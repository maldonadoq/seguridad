#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "src/sesion.h"

int main(int argc, char const *argv[]){
	csesion *tmp = new csesion(3,6,2);

	tmp->menu();

	delete tmp;
	return 0;
}