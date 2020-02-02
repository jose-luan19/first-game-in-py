#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, k = 0, j=0, matriz[50][50] ;
    for(i=0;i<10;i++){
        printf("| ");
    for(k=0;k<10;k++){
        printf("%d",matriz[i][k] );
        }
    printf(" |");
        printf("\n");
}

    return 0;
}
