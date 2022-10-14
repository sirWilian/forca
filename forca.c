#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define TAM 50

char *sorteiaPalavra(char **dicionario, int contaPalavra){
	return dicionario[rand() % (contaPalavra - 1)];
}

int getPosicao(char *string, char letra, int inicio){
	for (int i = inicio; i < strlen(string); i++){
		if (string[i] == letra)
			return i;
	}
	return -1;
}

char *insere(char *string, int posicao, char letra){
	string[posicao] = letra;
	return string;
}

int main(int argc, char **argv){
	FILE *arq;
	char **dicionario;
	char *string, *forca, entrada;
	int tentativas, contadorPalavras, encerra, posicao;
	tentativas = encerra = posicao = 0;
	srand(time(NULL));

	if (!(arq = fopen(argv[1], "r"))){
		fprintf(stderr, "erro ao abrir o arquivo\n");
		exit(1);
	}
	if (!(string = malloc(sizeof(char) * TAM))){
		fprintf(stderr, "erro ao alocar espaco para a string\n");
		exit(1);
	}
	if (!(forca = malloc(sizeof(char) * TAM))){
		fprintf(stderr, "erro ao alocar espaco para a forca\n");
		exit(1);
	}
	if (!(dicionario = malloc(sizeof(char *)))){
		fprintf(stderr, "erro ao alocar primeira string\n");
		exit(1);
	}

	fgets(string, TAM, arq);
	dicionario[0] = malloc(sizeof(char) * TAM);
	strcpy(dicionario[0], string);
	contadorPalavras = 1;

	/* cria dicionario */
	while (!feof(arq)){
		fgets(string, TAM, arq);
		contadorPalavras++;
		if (!(dicionario = realloc(dicionario, sizeof(char *) * contadorPalavras))){
			fprintf(stderr, "erro ao realocar dicionario\n");
			exit(1);
		}
		dicionario[contadorPalavras - 1] = malloc(sizeof(char) * TAM);
		strcpy(dicionario[contadorPalavras - 1], string);
	}

	strcpy(string, sorteiaPalavra(dicionario, contadorPalavras));

	strcpy(forca, string);

	for (int i = 0; i < strlen(string); i++)
		forca[i] = 95;

	/* algoritmo da forca */
	while (!encerra){
		printf("\npalavra até agora: \n");
		for (int i = 0; i < strlen(string) - 1; i++)
			printf("%c ", forca[i]);
		printf("\n");
		printf("entre com uma letra: \n");

		entrada = getchar();
		tentativas++;

		/* encerra quando 0 for inserido */
		if (entrada == 30)
			encerra++;
		
		for(int i = 0; i < strlen(string); i++){
			posicao = getPosicao(string, entrada, i);
			if(posicao != -1)
				insere(forca, posicao, entrada);
		}

		if(!(strcmp(string, forca))){
			printf("\nparabéns!\n");
			printf("a palavra era %s\n", string);
			encerra++;
		}
	}

	printf("numero de tentativas: %.0f\n", ceil(tentativas/2 + 1));

	/* encerra */
	for (int i = 0; i < contadorPalavras; i++)
		free(dicionario[i]);
	free(string);
	free(forca);
	free(dicionario);
	fclose(arq);
}
