#include <stdlib.h>
#include "inicio.h"

int alt;//Altura de peça que o jogador pode mover
int larg = 5;//Posição da peça que a peça poderá na esquerda ou para a direita
int tabuleiro[25][18] = {0};//Matriz que vai formar o tabuleiro do jogo
int peca[4][4] = {0};//Matriz que vai formar a peça jogável
int CORPO = 2;//Vai definir o valor a ser preenchido na matriz peça
int x, y, i, j;//Essas variáveis serão usadas em diversos loops do tipo for durante a execução do programa
int valor;//Esse valor será aleatório e vai ser usado para definir a peça jogável
extern ponto;//Essa variável será usada para contar os pontos do jogador

inicio()//Função que vai iniciar o jogo, ela será chamada mais de uma vez durante a execução do programa caso o jogo for reiniciado
{
    limparPeca();//Retira quaisquer valores da matriz peca
    alt = 0;//Define a altura da peca como sendo 0
    srand(time(NULL));
    valor  = 1 + rand()%7;//Sorteia uma peca com valor de 1 a 7(pois sao 7 peças)
    escolherPeca();//Escolhe uma peça pra ser usada no jogo
    menu();//Mostra o menu do jogo
    ponto=0;//Zera os pontos do jogador
}
