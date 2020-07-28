#include <stdlib.h>

struct elemento{
    int valor;
    struct elemento *prox;
};

struct fila{
    struct elemento *inicio;
    struct elemento *fim;
    int qtd;
};

typedef struct elemento Elem;

typedef struct fila Fila;

Fila* cria_Fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->fim = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;

    }
    return fi;
}

int insere_Fila(Fila* fi, int x){
    if(fi == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->valor = x;
    no->prox = NULL;
    if(fi->fim == NULL)//fila vazia
        fi->inicio = no;
    else
        fi->fim->prox = no;
    fi->fim = no;
    fi->qtd++;
    return 1;
}

int remove_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)//fila ficou vazia
        fi->fim = NULL;
    free(no);
    fi->qtd--;
    return 1;
}

void imprime_Fila(Fila* fi){
    if(fi == NULL)
        return;
    Elem* no = fi->inicio;
    while(no != NULL){
        printf("Valor: %d\n",no->valor);
        no = no->prox;
    }
}

int main(void){
    Fila* fi = cria_Fila();

    int res = 0;
    int i;

    do{

        scanf("%i", &res);

        if (res != 0 && res > 1){
            for (i = 1; i <= res; i++){
                insere_Fila(fi, i);
            }

            int aux;

            printf("Discarded cards: ");

            while(fi->inicio->prox != NULL){
                if (fi->qtd < res){
                    printf(", ");
                }
                printf("%i", fi->inicio->valor);
                remove_Fila(fi);
                aux = fi->inicio->valor;
                remove_Fila(fi);
                insere_Fila(fi, aux);
            }

            printf("\n");

            int sobra = fi->inicio->valor;

            printf("Remaining card: %i\n", sobra);

            free(fi);
            Fila* fi = cria_Fila();
        }
    }while(res != 0);

}
