#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
    typedef struct box {
     char conteudo[2];
     struct box *prox;
     };
     struct box *primeiro, *ultimo;

     void vazia(){
         struct box *aux;
         aux = (struct box *) malloc(sizeof(struct box));
         primeiro = aux;
         ultimo = primeiro;
     }

     char insere_final(char x[2]){
        struct box *aux;
        aux = (struct box *) malloc(sizeof(struct box));
        strcpy( aux->conteudo, x);
        ultimo->prox = aux;
        ultimo = ultimo->prox;
        aux->prox = NULL;
     }
     /* //Falta fazer com que insira no inicio e conecte com o prox item
    char insere_inicio(char x[2]){
        struct box *novo, *aux;
        novo = (struct box *) malloc(sizeof(struct box));
        aux = (struct box *) malloc(sizeof(struct box));
        strcpy( novo->conteudo, x);
        novo->prox = NULL;
        novo->prox = aux;


     }*/

     /* //Falta fazer com que insira ap�s a letra pedida
    char insere_meio(char x[2], char y[2]){
        struct box *aux;
        struct box *novo;
        novo = (struct box*) malloc(sizeof(struct box));
        aux = (struct box *) malloc(sizeof(struct box));
        strcpy( aux->conteudo, x);
        primeiro->prox = aux;
        aux->prox = ultimo;
        ultimo->prox = NULL;
        while(aux!=NULL){
            if( strcmp(y,aux->conteudo)== 0){
                aux->prox = novo;
                novo = aux->conteudo;
                aux = NULL;
            }
            else{aux = aux->prox;}
       }
     }*/

    void imprime(){
        struct box *aux;
        aux = primeiro->prox;
        printf("Lista:\n");
        while(aux!= NULL){
            printf("%s \n", aux->conteudo);
            aux = aux->prox;
        }
    }
    //prot�tipo para fun��o remover
    char pesquisa(char x[2]){
       struct box *aux;
       int flag = 0;
       aux = primeiro->prox;
       while(aux!=NULL){
            if( strcmp(x,aux->conteudo)== 0){
                printf("\n ACHOU %s",x);
                flag = 1;
                aux=NULL;
            }
            else{aux = aux->prox;}
       }
       if(!flag){printf("\n'%s' nao se encontra nessa lista",x);}
    }
    char remover(char x[2]){
       struct box *aux;
       struct box *sentinela;
       int flag = 0;
       aux = primeiro->prox;
       sentinela = primeiro;
       while(aux!=NULL){
            if( strcmp(x,aux->conteudo)== 0){
                printf("\nRemoveu %s\n\n",x);
                sentinela->prox = aux->prox;
                flag = 1;
                free(aux);
                aux=NULL;
            }
            else{
                aux = aux->prox;
                sentinela = sentinela->prox;
            }
       }
       if(!flag){printf("\n'%s' nao se encontra nessa lista",x);}
    }

int main()
{
    char op = '2';
    char code[2], lugar[2];
    vazia();

    int opcao;
    printf("Digite 0: Sair do programa\nDigite 1: Inserir letra no inicio da lista\nDigite 2: Inserir letra no final da lista\nDigite 3: Inserir letra apos uma letra especifica\nDigite 4: Excluir letra da lista\n");
    while(1){
        scanf("%i",&opcao);
        if(opcao == 0){return 0;}
        system("cls");
        if(opcao == 1){
            printf("\n\nPreencha: ");
            scanf("%s",&code);
            //insere_inicio(code);
            imprime();
            system("pause");
        }
        if(opcao == 2){
            printf("\n\nPreencha com a letra: ");
            scanf("%s",&code);
            insere_final(code);
            imprime();
            system("pause");
        }
        if(opcao == 3){
           /*printf("Apos qual letra deve-se preencher: ");
            scanf("%s",&lugar);
            printf("\n\nPreencha: ");
            scanf("%s",&code);
            insere_meio(code,lugar);*/
            imprime();
            system("pause");
        }
        if(opcao == 4){
            printf("\nInforme um item para remover: ");
            scanf("%s",&code);
            remover(code);
            imprime();
            system("pause");
        }
        system("cls");
    printf("Digite 0: Sair do programa\nDigite 1: Inserir letra no inicio da lista\nDigite 2: Inserir letra no final da lista\nDigite 3: Inserir letra apos uma letra especifica\nDigite 4: Excluir letra da lista\n");    }



    return 0;
}
