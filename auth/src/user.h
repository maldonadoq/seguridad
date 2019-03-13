#ifndef _USER_H_
#define _USER_H_

class cuser{
private:
	std::string m_user;
	std::string m_pass;
public:
	cuser(std::string _user, std::string _pass){
		this->m_user = _user;
		this->m_pass = _pass;
	}

	std::string get_user(){
		return this->m_user;
	}

	std::string get_pass(){
		return this->m_pass;
	}

	void set_pass(std::string _pass){
		this->m_pass = _pass;
	}

	void set_user(std::string _user){
		this->m_user = _user;
	}
};

#endif