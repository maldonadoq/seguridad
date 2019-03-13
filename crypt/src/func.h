#ifndef _FUNC_H_
#define _FUNC_H_

int modulo(int a,int n){
    int q = a/n;
    int r = a-(n*q);
    if(r<0) return r+n;
    return r;
}

#endif