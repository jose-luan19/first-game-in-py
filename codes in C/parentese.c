#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    struct Parentese{
        char parentese;
        struct Parentese *prox;
    };
    typedef struct Parentese *TPar;
    struct descrPilha {
        TPar *topo;
    };
    typedef struct descrPilha DPilha;


int main()
{
	DPilha	descritor;
	struct Parentese *aux, *aux2;
    char linha[1001];
    int N, d, i,esquerda, direita;
    while(scanf("%s",&linha) != EOF){
        esquerda = 0;
        direita = 0;
        for(d=0;d<strlen(linha);d++){
            if (linha[d]=='('){
                aux = (TPar *) malloc(sizeof(TPar));
                if(aux == NULL){break;}
                aux->parentese = linha[d];
                aux->prox = descritor.topo;
                descritor.topo = aux;
                esquerda++;
            }
            else if(linha[d] == ')'){
                    direita++;
				if(descritor.topo != NULL)
				{
					aux2 = descritor.topo;
					descritor.topo = aux2->prox;
					free(aux2);
					esquerda--;
                    direita--;
                }
            }
        }
        if(esquerda == 0 && direita == 0) printf("correct\n");
        else printf("incorrect\n");
    }
 return 0;
}



