#include <stdio.h>
#include <time.h>
#include <locale.h>

/*
*                            ***** QUIZ *****
*
* Notas da vers�o 1.1.0
* - Implementado procedimento �nico para respostas
*
*/

int score = 0;              /*            VARI�VEL DA PONTUA��O            */
int acertos = 0;            /*             VARIAVEL DE ACERTOS             */
int erros = 0;              /*              VARI�VEL DE ERROS              */
int perg = 0;               /*     VARI�VEL DA QUANTIDADE DE PERGUNTAS     */
int op = 1;                 /*             VARI�VEL DE RETORNO             */
int feedback = 0;           /*       VARIAVEL PARA RESPONDER JOGADOR       */
char r;                     /*     VARI�VEL DE VERIFICA��O DA RESPOSTA     */
char rcorreta;              /*     VARI�VEL DE VERIFICA��O DA RESPOSTA     */

void resp (char r,char rcorreta){
    r = tolower (r);   /*  MAIUSCULA = MINUSCULAS  */
    if (r == rcorreta)   /* RESPOSTA CERTA = +2 PONTOS */
        printf("\nResposta correta, Voc� ganhou 2 pontos!! \n\a\a"), score=score +2, acertos++, op=0, perg++;
    else if ((r!=rcorreta)&&(r == 'a')||(r == 'b')||(r == 'c')||(r == 'd'))  /* RESPOSTA ERRADA = -1PONTO */
        {
        printf("\nResposta errada, Voc� perdeu 1 ponto! \n\a"), score--, erros++, op=0, perg++;
        feedback = 1;
        }
    else   /* RESPOSTA INV�LIDA = RETORNA PERGUNTA */
        tryagain();
}

void tryagain (void){
    printf ("\nResposta invalida, tente novamente\n"), op=1;
    int tempo = clock();
    while (clock() - tempo < 800);
    system ("cls");
}

void pontparc (void){
    printf ("Voce tem: %d pontos \n\n", score);   /*                                           */
    system ("pause");                             /*  EXIBE A PONTUA��O A O FINAL DA RESPOSTA  */
    system ("cls");                               /*                                           */
}

void startperg (void){
    op = 1;
    feedback = 0;
}

int main (void){

    setlocale(LC_ALL, "Portuguese");
    float porcent;                    /*            VARI�VEL DA EFIC�CIA             */
    char nome[25];                    /*         VETOR PARA INSER��O DO NOME         */

    printf ("\n \t\t\tQuiz\n");                         /*                                      */
    printf ("Digite seu nome: ");                       /*                                      */
    scanf  ("%[^\n]s  ", nome);                         /*       APRESENTA��O DO JOGADOR        */
    system ("cls");                                     /*                                      */

    printf ("\n \t\t\tQuiz\n");
    printf ("\n\n\n\n\n   Ol� %s, seja bem vindo ao jogo de quiz"), nome;            /*                                */
    printf ("\n\n\n\n2 BEEP quando acertar uma pergunta e 1 beep quando errar.");    /*      APRESENTA��O DO QUIZ      */
    printf ("\n\n\n\n\n\n\n\n\n\n\nO jogo iniciar� em instantes!!");                 /*                                */
        int tempo = clock();                    /*                           */
            while (clock() - tempo < 4500);     /*     CONDI��O DE TEMPO     */
            system ("cls");                     /*                           */

/* *********************************************************** */
/* ******************** PRIMEIRA PERGUNTA ******************** */
/* *********************************************************** */

    startperg();
    while (op == 1)
    {
        printf ("\n \t\t\tQuiz\n");
        printf ("1) Qual o nome do elemento N, na tabela peri�dica?\n\n");
        printf (" A) Nitrog�nio\n B) F�sforo\n C) Hidrog�nio\n D) Boro\n\n");
        printf ("Sua resposta: ");
        scanf (" %c", &r);
        rcorreta = 'a';
        resp(r, rcorreta);
    }
    if (feedback == 1)
        printf("O elemento correto seria Nitrog�nio  :( \n");
    pontparc();


/* *********************************************************** */
/* ********************* SEGUNDA PERGUNTA ******************** */
/* *********************************************************** */

    startperg();
    while (op == 1)
    {
        printf ("\n \t\t\tQuiz\n");
        printf ("2) Qual a maior m�o no poker (Texas hold'em)?\n\n");
        printf (" A) Four of a kind\n B) Straight Flush\n C) FullHouse\n D) Royal Straight Flush\n\n");
        printf ("Sua resposta: ");
        scanf (" %c", &r);
        rcorreta = 'd';
        resp(r, rcorreta);
    }
    if (feedback == 1)
        printf("Quase l�, a resposta certa seria: D) Royal Straght Flush \n que � a sequencia de �s a 10 do mesmo naipe  :( \n");
    pontparc();

/* *********************************************************** */
/* ******************** TERCEIRA PERGUNTA ******************** */
/* *********************************************************** */

    startperg();
    while (op == 1)
    {
        printf ("\n \t\t\tQuiz\n");
        printf ("3) Qual a capital de  Roraima?\n\n");
        printf (" A) Bras�lia \n B) Porto Velho\n C) Boa Vista\n D) Jo�o Pessoa\n\n");
        printf ("Sua resposta: ");
        scanf (" %c", &r);
        rcorreta = 'c';
        resp(r, rcorreta);
    }
    if (feedback == 1)
        printf("Continue tentando, A resposta certa seria C) Boa Vista  :( \n");
    pontparc();


/* *********************************************************** */
/* ********************* QUARTA PERGUNTA ********************* */
/* *********************************************************** */

    startperg();
    while (op == 1)
    {
        printf ("\n \t\t\tQuiz\n");
        printf ("4) O que voc� coloca em uma torradeira?\n\n");
        printf (" A) Torrada \n B) Torresmo\n C) Bolo\n D) P�o\n\n");
        printf ("Sua resposta: ");
        scanf (" %c", &r);
        rcorreta = 'd';
        resp(r, rcorreta);
    }
    if (feedback == 1)
        printf("O certo seria colocar o p�o na torradeira, certo ??  :( \n");
    pontparc();

/* *********************************************************** */
/* ********************* QUINTA PERGUNTA ********************* */
/* *********************************************************** */

    startperg();
    while (op == 1)
    {
        printf ("\n \t\t\tQuiz\n");
        printf ("5) Um avi�o em um voo de Curitiba/S�o Paulo, no meio da viagem, \n");
        printf ("   sofreu uma falha mec�nica, e caiu exatamente na fronteira do \n");
        printf ("   Paran� com S�o Paulo. Onde devem ser enterrados os sobreviventes?\n\n");
        printf (" A) S�o Paulo\n B) N�o devem ser enterrados\n C) Paran�\n D) Curitiba\n\n");
        printf ("Sua resposta: ");
        scanf (" %c", &r);
        rcorreta = 'b';
        resp(r, rcorreta);
    }
    if (feedback == 1)
        printf("Voc� realmente enterraria SOBREVIVENTES ???  :( \n");
    pontparc();

/* *********************************************************** */
/* ********************** SEXTA PERGUNTA ********************* */
/* *********************************************************** */

    startperg();
    while (op == 1)
    {
        printf ("\n \t\t\tQuiz\n");
        printf ("6)Voc� esta participando de uma corrida e, antes de cruzar a \n");
        printf ("  linha de chegada, ultrapassa o segundo colocado. Em que posi��o voc� fica?\n\n");
        printf (" A) Primeiro\n B) Segundo\n C) Terceiro\n D) Quarto\n\n");
        printf ("Sua resposta: ");
        scanf (" %c", &r);
        rcorreta = 'b';
        resp(r, rcorreta);
    }
    if (feedback == 1)
        printf("Geralmente quando vc ultrapassa o segundo, passa a ser o segundo colocado!!  :( \n");
    pontparc();

/* *********************************************************** */
/* ********************* S�TIMA PERGUNTA ********************* */
/* *********************************************************** */

    startperg();
    while (op == 1)
    {
        printf ("\n \t\t\tQuiz\n");
        printf ("7)Qual a altura do Monte Everest\n\n");
        printf (" A) 6391m\n B) 7215m\n C) 8848m\n D) 9732m\n\n");
        printf ("Sua resposta: ");
        scanf (" %c", &r);
        rcorreta = 'c';
        resp(r, rcorreta);
    }
    if (feedback == 1)
        printf("Quase l�, mas a altura seria aproximadamente 8848m de altura  :( \n");
    pontparc();

/* *********************************************************** */
/* ******************* TELA DE RESULTADOS ******************** */
/* *********************************************************** */

    printf ("Parab�ns, %s!!!\n",nome);
    printf ("Foram %d perguntas\n", perg);
    printf ("Voc� marcou %d pontos,\n", score);
    printf ("Sendo %d acertos e %d erros\n", acertos, erros);
    porcent = acertos*(100/perg);
    printf ("Sua efic�cia foi de %.2f%c \n", porcent, 37);

    printf ("\n\n\n\n\n\n\n\n\n\n\n\n\t\t      Obrigado por usar este programa!!\n");      /*                       */
    printf ("\t\tDesenvolvido por: Gabriel Augusto Requena dos Reis\n");                   /*     AGRADECIMENTO     */
    printf ("\t\t        Sistemas de informacao - UFOP\n\n\n\n\n");                        /*                       */
    system ("pause");                                                                      /*                       */


    return 0;
}
