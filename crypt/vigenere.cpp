#include <iostream>
#include <stdio.h>
#include <string>
#include "src/func.h"

using namespace std;

class vigenere{
private:
	string alfa, clave;
	int mod;
public:
	vigenere(string);
	string cifrado(string);
	string descifrado(string);
	~vigenere(){	}
};

vigenere::vigenere(string clave){
	this->clave = clave;
	// this->alfa = "abcdefghijklmnopqrstuvwxyz ";
	this->alfa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	this->mod = alfa.size();
}

string vigenere::cifrado(string t_pl){
	string t_ci = "";
	int aux = 0;
	for(int i=0, j=0;i<t_pl.size();i++, j++){
		if(j>=clave.size()) j=0;
		aux = modulo((alfa.find(t_pl[i]) + alfa.find(clave[j])),mod);
		t_ci += alfa[aux];
	}
	return t_ci;
}

string vigenere::descifrado(string t_ci){
	string t_dsci = "";
	int aux=0;
	for(int i=0,j=0;i<t_ci.size();i++,j++){
		if(j>=clave.size()) j=0;
		aux = modulo(alfa.find(t_ci[i]) - alfa.find(clave[j]), mod);
		t_dsci += alfa[aux];
	}
	return t_dsci;
}

int main(int argc, char const *argv[]){
	string clave="", t_pl="", t_ci, t_dsci;
	char ad;
	cout << "clave:  ";
	for(;(ad=getchar())!='\n';)	clave += ad;
	cout << "texto_plano:  ";
	for(;(ad=getchar())!='\n';)	t_pl += ad;
		
	vigenere emisor(clave);
	vigenere receptor(clave);

	t_ci = emisor.cifrado(t_pl);
	t_dsci = receptor.descifrado(t_ci);

	cout << t_ci << endl;
	cout << t_dsci << endl;

	return 0;
}
// WSKEHJTZCBDOJEOSTIAKMCZDVUOEUUKIJTLEAZNMGRDAAACFSPFIETLJVVNJAOEHBEAEATACIOZGFKOMJETELKTRSAJAUUJUIFNLKALTVEAKIJSSGAYSQLESGSYAIDAETLKDVOAJOJIKAODAZVIJTPFTFSKWLZNNDEJPBWDRNKASWRBLAIDLDCFNAWNZDVKOSRLDOJPYGDLCAGSCOZKEIVPUIFSFDAJTLUNFLVYIRSKWMZCYGSFFAHUVSAGQLELKTVAYLITUSGSVHHLRRDBUIUOJGNKRHVUTCPGNRUAGMRTPUAVSWGSZBSWQLEJGNKEUYAVRYGRVSKWVFCHTUCAYAOJIULAOIZGGIATSTZCH
// ESTEARTICULOSEHATRADUCIDOCONUNSISTEMAINFORMATICOSININTERVENCIONHUMANAMICROSOFTOFRECEESTASTRADUCCIONESAUTOMATICASPARAQUELOSHABLANTESDEOTROSIDIOMASDISTINTOSDELINGLESPUEDANDISFRUTARDELCONTENIDOSOBRELOSPRODUCTOSLOSSERVICIOSYLASTECNOLOGIASDEMICROSOFTPUESTOQUEESTEARTICULOSEHATRADUCIDOCONTRADUCCIONAUTOMATICAESPOSIBLEQUECONTENGAERRORESDEVOCABULARIOSINTAXISOGRAMATICA