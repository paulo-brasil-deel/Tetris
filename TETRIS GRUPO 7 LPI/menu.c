int tempodequeda;//Essa variável irá ser responsável por definir o tempo padrão que a peça levará para cair, e pode ser ajustado pela dificuldade do jogo.

void capa()//Essa função é puramente estética, mostra o nome do jogo.
{
    printf("--------------------------------------------------------\n");
    printf("----------------------TETRIS----------------------------\n");
    printf("--------------------------------------------------------\n\n\n");
}
void dificuldade()//Se essa função for executada, o usuário terá a opção de escolher a dificuldade do jogo
{
    char decisao;
    system("cls");
    printf("Escolha a dificuldade:\n1)Facil\n2)Medio\n3)Dificil\n");
    decisao=getch();
    if(decisao==49)//Verifica se o usuário digitou o número 1
        tempodequeda=400;
    else if(decisao=50)//Verifica se o usuário digitou o número 2
        tempodequeda=270;
    else if(decisao=51)//Verifica se o usuário digitou o número 3
        tempodequeda=75;
    else
        tempodequeda=400;//Caso o usuário não digite nenhum desses três números, o jogo por padrão define a dificuldade como sendo FÁCIL.

}
void decisoes(){//Essa função vai receber uma informação do usuário, que será usada para executar a opção do menu que ele escolheu.
   char decisao;
   while(1){
       decisao=getch();
       if(decisao==49)//Se o usuário escolheu para INICIAR, o jogo vai requisitar uma dificuldade e, quando está for dada, iniciará o jogo.
       {
           system("cls");
           dificuldade();
           jogar();
       }
       else if(decisao==50)
       {
           system("cls");
           Ranking();
       }
       else if(decisao==51)
       {
           system("cls");
           printf("FIM DE JOGO");
           exit(0);//Se o usuário escolheu SAIR, o programa fecha, retornando 0.
       }
   }
}
void menu()//Essa função vai, primeiramente, mostrar as instruções do jogo e, após uma pausa, irá mostras as opções do Menu, depois vai executar uma função que vai deixar o usuário escolher uma opção
{
    capa();
    printf("       ATENCAO       \n");
    printf("-->Utilize as teclas A e D para mover a peca na tela.\n-->W para girar a peca.\n-->S para descer a peca mais rapidamente\n\n");
    system("pause");
    system("cls");
    capa();
    printf("1)INICIAR\n2)RANKING\n3)SAIR");
    decisoes();
}



