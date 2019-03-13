#ifndef _CHECK_H_
#define _CHECK_H_

#include <fstream>
#include <regex> 
#include "func.h"

class ccheck{	
public:
	ccheck(){	}

	bool password(std::string _pass, std::string _user, unsigned n,
		std::string _file, std::string _dict, std::string _clas){		
		if(!length(_pass))	return false;
		if(!alternate(_pass))	return false;
		if(!repeat(_pass, _file))	return false;
		if(!repeat(_pass, _clas))	return false;
		if(!match(_pass, _dict))	return false;
		if(ncharacter(_pass, n))	return false;
		if(same(_pass, _user))	return false;

		return true;
	}

	bool same(std::string _pass, std::string _user){
		if(_pass == _user){
			std::cout << "    [fail 6]\tDebe ser diferente del usuario\n";
			return true;
		}
		return false;
	}

	bool length(std::string _pass){
		if(_pass.size()<8 or _pass.size()>28){
			std::cout << "    [fail 1]\tTamaño entre [8,28]\n";
			return false;
		}
		return true;
	}

	bool alternate(std::string _pass){
		bool cap = false, low = false;
		bool num = false, spe = false;
		for(unsigned i=0; i<_pass.size(); i++){
			if(_pass[i]>=65 and _pass[i]<=90)	cap = true;
			if(_pass[i]>=97 and _pass[i]<=122)	low = true;
			if(_pass[i]>=48 and _pass[i]<=57)	num = true;
			if((_pass[i]>=33 and _pass[i]<=47) or
				(_pass[i]>=91 and _pass[i]<=96))	spe = true;

			if(_pass[i] == ' '){
				std::cout << "    [fail 4]\t Sin espacios\n";		
			}
		}

		if(cap and low and num and spe)	return true;
		std::cout << "    [fail 2]\t Mayuscula - Minuscula - Número - Especial\n";
		return false;
	}

	bool repeat(std::string _pass, std::string _file){
		std::ifstream file(_file);

		if(!file.is_open()){
			std::cout << "    [fail 3]\tBD Inactiva\n";
			return false;
		}

		std::string tmp;
		while(file.good()){		
			getline(file, tmp, ' ');
			if(tmp == _pass){
				std::cout << "    [fail 3]\tNo se puede reutilizar\n";
				std::cout << "    [fail 3]\tContraseña Clásica\n";
				return false;
			}
		}

		return true;
	}

	bool match(std::string _pass, std::string _file){
		std::ifstream file(_file);

		if(!file.is_open()){
			std::cout << "    [fail 5]\tDiccionario Inactiva\n";
			return false;
		}

		std::string tmp;
		while(file.good()){
			getline(file, tmp, ' ');

			if(word_inside(tmp, _pass)){
				std::cout << "    [fail 5]\tNo palabras del diccionario\n";
				return false;
			}			
		}
		return true;
	}

	bool ncharacter(std::string _pass, unsigned n){
		std::string tmp, word;
		for(int i=0; i<(int)(_pass.size()-n); i++){
			word = nc(_pass[i], n);
			tmp = _pass.substr(i,n);
			if(tmp == word){
				std::cout << "    [fail 7]\tNo tener " << n << " caracteres consecutivos\n";
				return true;
			}
		}

		return false;
	}	

	~ccheck(){}
};

#endif