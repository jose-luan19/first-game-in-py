#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i, n;
    float notaMelhor, mediaFinal = 0, porcenFracasso = 0;
    printf("Programa para a análise de avaliações de alunos.\n\nInforme o número de alunos: ");
    scanf("%d", &n);
    float matriz[n][4];
    for(i = 0; i < n; i++)
    {
        printf("\nInforme o número de matrícula: ");
        scanf("%f", &matriz[i][0]);
        printf("Informe a média das provas: ");
        scanf("%f", &matriz[i][1]);
        printf("Informe a média dos trabalhos: ");
        scanf("%f", &matriz[i][2]);
        matriz[i][3] = (matriz[i][1] + matriz[i][2]) / 2;
        if(i == 0){
            notaMelhor = matriz[0][3];
        } else if(matriz[i][3] > notaMelhor){
            notaMelhor = matriz[i][3];
        }
    }
    for(i = 0; i < n; i++)
    {
        if(matriz[i][3] == notaMelhor)
        {
            printf("\nO aluno com a matrícula %.0f atingiu a maior nota final.\n", matriz[i][0]);
        }
    }
    for(i = 0; i < n; i++)
    {
        mediaFinal += matriz[i][3] / n;
    }
    printf("\nA média aritmética final dos alunos foi %.1f.\n", mediaFinal);
    for(i = 0; i < n; i++)
    {
        if(matriz[i][3] < 6.0)
        {
            porcenFracasso += 1.0f / n * 100;
        }
    }
    printf("\n%.2f%% dos alunos ficaram abaixo da média e %.2f%% ficaram acima da média\n", porcenFracasso, 100 - porcenFracasso);
    return 0;
}
