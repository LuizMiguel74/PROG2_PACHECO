#include <stdio.h>
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
 * Cria um jogador com o id passado como parâmetro e retorna o jogador criado.
 * 
 * @param idJogador o id do jogador (1 ou 2).
 * 
 * @return tJogador o jogador criado.
 */
tJogador CriaJogador(int idJogador) {
    tJogador j;

    j.id = idJogador;

    return j;
}


/**
 * Recebe um jogador e um tabuleiro e retorna o tabuleiro com a jogada do jogador.
 * 
 * @param jogador o jogador que fará a jogada.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return o tabuleiro atualizado com a jogada do jogador.
 */
tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro) {
    tJogada jogada;
    int x, y;

    do {
        printf("Jogador %d\n", jogador.id);

        jogada = LeJogada();

        if (!FoiJogadaBemSucedida(jogada)) {
            printf("Jogada invalida!\n");
            continue;
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

        tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, x, y);

        printf("Jogada [%d,%d]!\n", x, y);
        return tabuleiro;

    } while (1);
}



/**
 * Recebe um jogador e um tabuleiro e retorna 1 se o jogador venceu e 0 caso contrário.
 * 
 * @param jogador o jogador a ser verificado.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro) {
    char peca;
    int i;

    if(jogador.id == 1) {
        peca = 'X';
    } else {
        peca = '0';
    }

    // primeira possibilidade LINHA INTEIRA
    for(i = 0 ; i < 3 ; i++) {
        if(tabuleiro.posicoes[i][0] == peca && tabuleiro.posicoes[i][1] == peca &&
        tabuleiro.posicoes[i][2] == peca) {
            return 1;
        }
    }

    //COLUNAS INTEIRAS
    for(i = 0 ; i < 3 ; i++) {
        if(tabuleiro.posicoes[0][i] == peca && tabuleiro.posicoes[1][i] == peca &&
        tabuleiro.posicoes[2][i] == peca) {
            return 1;
        }
    }
    //DIAGONAIS

    //DIAGONAL DA ESQUERDA PARA DIREITA
    if(tabuleiro.posicoes[0][0] == peca && tabuleiro.posicoes[1][1] == peca &&
    tabuleiro.posicoes[2][2] == peca) {
        return 1;
    }

    //DIAGONAL DA DIREITA PARA ESQUERDA
    if(tabuleiro.posicoes[0][2] == peca && tabuleiro.posicoes[1][1] == peca &&
    tabuleiro.posicoes[2][0] == peca) {
        return 1;
    }

    return 0;
}

