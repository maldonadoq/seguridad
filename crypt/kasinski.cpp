#include <iostream>

struct sdata{
	std::string data;
	unsigned count;
} sdata;

unsigned nrepeat(std::string tmp, std::string in){
	unsigned t = in.size();
	unsigned tmax = 0;
	std::string r;
	for(unsigned i=0; i<tmp.size()-t; i++){
		r = tmp.substr(i,t);
		if(in == r)
			tmax++;
	}
	return tmax;
}

int main(int argc, char const *argv[]){

	std::string tmp = "WSKEHJTZCBDOJEOSTIAKMCZDVUOEUUKIJTLEAZNMGRDAAACFSPFIETLJVVNJAOEHBEAEATACIOZGFKOMJETELKTRSAJAUUJUIFNLKALTVEAKIJSSGAYSQLESGSYAIDAETLKDVOAJOJIKAODAZVIJTPFTFSKWLZNNDEJPBWDRNKASWRBLAIDLDCFNAWNZDVKOSRLDOJPYGDLCAGSCOZKEIVPUIFSFDAJTLUNFLVYIRSKWMZCYGSFFAHUVSAGQLELKTVAYLITUSGSVHHLRRDBUIUOJGNKRHVUTCPGNRUAGMRTPUAVSWGSZBSWQLEJGNKEUYAVRYGRVSKWVFCHTUCAYAOJIULAOIZGGIATSTZCH";
	unsigned smax = 5;

	unsigned i,j;

	std::string r;

	//std::vector<std::vector<pair<std::string, int> > > 

	for(i=1; i<smax; i++){
		for(j=0; j<tmp.size()-i; j++){
			r = tmp.substr(j,i);			
			std::cout << r << ":" << nrepeat(tmp, r) << "\t";
		}
		std::cout << "\n";
	}
	
	return 0;
}