#include <stdio.h>
#include "jogo.h"
#include "jogador.h"
#include "tabuleiro.h"

/*
typedef struct{
    tTabuleiro tabuleiro;
    tJogador jogador1;
    tJogador jogador2;
    
} tJogo;
*/

/**
 * Cria um jogo e retorna o jogo criado.
 * 
 * @return o jogo criado.
 */
tJogo CriaJogo() {
    tJogo j;

    j.jogador1 = CriaJogador(1);
    j.jogador2 = CriaJogador(2);
    j.tabuleiro = CriaTabuleiro();
    return j;
}


/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 * 
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo jogo) {
    
    while(1) {

        //jogador 1

        jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro);
        ImprimeTabuleiro(jogo.tabuleiro);

        if(VenceuJogador(jogo.jogador1, jogo.tabuleiro)) {
            printf("JOGADOR 1 Venceu!\n");
            
            printf("Jogar novamente? (s,n)\n");
            if(ContinuaJogo()) {
                jogo = CriaJogo();
                continue;
            } else {
                return;
            }
            
        }

        if(AcabouJogo(jogo)) {
            printf("Sem vencedor!\n");
            
            printf("Jogar novamente? (s,n)\n");
            if(ContinuaJogo()) {
                jogo = CriaJogo();
                continue;
            } else {
                return;
            }
        }

        //jogador 2

        jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro);
        ImprimeTabuleiro(jogo.tabuleiro);

        if(VenceuJogador(jogo.jogador2, jogo.tabuleiro)) {
            printf("JOGADOR 2 Venceu!\n");

            printf("Jogar novamente? (s,n)\n");
            if(ContinuaJogo()) {
                jogo = CriaJogo();
                continue;
            } else {
                return;
            }
        }

        if(AcabouJogo(jogo)) {
            printf("Sem vencedor!\n");

            printf("Jogar novamente? (s,n)\n");
            if(ContinuaJogo()) {
                jogo = CriaJogo();
                continue;
            } else {
                return;
            }
        }
    }
}



/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 * 
 * @param jogo o jogo atual.
 * 
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo jogo) {
    if(TemPosicaoLivreTabuleiro(jogo.tabuleiro)) {
        return 0;
    }
    return 1;
}


/**
 * Verifica se o usuário deseja jogar novamente.
 * 
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo() {
    char l;


    scanf("%c", &l);

    if(l == 's') {
        return 1;
    } 

    return 0;
}

