#include <iostream>
#include <stdio.h>
#include <NTL/ZZ.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <future>
#include "src/func.cpp"

using namespace std;
using namespace NTL;

static string alfa = "0123456789,abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ-.()";

class rsa{
private:
	ZZ p, q ,c_pr;
	vector<ZZ> _p, _q, P, dpq;
	FILE *t_c, *t_dc;
public:
	vector<ZZ> criba;
	ZZ c_pu, N;
	rsa(long int t){
		this->p = RandomPrime_ZZ(t);
		this->q = RandomPrime_ZZ(t);
		this->c_pu = RandomPrime_ZZ(t);

		ZZ ps = (p-1)*(q-1);
		this->c_pr = euc_ext(c_pu, ps);
		this->N = p*q;

		_p.push_back(p);
		_p.push_back(q);

		_q.push_back(euc_ext(modulo(q,p),p));
		_q.push_back(euc_ext(modulo(p,q),q));
		
		P.push_back(q);
		P.push_back(p);

		dpq.push_back(modulo(c_pr, p-1));
		dpq.push_back(modulo(c_pr, q-1));
	}	


	void info(){
		cout << endl << "c_pu:  " << this->c_pu << endl;
		cout << "N:  " << this->N << endl;
	}	

	string cifrar(string msg, ZZ c_pu, ZZ N){
		string tb = to_string(alfa.size());	// bloques de 2 [digitos de alpha]
		int bq1 = tb.size(), p, c;
		ZZ bq3 = ZZ(zz_to_str(N).size());

		string sms = "", msgc = "";
		string temp, aux, str, auxt;

		for(unsigned i=0; i<msg.size(); i++){		
			c = msg[i];

			p = alfa.find(c);
			aux = to_string(p);
			if(aux.size() != unsigned(bq1)) aux = con_zero(aux, ZZ(bq1));

			temp = sms;
			sms += aux;
			ZZ num(INIT_VAL, sms.c_str());
			
			if(i == msg.size()-1){
				ZZ num_(INIT_VAL, temp.c_str());
				str = zz_to_str(exp_mod(num_, c_pu, N));
				if(str.size() != bq3) auxt = con_zero(str, bq3);
				msgc += auxt;
			}
			else if(num>N){
				ZZ nu(INIT_VAL, temp.c_str());
				str = zz_to_str(exp_mod(nu, c_pu, N));
				if(str.size() != bq3) auxt = con_zero(str, bq3);
				msgc += auxt;
				sms = aux;
			}
		}
		return msgc;
	}

	string descifrar(string msgc){
		ZZ bq1 = ZZ((zz_to_str(ZZ(alfa.size()))).size());
		ZZ bq3 = ZZ(zz_to_str(this->N).size());
		ZZ temp = ZZ(0);

		string num = "", sms = "", str;
		unsigned i;
		for(i=0; msgc[i]!='\0'; i++){
			temp++;
			num += msgc[i];
			if(temp == bq3){
				ZZ aux(INIT_VAL, num.c_str());
				str = zz_to_str(resto_chino_rsa(aux));
				sms += str;
				num = "";
				temp = ZZ(0);
			}
		}

		string ind = "", msg = "";
		for(i=0; sms[i]!='\0'; i++){
			ind += sms[i];
			if(ind.size() == bq1){
				int b = atoi(ind.c_str());
				msg += alfa[b];
				ind = "";
			}
		}

		return msg;
	}

	ZZ resto_chino_rsa(ZZ w){
		ZZ x = ZZ(0), a, ad;
		for(long int j=0;j<(int)_p.size();j++){
			ad = modulo(w, _p[j]); //saca modulo de t_cifr con p o q respe
			a = exp_mod(ad, dpq[j],_p[j]); //saca el a , para cada uno
			x+= a*P[j]*_q[j];
		}
		x = modulo(x, N);
		return x;
	}

	virtual ~rsa(){	};
};

int main(int argc, char const *argv[]){
	int r=100;
		
	rsa *rs = new rsa(r);
	string msgp, msgc, msgd;
	msgp = "Hello Percy, como estas, como te fue en este dia";
	rs->info();
	msgc = rs->cifrar(msgp,rs->c_pu,rs->N);
	msgd = rs->descifrar(msgc);

	std::cout << msgp << "\n";
	std::cout << msgc << "\n";
	std::cout << msgd << "\n";
	delete rs;
	return 0;
}

//cifrado y descifrado