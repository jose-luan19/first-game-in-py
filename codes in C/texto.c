#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *p;
    char nomes[100], telefones[50];
    p = fopen ("lista.txt", "r+");
    if(p == NULL){
        printf("Erro ao abrir o arquivo");
        return 1;
    }
    char nomes[100];
    while(fgets(nomes, 100, p )!= NULL){
        printf("%s");
    }

    fclose(p);



    return 0;
}
