#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

extern alt;
extern larg;
extern x;
extern y;
extern tabuleiro[25][18];
extern ponto;


void apagar(int linha)//Se essa função for chamada, vai apagar uma linha no tabuleiro, e a linha anterior vai assumir o lugar da linha que acabou de ser apagada. Ela recebo como argumento um valor que represanta a linha que vai ser apagada.
{
    for(x = linha; x > 1; --x)
    {
        for(y = 1; y < 17; ++y)
        {
            tabuleiro[x][y] = tabuleiro[x-1][y];

        }
    }
    ponto=ponto+10;//Caso isso aconteça, o jogador ganha 10 pontos.
}

void completarLinha()//Essa função vai verificar se uma linha da matriz tabuleiro foi preenchida com peças, caso for, ela executará uma função que apaga essa linha.
{
    int linha, col;
    for(linha = 0; linha < 24; ++linha)//Esse for só vai até a linha 24, pois a linha seguinte é o chão. E o chão não pode ser apagado pela função apagar
    {
        int contarCorpo = 0;
        for(col = 1; col < 17; ++col)//O mesmo serve para as paredes que ficam na direita e esquerda, elas não precisam ser apagadas.
        {
            if(tabuleiro[linha][col] == 178)
                ++contarCorpo;
            if(contarCorpo == 16)
            {
                apagar(linha);
            }
        }
    }
}
