#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

#include "jogador.h"
#include "tabuleiro.h"

/*
typedef struct{
    tTabuleiro* tabuleiro;
    tJogador* jogador1;
    tJogador* jogador2;
    
} tJogo;
*/

/**
 * Aloca e retorna uma estrutura do tipo tJogo.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tJogo alocada.
 */
tJogo* CriaJogo() {
    tJogo *j = (tJogo *) calloc (1, sizeof(tJogo));

    if(j == NULL) {
        printf("ERRO\nalocação (jogo)");
        exit(1);
    }

    j->jogador1 = CriaJogador(1);
    j->jogador2 = CriaJogador(2);

    j->tabuleiro = CriaTabuleiro();

    return j;
}


/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 * 
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo* jogo) {
     while(1) {
        //jogador 1

        JogaJogador(jogo->jogador1, jogo->tabuleiro);
        ImprimeTabuleiro(jogo->tabuleiro);

        if(VenceuJogador(jogo->jogador1, jogo->tabuleiro)) {
            printf("JOGADOR 1 Venceu!\n");
            printf("Jogar novamente? (s,n)\n");

            if(ContinuaJogo()) {
                DestroiTabuleiro(jogo->tabuleiro);
                jogo->tabuleiro = CriaTabuleiro();
                continue;
            } else {
                break;
            }
            
        }

        if(AcabouJogo(jogo)) {
            printf("Sem vencedor!\n");
            printf("Jogar novamente? (s,n)\n");

            if(ContinuaJogo()) {
                 DestroiTabuleiro(jogo->tabuleiro);
                jogo->tabuleiro = CriaTabuleiro();
                continue;
            } else {
                break;
            }
        }

        //jogador 2

        JogaJogador(jogo->jogador2, jogo->tabuleiro);
        ImprimeTabuleiro(jogo->tabuleiro);

        if(VenceuJogador(jogo->jogador2, jogo->tabuleiro)) {
            printf("JOGADOR 2 Venceu!\n");
            printf("Jogar novamente? (s,n)\n");

            if(ContinuaJogo()) {
                DestroiTabuleiro(jogo->tabuleiro);
                jogo->tabuleiro = CriaTabuleiro();
                continue;
            } else {
                break;
            }
        }

        if(AcabouJogo(jogo)) {
            printf("Sem vencedor!\n");
            printf("Jogar novamente? (s,n)\n");
            
            if(ContinuaJogo()) {
                DestroiTabuleiro(jogo->tabuleiro);
                jogo->tabuleiro = CriaTabuleiro();
                continue;
            } else {
                break;
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
int AcabouJogo(tJogo* jogo) {
    if(!(TemPosicaoLivreTabuleiro(jogo->tabuleiro))) {
        return 1;
    }
    return 0;
}


/**
 * Verifica se o usuário deseja jogar novamente.
 * 
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo() {
    char escolha;

    while (scanf(" %c", &escolha) == 1) {
        if (escolha == 's' || escolha == 'S') {
            return 1;
        }

        if (escolha == 'n' || escolha == 'N') {
            return 0;
        }
    }

    return 0;
}


/**
 * Libera a memória de uma estrutura do tipo tJogo.
 * 
 * @param jogo a estrutura do tipo tJogo a ser liberada.
 */
void DestroiJogo(tJogo* jogo) {
    DestroiTabuleiro(jogo->tabuleiro);
    DestroiJogador(jogo->jogador2);
    DestroiJogador(jogo->jogador1);
    free(jogo);
}

