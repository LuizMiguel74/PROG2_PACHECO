#include "tabuleiro.h"

#define TAM_TABULEIRO 3
#define PECA_1 1
#define PECA_2 2

/*
typedef struct{
    char posicoes[TAM_TABULEIRO][TAM_TABULEIRO];
    char peca1;
    char peca2;
    char pecaVazio;
} tTabuleiro;
*/

/**
 * Cria um tabuleiro e retorna o tabuleiro criado.
 * 
 * @return o tabuleiro criado.
 */
tTabuleiro CriaTabuleiro() {
    tTabuleiro t;
    int i, j;

    for(i = 0 ; i < 3 ; i++) {
        for(j = 0 ; j < 3 ; j++) {
            t.posicoes[i][j] = '-';
        }
    }
    return t;
}


/**
 * Marca uma posição do tabuleiro com a peça do jogador e retorna o tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param peca a peça do jogador (1 ou 2).
 * @param x a coordenada x da posição a ser marcada.
 * @param y a coordenada y da posição a ser marcada.
 * 
 * @return o tabuleiro atualizado.
 */
tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y) {
    char jogadorPeca;
    if(peca == 1) {
        jogadorPeca = 'X';
    }
    if(peca == 2) {
        jogadorPeca = '0';
    }

    
    if(EhPosicaoValidaTabuleiro(x, y)) {
        if(TemPosicaoLivreTabuleiro(tabuleiro)) {
            if(EstaLivrePosicaoTabuleiro(tabuleiro, x, y)) {
                tabuleiro.posicoes[y][x] = jogadorPeca;
            }
        }
    }
    return tabuleiro;
}


/**
 * Verifica se há alguma posição livre no tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se há posição livre, 0 caso contrário.
 */
int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro) {
    int i, j;

    for(i = 0 ; i < 3 ; i++) {
        for(j = 0 ; j < 3 ; j++) {
            if(tabuleiro.posicoes[i][j] == '-') {
                return 1;
            }
        }
    }
    return 0;
}


/**
 * Verifica se a posição do tabuleiro está marcada com a peça do jogador.
 * 
 * @param tabuleiro - o tabuleiro atual.
 * @param x a coordenada x da posição a ser verificada.
 * @param y a coordenada y da posição a ser verificada.
 * @param peca a peça do jogador (1 ou 2).
 * 
 * @return 1 se a posição está marcada com a peça do jogador, 0 caso contrário.
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca) {
    char jogadorPeca;
    if(peca == 1) {
        jogadorPeca = 'X';
    }
    if(peca == 2) {
        jogadorPeca = '0';
    }

    return (tabuleiro.posicoes[y][x] == jogadorPeca);
}


/**
 * Verifica se a posição do tabuleiro está livre.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param x a coordenada x da posição a ser verificada.
 * @param y a coordenada y da posição a ser verificada.
 * 
 * @return 1 se a posição está livre, 0 caso contrário.
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y) {
    return (tabuleiro.posicoes[y][x] == '-');
}

/**
 * Verifica se a posição do tabuleiro é válida.
 * 
 * @param x a coordenada x da posição a ser verificada.
 * @param y a coordenada y da posição a ser verificada.
 * @return 1 se a posição é válida, 0 caso contrário.
*/
int EhPosicaoValidaTabuleiro(int x, int y) {
    if(x < 0 || x > 2) {
        return 0;
    }
    if(y < 0 || y > 2) {
        return 0;
    }
    return 1;
}


/**
 * Verifica se o tabuleiro está cheio.
 * 
 * @param tabuleiro o tabuleiro atual.
 */
void ImprimeTabuleiro(tTabuleiro tabuleiro) {
    int i, j;

    for(i = 0 ; i < 3 ; i++) {
        printf("\t");
        for(j = 0 ; j < 3 ; j++) {
            printf("%c", tabuleiro.posicoes[i][j]);
        }
        printf("\n");
    }
    
}


