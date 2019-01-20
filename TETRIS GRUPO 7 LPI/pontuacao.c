#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "inicio.h"


typedef struct {//Struct q vai salvar o nome e os pontos
	char nome[20];
	int pontos;
}rank;
rank ranking[10];
FILE *rank_ar;

void Ranking()//Mostra o ranking
{

	int i;
	rank_ar = fopen("arquivoRanking", "rb");
	fread(ranking, sizeof(rank), 10, rank_ar);
	for (i = 0; i<10; i++)
    printf("\tnome :%s         pontuacao: %d\n", ranking[i].nome, ranking[i].pontos);
	fclose(rank_ar);
	system("pause");
	system("cls");
    inicio();
}

void verificar(char *name, int score)// função que armazena, se possivel, a pontuação do usuario no vetor de pontuações
{
	int aux, i;
	char auxs[10];
	for (i = 0; i<10; i++)
	{
		if (ranking[i].pontos < score)
		{
			aux = ranking[i].pontos;
			strcpy(auxs, ranking[i].nome);
			ranking[i].pontos= score;
			strcpy(ranking[i].nome, name);
			score = aux;
			strcpy(name, auxs);

		}
	}
}
void dados(char *nome, int pontos)//SAlva os dados no arquivo
{

	rank_ar = fopen("arquivoRanking", "rb");
	if (rank_ar == NULL) {
		rank_ar = fopen("arquivoRanking", "wb");
	}
	else {
		fread(ranking, sizeof(rank), 10, rank_ar);
		verificar(nome, pontos);

	}
	fclose(rank_ar);
	rank_ar = fopen("arquivoRanking", "wb");
	fwrite(ranking, sizeof(rank), 10, rank_ar);
	fclose(rank_ar);

}
void dadosjogador(int pontos)// função que armazena no arquivo a pontuação
{
	char nome[10];
	printf("digite seu nome:");
	gets(nome);
	dados(nome, pontos);
}



int pontuacao(int ponto)//Essa função, quando executada, vai pegar o nome do jogador e vai computar sua pontuação no highscore
{
	int x;
	dadosjogador(ponto);
	Ranking();
	return 0;
}

