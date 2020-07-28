/*#include <stdio.h>
#include <stdlib.h>

int contador = 0;
struct Fila {

	int capacidade;
	int *dados;
	int primeiro;
	int ultimo;
	int nItens;

};

void criarFila( struct Fila *f, int c ) {

	f->capacidade = c;
	f->dados = (int*) malloc (f->capacidade * sizeof(int));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0;

}

void inserir(struct Fila *f, int v) {

	if(f->ultimo == f->capacidade-1)
		f->ultimo = -1;

	f->ultimo++;
	f->dados[f->ultimo] = v; // incrementa ultimo e insere
	f->nItens++; // mais um item inserido

}


int main(){
    struct Fila umaFila;
    criarFila(&umaFila, 1001);
	int N, M, i, j, k;
	int vetor[1001];
	scanf("%i", &N);
	for(i=0;i<N;i++){
		scanf("%i",&M);
		for(j=0;j<M;j++){
			scanf("%i",&vetor[j]);
		}
		for(k=0;k<M+1;k++){
            inserir(&umaFila,vetor[k]);
        }

		int temp, a, b;
        for(a=1;a<M;a++){
            for(b=0;b<a;b++){
                if(vetor[a]>vetor[b]){
                    temp = vetor[a];
                    vetor[a]=vetor[b];
                    vetor[b]= temp;
                }
            }
        }
        struct Fila *f;

        int cont, z;

        for ( cont=0, z= f->primeiro; cont < f->nItens; cont++){

            if(f->dados[z++]==vetor[cont]){contador++;}

            if (z == f->capacidade)
			z=0;

        }
        criarFila(&umaFila, 51);
		printf("%i\n", contador);
        cont = 0;
	}
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>

int cont = 0;


typedef struct box {
     int conteudoAntes;
     struct box *prox;
     int tamanho;
     };
     struct box *primeiro, *ultimo;

     void vazia(){
         struct box *aux;
         aux = (struct box *) malloc(sizeof(struct box));
         primeiro = aux;
         ultimo = primeiro;
     }

     int insere_final(int x){
        struct box *aux;
        aux = (struct box *) malloc(sizeof(struct box));
        aux->conteudoAntes = x;
        ultimo->prox = aux;
        ultimo = ultimo->prox;
        ultimo->prox = NULL;
        //aux->tamanho = aux->tamanho+1;
     }
    /* void remover(int x){
       struct box *aux;
       struct box *sentinela;
       int i;
       for(i=0;i<x-1;i++){
            aux = primeiro->prox;
            sentinela = primeiro;
            sentinela->prox = aux->prox;
            free(aux);
        }
    }
    int ordernar(int x){

    }
    void imprime(){

    }

    int comparar(){

    }*/

int main(){
    vazia();
    int vetor[1001];
	int N, M, i, j, k;
	scanf("%i", &N);
	for(i=0;i<N;i++){
		scanf("%i",&M);
		for(j=0;j<M;j++){
			scanf("%i",&vetor[j]);
		}
		for(k=0;k<M;k++){
			insere_final(vetor[k]);
		}
		int temp, a, b;
        for(a=1;a<M;a++){
            for(b=0;b<a;b++){
                if(vetor[a]>vetor[b]){
                    temp = vetor[a];
                    vetor[a]=vetor[b];
                    vetor[b]= temp;
                }
            }
        }
        struct box *sentinela;
        sentinela= primeiro->prox;
        int z = 0;
        for(z=0;z<M;z++){
            if(sentinela->conteudoAntes == vetor[z]){
                cont++;
                sentinela = sentinela->prox;
            }
            else{
                sentinela = sentinela->prox;
            }
       }






		//ordernar(M);
		//comparar();
		vazia();
		printf("%i\n", cont);
        cont = 0;
		//imprime();
		/*struct box *auxiliar;
        auxiliar = primeiro->prox;
        int x = 0;
        for(x=0;x<M;x++){
            printf("Antes:%i\nDepois:%i\n", auxiliar->conteudoAntes, vetor[x]);
            auxiliar = auxiliar->prox;
        }*/

	}

    return 0;
}
