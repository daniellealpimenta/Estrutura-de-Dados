#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[50];
	char curso[50];
	char telefone[20];
	float nota1, nota2;
} Dados;

void leitura_arquivo(){
	
	FILE *arquivo;
	FILE *arquivo2;
	
	float media = 0;
	
	arquivo = fopen("DadosEntrada.csv", "r");
	arquivo2 = fopen("SituacaoFinal.csv", "w");
	
	Dados info;
	
	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		exit(1);
	} 
	
	fscanf(arquivo, "%*[^\n]\n");
	
	while(fscanf(arquivo, "%49[^,],%19[^,],%49[^,],%f,%f", info.nome, info.telefone, info.curso, &info.nota1, &info.nota2) != EOF){	
	
	media = (info.nota1 + info.nota2) / 2;
	
	fprintf(arquivo2, "%s, %.2f, ", info.nome, media);
	
	if (media >= 7.0){
	
    	fprintf(arquivo2, "APROVADO\n");
    	
	}
	else if (media < 7.0){

    	fprintf(arquivo2, "REPROVADO\n");	

	}
	
	fscanf(arquivo, "%*c");
	
	}
	
	fclose(arquivo);
	fclose(arquivo2);
	
};

int main(){
	
	leitura_arquivo();

	return 0;

};
