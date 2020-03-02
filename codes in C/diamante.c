#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{
    int i, j, N = 0, diamante;
    char V[1010];
    scanf("%i", &N);
    while (N--){
        scanf("%s", V);
        diamante = 0;
        for (i = 0; i < strlen(V); i++){
            if (V[i] == '\0')
                break;
            if (V[i] == '<'){
                for (j = i; j< strlen(V); j++){
                    if (V[j] == '>'){
                        diamante++;
                        V[j] = '0';
                        break;
                    }
                }
            }
        }
        printf("%d\n", diamante);
    }
    return 0;
}
