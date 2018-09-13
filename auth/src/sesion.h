#ifndef _SESION_H_
#define _SESION_H_

#include "user.h"
#include "cesar.h"
#include "check.h"
#include <vector>

static std::vector<cuser *> nuser;

cuser * find_user(std::string user){
	cuser *tuser;
	for(unsigned i=0; i<nuser.size(); i++){
		if(nuser[i]->get_user() == user){
			tuser = nuser[i];
			return tuser;
		}
	}
	return NULL;
}

class csesion{
private:
	ccheck *m_ch;
	unsigned m_n, m_key, m_in;
	ccesar *m_enc;
public:
	csesion(unsigned _n, int _key, unsigned _in){
		this->m_ch = new ccheck();
		this->m_n = _n;
		this->m_key = _key;
		this->m_in = _in;
		this->m_enc = new ccesar(m_key);
	}

	void menu(){
		bool t = true;
		unsigned id;
		while(t){
			std::cout << "[1] Registarse\n";
			std::cout << "[2] Iniciar Sesión\n";
			std::cout << "[3] Cambiar Password\n";
			std::cout << "[4] Salir\n";
			std::cout << "[x] ";
			std::cin >> id;

			switch(id){
				case 1:				
					this->signup();
					std::cout << "\n";
					break;
				case 2:
					this->signin();
					std::cout << "\n";
					break;
				case 3:
					this->change_password();
					std::cout << "\n";
					break;
				case 4:
					t = false;
					break;
				default:
		        	break;
			}
		}	
	}

	void signup(){
		std::string user, password;

		std::cout << "  User: "; std::cin >> user;
		std::cout << "  Password: "; std::cin >> password;
		//user = "percy.maldonado";
		//password = "pass1woAr3d]";

		if(this->m_ch->password(password, user, this->m_n, "test/file.csv", "test/dict.csv", "test/classic.csv")){
			std::cout << "    Check Pass\n";
			nuser.push_back(new cuser(user, m_enc->cifrar(password)));
		}
		else
			std::cout << "    Check Fail\n";
	}

	void signin(){
		std::string user, password;

		std::cout << "  User: "; std::cin >> user;		

		unsigned n = 0;		

		cuser *tuser = find_user(user);

		if(tuser != NULL){
			while(n<this->m_in){
				std::cout << "  Password: "; std::cin >> password;

				if(password == m_enc->descifrar(tuser->get_pass())){
					std::cout << "    Iniciando Sesión\n    Ok\n";
					return;
				}
				n++;
			}
			std::cout << "    Muchos Intentos\n";
		}
		else	std::cout << "  No existe el usuario\n";
	}

	void change_password(){
		std::string user, password;

		std::cout << "  User: "; std::cin >> user;		

		cuser* tuser = find_user(user);

		if(tuser != NULL){
			std::cout << "  Password: "; std::cin >> password;

			if(password == m_enc->descifrar(tuser->get_pass())){
				std::cout << "    New Password: "; std::cin >> password;
				tuser->set_pass(m_enc->cifrar(password));
				std::cout << "      Cambiando Contraseña\n      Ok\n";
			}
			else{
				std::cout << "    Contraseña Distinta\n";
			}
		}		
	}

	~csesion(){	}
};

#endif