#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

extern peca[4][4];
extern x, y;

limparPeca()//Essa função vai preencher a matriz peça com espaços vazios, de maneira que vai limpar ela de quaisquer outros valores.
{
    for(x = 0; x < 4; ++x)
    {
        for(y = 0; y < 4; ++y)
        {
            peca[x][y] = ' ';
        }
    }
}

