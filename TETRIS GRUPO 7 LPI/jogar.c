#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


extern peca[4][4], tabuleiro[25][18], CORPO, x, y, valor, alt, larg,tempodequeda;
int tempo, ponto;//A variável tempo irá ser usada para definir o intervalo de tempo necessário para que a peça desça no tabuleiro


void reiniciar()//Quando essa função for executada, irá limpar para que não seja mostrado nenhuma nova peça nele durante a execução do jogo, quando o jogo for reiniciado
{
    for(x = 0; x < 25; x++)
    {
        for(y = 0; y < 18; y++)
        {
            tabuleiro[x][y] = 0;//Está anulando os valores existentes na matriz tabuleiro
        }
    }
}


int fim()//Quando essa função retornar o valor 1, significa que o jogo terminou, ou seja, a pilha de peças alcançou o "teto" do tabuleiro
{
    for(x = 1; x < 17; ++x)
    {
        if(tabuleiro[3][x] == 178)
        {
            return 1;
        }
    }
}

int movDireita()//Essa função vai garantir que a peça jogável não atravesse as paredes do tabuleiro para a direita
{
    for(x = 0; x < 4; ++x)
    {
        for(y = 0; y < 4; ++y)
        {
            if((peca[x][y] == CORPO && tabuleiro[alt+x][larg+y+1] == 219) ||
                    (peca[x][y] == CORPO && tabuleiro[alt+x][larg+y+1] == 178))
            {
                return 1;
            }
        }
    }
}
int movEsquerda()//Essa função vai garantir que a peça jogável não atravesse as paredes do tabuleiro para a esquerda
{
    for(x = 0; x < 4; ++x)
    {
        for(y = 0; y < 4; ++y)
        {
            if((peca[x][y] == CORPO && tabuleiro[alt+x][larg+y-1] == 219)||
                    (peca[x][y] == CORPO && tabuleiro[alt+x][larg+y-1] == 178))
            {
                return 1;
            }
        }
    }
}
void checarColisao()//Essa função diz que, caso haja um colisão, vai sortear uma próxima peça jogável e também vai mudar a posição onde ela vai aparecer, além disso, vai somar um ponto na pontuação do jogador
{
    if(colisao() == 1)
    {
        alt = -1;
        larg = 5;
        valor = 1 + rand()%7;
        limparPeca();
        escolherPeca();
        ponto++;
    }

}

void jogar()//Essa função fará com a peça se locomova no tabuleiro, e é composta por outras funções que servem para mostrar o jogo, impedir que a peça jogável ultrapasse os limites do tabuleiro e decidir se o jogador perdeu ou não o jogo.
{
    while(1)//A função está em loop
    {
        while(!kbhit())//Enquanto o usuário não digita nada
        {
            if(fim() == 1)//Caso essa condição se satisfaça, o jogo acaba e volta para o inicio.
            {
                system("cls");
                printf("---GAME OVER---\n\n");
                printf("Voce fez: %d pontos\n\n", ponto);
                printf("Aperte qualquer tecla para computar a pontuacao...");
                getch();
                reiniciar();
                system("cls");
                pontuacao(ponto);
            }
            completarLinha();
            Sleep(tempo);
            checarColisao();
            mostrarPecaETabuleiro();
            ++alt;
            tempo = tempodequeda;
        }
        char mov = getch();//Vai receber um comando do usuário que pode ser usado para movimentar a peça.
        switch(mov)
        {
        case 'p'://P pausa o jogo
            getch();
            break;
        case 'd'://D move para a direita
            if(movDireita()!=1)
            {
                ++larg;
            }
            break;
        case 'a'://A para a esquerda
            if(movEsquerda()!=1)
            {
                --larg;
            }
            break;
        case 's'://S diminui o tempo necessário para a peça cair, logo, vai fazer ela descer mais rapidamente
            tempo = 50;
            break;
        case 'w'://W vai executar uma função que gira a peça.
            if(movDireita()!=1 && movEsquerda()!=1)//Ela nao rotaciona quando encostada nas paredes
            {
                rotacionar();
            }
        }
    }
}
