#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float x,y,z,w,V;
	float S,x2,y2,z2,w2;
	x=0;
	y=0;
	z=0;
	w=0;
	printf("qual o numero do seu candidato: ");
	scanf("%f", &V);
	while (V>0){
		if(V>4){
			printf("\nesse voto nao e valido\n");
		}
		
	     if(V==1){
			x++;
			printf("voto valido\n");
		}
		else if (V==2){
			y++;
			printf("voto valido\n");
		}
		else if(V==3){
			z++;
			printf("voto valido\n");
		}
		else if(V==4){
			w++;
			printf("voto valido\n");	
		}
		scanf("%f",&V);
	}
	printf("\n\nResultado final da votacao: \n\n1:%.0f \n\n2:%.0f \n\n3:%.0f \n\n4:%.0f" ,x,y,z,w);
	S=x+y+z+w;
	x2=(x*100)/S;
	y2=(y*100)/S;
	z2=(z*100)/S;
	w2=(w*100)/S;
	printf("\n\n1:%.0f  \n\n2:%.0f \n\n3:%.0f \n\n4:%.0f ",x2,y2,z2,w2);
	system("pause");
	
	
	
	
	return 0;
}
