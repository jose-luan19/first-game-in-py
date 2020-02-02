#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale (LC_ALL, "portuguese");
	int codigo, data, empresa, ano, idade, tempo;
	
	printf("Informe o codigo do funcionario ");
	scanf("%d", &codigo);
	printf("\nInforme o ano de nascimento do funcionario ");
	scanf("%d", &data);
	printf("\nInforme o ano atual ");
	scanf("%d", &ano);
	printf("\nInforme a data de entrada do funcionario na empresa ");
	scanf("%d", &empresa);
	idade = ano - data;
	tempo = ano - empresa;
	if(idade>=65){
		printf("\nFuncionario %d Requerer aposentadoria", codigo);
	}else if(idade>=60 && tempo>=25){
		printf("\nFuncionario %d Requerer aposentadoria", codigo);
	}else if(tempo>=30){
		printf("\nFuncionario %d Requerer aposentadoria", codigo);
	}else{
		printf("\nFuncionario %d Não Requerer aposentadoria", codigo);
	}
	
	
	return 0;
}
