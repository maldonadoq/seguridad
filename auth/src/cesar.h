#ifndef _CESAR_H_
#define _CESAR_H_

#include "func.h"

class ccesar{
private:
	int m_key, m_n;
	std::string m_alpha;
public:
	ccesar(int);
	std::string cifrar(std::string);
	std::string descifrar(std::string);
	~ccesar(){	}
};

ccesar::ccesar(int _key){
	m_alpha = "0123456789,abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ-.()[]!#$%&*+./^_}{";
	m_n = m_alpha.size();
	m_key = modulo(_key,m_n);
}

std::string ccesar::cifrar(std::string t_plano){
	int aux;
	std::string t_ci = "";
	for(unsigned i=0; i<t_plano.size(); i++){
		aux = modulo(m_alpha.find(t_plano[i])+m_key, m_n);
		t_ci = t_ci + m_alpha[aux];
	}
	return t_ci;
}

std::string ccesar::descifrar(std::string t_ci){
	int aux;
	std::string t_dsci = "";
	for(unsigned i=0; i<t_ci.size(); i++){
		aux = modulo(m_alpha.find(t_ci[i])-m_key, m_n);
		t_dsci = t_dsci + m_alpha[aux];
	}
	return t_dsci;
}

#endif