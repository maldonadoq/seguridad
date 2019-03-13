#ifndef _FUNC_H_
#define _FUNC_H_

int modulo(int a,int n){
    int q = a/n;
    int r = a-(n*q);
    if(r<0) return r+n;
    return r;
}

bool word_inside(std::string word, std::string in){
	unsigned sz = word.size();
	std::string tmp;
	for(int i=0; i<(int)(in.size()-sz); i++){
		tmp = in.substr(i,sz);
		if(tmp == word)	return true;
	}

	return false;
}

std::string nc(char l, unsigned n){
	std::string tmp = "";
	for(unsigned i=0; i<n; i++)	tmp += l;
		
	return tmp;
}

#endif