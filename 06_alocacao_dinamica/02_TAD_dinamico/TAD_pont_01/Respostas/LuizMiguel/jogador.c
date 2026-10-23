#include <stdio.h>
#include <stdlib.h>
#include "jogador.h"
#include "tabuleiro.h"
#include "jogada.h"


#define ID_JOGADOR_1 1
#define ID_JOGADOR_2 2
/*
typedef struct{
    int id;
} tJogador;
*/

/**
 * Aloca e retorna uma estrutura do tipo tJogador.
 * Se a alocação falhar, o programa é encerrado.
 *
 *  @param idJogador o ID do jogador (1 ou 2).
 * 
 * @return a estrutura do tipo tJogador alocada.
 */
tJogador* CriaJogador(int idJogador) {
    tJogador *j = (tJogador *) calloc (1, sizeof(tJogador));
    
    if(j == NULL) {
        printf("ERRO\nalocação (jogador %d)", idJogador);
    }

    j->id = idJogador;

    return j;
}


/**
 * Libera a memória de uma estrutura do tipo tJogador.
 * 
 * @param jogador a estrutura do tipo tJogador a ser liberada.
 */
void DestroiJogador(tJogador* jogador) {
    free(jogador);
}


/**
 * Lê uma jogada e armazena em uma estrutura do tipo tJogada.
 * 
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 */
void JogaJogador(tJogador* jogador, tTabuleiro* tabuleiro) {
    tJogada *jogada = CriaJogada();
    int x, y;

    do {
        printf("Jogador %d\n", jogador->id);

        LeJogada(jogada);

        if (FoiJogadaBemSucedida(jogada) == 0) {
            printf("Jogada invalida!\n");
            continue;
        } else if(FoiJogadaBemSucedida(jogada) == -1) {
            exit(1);
        }

        x = ObtemJogadaX(jogada);
        y = ObtemJogadaY(jogada);

        if (!EhPosicaoValidaTabuleiro(x, y)) {
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", x, y);
            continue;
        }

        if (!EstaLivrePosicaoTabuleiro(tabuleiro, x, y)) {
            printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
            continue;
        }

        MarcaPosicaoTabuleiro(tabuleiro, jogador->id, x, y);

        printf("Jogada [%d,%d]!\n", x, y);
        
        break;
    } while (1);
    
    DestroiJogada(jogada);
}


/**
 * Verifica se o jogador venceu o jogo.
 * 
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador* jogador, tTabuleiro* tabuleiro) {
    char peca;
    int i;

    if(jogador->id == 1) {
        peca = 'X';
    } else {
        peca = '0';
    }

    // primeira possibilidade LINHA INTEIRA
    for(i = 0 ; i < 3 ; i++) {
        if(tabuleiro->posicoes[i][0] == peca && tabuleiro->posicoes[i][1] == peca &&
        tabuleiro->posicoes[i][2] == peca) {
            return 1;
        }
    }

    //COLUNAS INTEIRAS
    for(i = 0 ; i < 3 ; i++) {
        if(tabuleiro->posicoes[0][i] == peca && tabuleiro->posicoes[1][i] == peca &&
        tabuleiro->posicoes[2][i] == peca) {
            return 1;
        }
    }
    //DIAGONAIS

    //DIAGONAL DA ESQUERDA PARA DIREITA
    if(tabuleiro->posicoes[0][0] == peca && tabuleiro->posicoes[1][1] == peca &&
    tabuleiro->posicoes[2][2] == peca) {
        return 1;
    }

    //DIAGONAL DA DIREITA PARA ESQUERDA
    if(tabuleiro->posicoes[0][2] == peca && tabuleiro->posicoes[1][1] == peca &&
    tabuleiro->posicoes[2][0] == peca) {
        return 1;
    }

    return 0;
}

