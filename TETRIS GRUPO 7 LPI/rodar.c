#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

extern peca[4][4];

rotacionar()//Essa função, caso executada, irá girar a peça.
{
    int aux[4][4] = {0};
    int x, y;
    for(x=0; x<4; ++x)
    {
        for(y=0; y<4; ++y)
        {
            aux[x][y] = peca[x][y];
        }
    }
    limparPeca();
    int i, j;
    for(i=0; i<4; ++i)
    {
        for(j=0; j<4; ++j)
        {
            peca[i][j] = aux[3-j][i];

        }
    }
}

