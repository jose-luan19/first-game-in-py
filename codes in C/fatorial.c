#include <stdio.h>
#include <stdlib.h>

int fat (int n) {
//Função que calcula, recursivamente, o fatorial de n.
if (n <= 1){
 return 1; }              
   else{
   
  
   return 	n * fat (n-1) ;
   }
   
	}
int main () {

int n;                        
printf("Informe o numero que deseja obter o fatorial: ");
scanf("%d",&n);
fat (n);
 printf("o fatorial do numero %d e %d", n, fat(n));
return 0;}
	
	
	
