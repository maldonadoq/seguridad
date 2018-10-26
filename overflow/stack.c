#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int bof(char *str){
    char buffer[24];    // less

    strcpy(buffer, str);
    return 1;
}

int main(int argc, char const *argv[]){
    int t = 517, i;
    char str[t], aux;
    
    FILE *badfile;
    badfile = fopen("badfile", "r");

    i = 0;
    while((aux=getc(badfile))!=EOF){
        str[i++] = aux;
        printf("%c", aux);        
    }

    fclose(badfile);    
    printf("\n");

    bof(str);

    printf("Ok\n");
    return 1;
}