#include <stdio.h>
#include <stdlib.h>

//#define F 1001

int fila[1001];
int Afila[1001];
static int p, u;
void criafila (void) {
   p = u = 0;
}

void colocanafila (int y) {
   fila[u++] = y;
   Afila[u++] = y;
   //cont++;
}

//int tiradafila (void) {
//   return fila[p++];
//   //cont--;
//} 
//
//int filavazia (void) {
//   return p >= u;
//}
//
//int filacheia (void) {
//   return u > F;
//}
int ordernar(int tamVetor){
	int i,j,temp;
	for (i = 1; i < tamVetor; i++) {
    	for ( j = 0; j < i; j++) {
    		
        	if (fila[i] > fila[j]) {
	            temp = fila[i];
	            fila[i] = fila[j];
	            fila[j] = temp;
        	}
		}
	}
}


int main(int argc, char *argv[]) {
	int vetor[1001];
	int N, M, i, j, k, z;
	scanf("%i", &N);
	for(i=0;i<N;i++){
		criafila();
		scanf("%i",&M);
		for(j=0;j<M;j++){
			scanf("%i",&vetor[j]);
		}
	
		for(k=0;k<M;k++){
			colocanafila(vetor[k]);
			//printf("%i\n",fila[k]);
		
		}
		ordernar(M);
		int tamanho = 0;
		for(z=0;z<M;z++){
			if(Afila[z]==fila[z]){
				tamanho++;
			}	
		}
		 
		printf("%i\n", tamanho);
	}
	return 0;
}
