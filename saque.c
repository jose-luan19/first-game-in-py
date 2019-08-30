#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int x,r1,r2,n1,n2,n3,total;
	printf("Informe o valor do saque: ");
	scanf("%d",&x);
	while(x%5 !=0 && x%10!=0 && x%50!=0){
		printf("No momento so temos cedulas para valores multiplos de 5. Digite novamente o valor:");
		scanf("%d",&x);
	}
	r1= x% 50;
	n1=(x-r1)/50;
	r2=r1%10;
	n2=(r1-r2)/10;
	n3= r2/5;
	printf("Quantidade de cedulas de 50 e: %d\n ", n1);
	printf("Quantidade de cedulas de 10 e: %d\n ", n2);
	printf("Quantidade de cedulas de 5 e: %d\n", n3);
	total= n1+n2+n3;
	printf("\nQuantidade minimia de cedulas para o saque de %d e %d\n\n", x, total);
	system("pause");
	return 0;
}
