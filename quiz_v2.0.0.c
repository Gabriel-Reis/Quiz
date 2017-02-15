#include <stdio.h>
#include <time.h>
#include <locale.h>

/*
                                ***** QUIZ *****
*
* - Adicionado procedimento apra jogar novamente
* - Adicionado procedimento para agradecimentos
*
*/

int score = 0;              /*            VARIÁVEL DA PONTUAÇÃO            */
int acertos = 0;            /*             VARIAVEL DE ACERTOS             */
int erros = 0;              /*              VARIÁVEL DE ERROS              */
int perg = 0;               /*     VARIÁVEL DA QUANTIDADE DE PERGUNTAS     */
int op = 1;                 /*             VARIÁVEL DE RETORNO             */
int feedback = 0;           /*       VARIAVEL PARA RESPONDER JOGADOR       */
char r;                     /*     VARIÁVEL DE VERIFICAÇÃO DA RESPOSTA     */
char rcorreta;              /*     VARIÁVEL DE VERIFICAÇÃO DA RESPOSTA     */
int opp = 1;                /*        VARIÁVEL PARA JOGAR NOVAMENTE        */
char ans;                   /*        VARIÁVEL PARA JOGAR NOVAMENTE        */

//Verificação da resposta
void resp (char r,char rcorreta){
    r = tolower (r);             /*  MAIUSCULA = MINUSCULAS  */
    if (r == rcorreta)          /* RESPOSTA CERTA = +2 PONTOS */
        printf("\nResposta correta, Você ganhou 2 pontos!! \n\a"), score=score +2, acertos++, op=0, perg++;
    else if ((r!=rcorreta)&&(r == 'a')||(r == 'b')||(r == 'c')||(r == 'd'))  /* RESPOSTA ERRADA = -1PONTO */
        {
        printf("\nResposta errada, Você perdeu 1 ponto! \n\a"), score--, erros++, op=0, perg++;
        feedback = 1;
        }
    else   /* RESPOSTA INVÁLIDA = RETORNA PERGUNTA */
        tryagain();
}

//Procedimento caso a alternativa escolhida não seja válida
void tryagain (void){
    printf ("\nResposta invalida, tente novamente\n"), op=1;
    int tempo = clock();
    while (clock() - tempo < 800);
    system ("cls");
}

// Exibe a pontuacao atual ao final da respota
void pontparc (void){
    printf ("Voce tem: %d pontos \n\n", score);
    system ("pause");
    system ("cls");
}

//mudança em valores de variáveis, antes de cada pergunta
void startperg (void){
    op = 1;
    feedback = 0;
}

//  NOVA RODADA, CASO JOGADOR SELECIONE 'S'
    void again (void){
    printf ("\n\n Deseja jogar novamente ?\n");
    scanf (" %c", &ans);
    if ((ans == 's')||(ans == 'S'))
        opp = 1;
    else
        opp = 10;
    }

//AGRADECIMENTOS
    void agradecimento (void){
    system ("cls");
    printf ("\n\n\n\n\n\n\n\n\n\n\n\n\t\t        Obrigado por usar este programa!!\n");
    printf ("\t\tDesenvolvido por: Gabriel Augusto Requena dos Reis\n");
    printf ("\t\t       Sistemas de informacao - UFOP (2016) \n\n\n\n\n");
    system ("pause");
}

//Código Principal
int main (void){

    setlocale(LC_ALL, "Portuguese");
    while (opp == 1){
    float porcent;                    /*            VARIÁVEL DA EFICÁCIA             */
    char nome[40];                    /*         VETOR PARA INSERÇÃO DO NOME         */

    system ("cls");
    fflush(stdin);   // limpa o buffer do teclado no windows
    printf ("\n \t\t\tQuiz\n");                         /*                                      */
    printf ("Digite seu nome: ");                       /*                                      */
    gets  (nome);                                       /*       APRESENTAÇÃO DO JOGADOR        */
    system ("cls");                                     /*                                      */

    printf ("\n \t\t\tQuiz\n");
    printf ("\n\n\n\n\n   Olá %s, seja bem vindo ao jogo de Quiz", nome);            /*      APRESENTAÇÃO DO QUIZ      */
    printf ("\n\n\n\n\n\n\n\n\n\n\nO jogo iniciará em instantes!!");                 /*                                */
        int tempo = clock();                    /*                           */
            while (clock() - tempo < 2500);     /*     CONDIÇÃO DE TEMPO     */
            system ("cls");                     /*                           */

/* *********************************************************** */
/* ******************** PRIMEIRA PERGUNTA ******************** */
/* *********************************************************** */

    startperg();
    while (op == 1)
    {
        printf ("\n \t\t\tQuiz\n");
        printf ("1) Qual o nome do elemento N, na tabela periódica?\n\n");
        printf (" A) Nitrogênio\n B) Fósforo\n C) Hidrogênio\n D) Boro\n\n");
        printf ("Sua resposta: ");
        scanf (" %c", &r);
        rcorreta = 'a';
        resp(r, rcorreta);
    }
    if (feedback == 1)
        printf("O elemento correto seria Nitrogênio  :( \n");
    pontparc();


/* *********************************************************** */
/* ********************* SEGUNDA PERGUNTA ******************** */
/* *********************************************************** */

    startperg();
    while (op == 1)
    {
        printf ("\n \t\t\tQuiz\n");
        printf ("2) Qual a maior mão no poker (Texas hold'em)?\n\n");
        printf (" A) Four of a kind\n B) Straight Flush\n C) FullHouse\n D) Royal Straight Flush\n\n");
        printf ("Sua resposta: ");
        scanf (" %c", &r);
        rcorreta = 'd';
        resp(r, rcorreta);
    }
    if (feedback == 1)
        printf("Quase lá, a resposta certa seria: D) Royal Straght Flush \n que é a sequencia de Ás a 10 do mesmo naipe  :( \n");
    pontparc();

/* *********************************************************** */
/* ******************** TERCEIRA PERGUNTA ******************** */
/* *********************************************************** */

    startperg();
    while (op == 1)
    {
        printf ("\n \t\t\tQuiz\n");
        printf ("3) Qual a capital de  Roraima?\n\n");
        printf (" A) Brasília \n B) Porto Velho\n C) Boa Vista\n D) João Pessoa\n\n");
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
        printf ("4) O que você coloca em uma torradeira?\n\n");
        printf (" A) Torrada \n B) Torresmo\n C) Bolo\n D) Pão\n\n");
        printf ("Sua resposta: ");
        scanf (" %c", &r);
        rcorreta = 'd';
        resp(r, rcorreta);
    }
    if (feedback == 1)
        printf("O certo seria colocar o pão na torradeira, certo ??  :( \n");
    pontparc();

/* *********************************************************** */
/* ********************* QUINTA PERGUNTA ********************* */
/* *********************************************************** */

    startperg();
    while (op == 1)
    {
        printf ("\n \t\t\tQuiz\n");
        printf ("5) Um avião em um voo de Curitiba/São Paulo, no meio da viagem, \n");
        printf ("   sofreu uma falha mecânica, e caiu exatamente na fronteira do \n");
        printf ("   Paraná com São Paulo. Onde devem ser enterrados os sobreviventes?\n\n");
        printf (" A) São Paulo\n B) Não devem ser enterrados\n C) Paraná\n D) Curitiba\n\n");
        printf ("Sua resposta: ");
        scanf (" %c", &r);
        rcorreta = 'b';
        resp(r, rcorreta);
    }
    if (feedback == 1)
        printf("Você realmente enterraria SOBREVIVENTES ???  :( \n");
    pontparc();

/* *********************************************************** */
/* ********************** SEXTA PERGUNTA ********************* */
/* *********************************************************** */

    startperg();
    while (op == 1)
    {
        printf ("\n \t\t\tQuiz\n");
        printf ("6)Você esta participando de uma corrida e, antes de cruzar a \n");
        printf ("  linha de chegada, ultrapassa o segundo colocado. Em que posição você fica?\n\n");
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
/* ********************* SÉTIMA PERGUNTA ********************* */
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
        printf("Quase lá, mas a altura seria aproximadamente 8848m de altura  :( \n");
    pontparc();

/* *********************************************************** */
/* ******************* TELA DE RESULTADOS ******************** */
/* *********************************************************** */

    printf ("Parabéns, %s!!!\n",nome);
    printf ("Foram %d perguntas\n", perg);
    printf ("Você marcou %d pontos,\n", score);
    printf ("Sendo %d acertos e %d erros\n", acertos, erros);
    porcent = acertos*(100/perg);
    printf ("Sua eficácia foi de %.2f%c \n", porcent, 37);


    again();
    }
    agradecimento();

    return 0;
}
