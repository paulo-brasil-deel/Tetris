#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

extern peca[4][4];
extern CORPO;
extern valor;

escolherPeca()//Preenche a matriz peca com o valor da variável CORPO, mas apenas nas posições da matriz que representam o formato da peça, pois futuramente o programa irá verificar onde existe esse valor na matriz e imprimirá um símbolo da peça na tela, na posição que a peça jogável está.
{
    switch(valor)//Ele vai escolher a peça baseado na variável, que recebeu um valor aleatório de 1 a 7.
    {
    case 1:
        peca[2][2] = CORPO;
        peca[3][1] = CORPO;
        peca[3][2] = CORPO;
        peca[3][3] = CORPO;
        break;
    case 2:
        peca[2][1] = CORPO;
        peca[2][2] = CORPO;
        peca[3][2] = CORPO;
        peca[3][3] = CORPO;
        break;
    case 3:
        peca[2][1] = CORPO;
        peca[3][1] = CORPO;
        peca[3][2] = CORPO;
        peca[3][3] = CORPO;
        break;
    case 4:
        peca[2][2] = CORPO;
        peca[2][3] = CORPO;
        peca[3][1] = CORPO;
        peca[3][2] = CORPO;
        break;
    case 5:
        peca[3][0] = CORPO;
        peca[3][1] = CORPO;
        peca[3][2] = CORPO;
        peca[3][3] = CORPO;
        break;
    case 6:
        peca[2][3] = CORPO;
        peca[3][1] = CORPO;
        peca[3][2] = CORPO;
        peca[3][3] = CORPO;
        break;
    case 7:
        peca[2][1] = CORPO;
        peca[2][2] = CORPO;
        peca[3][1] = CORPO;
        peca[3][2] = CORPO;
    }
}

