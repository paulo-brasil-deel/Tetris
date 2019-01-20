#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

extern x;
extern y;
extern peca[4][4];
extern alt;
extern larg;
extern tabuleiro[25][18];
extern i;
extern j;
extern CORPO;

void imprimirNoTabuleiro()//Essa função, quando executada, vai fazer com o chão do tabuleiro aumente nas posições da peça, quando a mesma colidir, de maneira que agora a peça jogável vai empilhar no chão e virar o chão, para que a próxima peça jogável possa ser empilhada nela, já que as peças jogáveis apenas colidem no chão
{
    for( i = 0; i < 4; ++i)
    {
        for(j = 0; j < 4; ++j)
        {
            if(peca[i][j] == CORPO)
            {
                tabuleiro[alt+i-1][larg + j] = 178;
            }
        }
    }
}

int colisao()//Essa função vai conferir se embaixo da peça jogável existe um chão, caso exista, ela vai colidir e executar a função acima, ela também irá retornar o valor para ser usado como parametro em outras funções do programa
{
    for(x = 0; x < 4; ++x)
    {
        for(y = 0; y < 4; ++y)
        {
            if(peca[x][y] == CORPO && tabuleiro[alt+x][larg+y] == 178)
            {
                imprimirNoTabuleiro();
                return 1;
            }
        }
    }
}

void gotoxy(int x, int y)//A função gotoxy move o cursor para as posições x e y, determinadas como argumento quando a função é chamada, ela foi usada no jogo para imprimir a peça jogável em posições diferentes, simulando sua movimentação
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
mostrarPecaETabuleiro()//Essa função serve para visualizar o jogo na tela, pois ela imprime as paredes do tabuleiro, o chão do tabuleiro, e também a peça jogável na sua posição determinada.
{
    system("cls");
    for(x = 0; x < 25; ++x)
    {
        for(y = 0; y < 18; ++y)
        {
            if(x == 24)
                tabuleiro[x][y] = 178;
            else if (y == 0 || y == 17)
                tabuleiro[x][y] = 219;
            printf("%c", tabuleiro[x][y]);
        }
        putchar('\n');
    }

    int var = alt;

    for(x = 0; x < 4; ++x)
    {
        for(y = 0; y < 4; ++y)
        {
            if(peca[x][y] == CORPO)
            {
                gotoxy(larg+y, var+x);
                printf("%c", 219);

            }
        }
        gotoxy(larg+y, var+x+1);
    }
}

