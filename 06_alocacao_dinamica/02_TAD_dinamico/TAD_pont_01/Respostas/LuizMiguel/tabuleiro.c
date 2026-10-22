#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"


#define TAM_TABULEIRO 3
#define PECA_1 1
#define PECA_2 2

/*
typedef struct{
    char** posicoes;
    char peca1;
    char peca2;
    char pecaVazio;
} tTabuleiro;
*/

/**
 * Aloca e retorna uma estrutura do tipo tTabuleiro.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tTabuleiro alocada.
 */
tTabuleiro* CriaTabuleiro() {
    tTabuleiro *t = (tTabuleiro *) calloc (1, sizeof(tTabuleiro));

    t->peca1 = 'X';
    t->peca2 = '0';
    t->pecaVazio = '-';

    if(t == NULL) {
        printf("ERRO\nAlocação");
        exit(1);
    }

    t->posicoes = (char **) calloc (TAM_TABULEIRO, sizeof(char *));

    if(t->posicoes == NULL) {
        printf("ERRO\nAlocação(primeiro vetor da matriz)");
        exit(1);
    }

    for(int i = 0 ; i < TAM_TABULEIRO ; i++) {
        t->posicoes[i] = (char *) calloc (TAM_TABULEIRO, sizeof(char));

        if(t->posicoes[i] == NULL) {
            printf("ERRO\nAlocação(segundo vetor da matriz)");
            exit(1);
        }
    }

    //inicializa tudo com '-'
    for(int i = 0 ; i < TAM_TABULEIRO ; i++) {
        for(int j = 0 ; j < TAM_TABULEIRO ; j++) {
            t->posicoes[i][j] = t->pecaVazio;
        }
    }

    return t;
}


/**
 * Libera a memória de uma estrutura do tipo tTabuleiro.
 * 
 * @param tabuleiro a estrutura do tipo tTabuleiro a ser liberada.
 */
void DestroiTabuleiro(tTabuleiro* tabuleiro) {
    for(int i = 0 ; i < TAM_TABULEIRO ; i++) {
        free(tabuleiro->posicoes[i]);
    }
    free(tabuleiro->posicoes);
    free(tabuleiro);
}


/**
 * Marca uma posição do tabuleiro com a peça do jogador.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param peca a peça do jogador (1 ou 2).
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 */
void MarcaPosicaoTabuleiro(tTabuleiro* tabuleiro, int peca, int x, int y) {
    if(EhPosicaoValidaTabuleiro(x, y)) {
        
        if(TemPosicaoLivreTabuleiro(tabuleiro)) {
            if(EstaLivrePosicaoTabuleiro(tabuleiro, x, y)) {
            
                if(peca == 1) {
                   tabuleiro->posicoes[y][x] = tabuleiro->peca1;
                } else {
                    tabuleiro->posicoes[y][x] = tabuleiro->peca2;
                }
            }
        }

    }
    
}


/**
 * Verifica se há alguma posição livre no tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se há alguma posição livre, 0 caso contrário.
 */
int TemPosicaoLivreTabuleiro(tTabuleiro* tabuleiro) {
    int tem = 0;

    for(int i = 0 ; i < TAM_TABULEIRO ; i++) {
        for(int j = 0 ; j < TAM_TABULEIRO ; j++) {

            if(tabuleiro->posicoes[i][j] == tabuleiro->pecaVazio) {
                tem = 1;
                break;
            }
        }
    }
    return tem;
}


/**
 * Verifica se a posição do tabuleiro está marcada com a peça do jogador.
 * 
 * @param tabuleiro - o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * @param peca a peça do jogador (1 ou 2).
 * 
 * @return 1 se a posição está marcada com a peça do jogador, 0 caso contrário.
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro* tabuleiro, int x, int y, int peca) {
   if(!(EhPosicaoValidaTabuleiro(x, y))) {
    return 0;
   }
   
    if(peca == 1) {
        if(tabuleiro->posicoes[y][x] == tabuleiro->peca1) {
            return 1;
        }
    } else {
        if(tabuleiro->posicoes[y][x] == tabuleiro->peca2) {
            return 1;
        }
    }
    return 0;
}


/**
 * Verifica se a posição do tabuleiro está livre.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * 
 * @return 1 se a posição está livre, 0 caso contrário.
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro* tabuleiro, int x, int y) {
    return (tabuleiro->posicoes[y][x] == '-');
}


/**
 * Verifica se a posição do tabuleiro é válida.
 * 
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * 
 * @return 1 se a posição é válida, 0 caso contrário.
 */
int EhPosicaoValidaTabuleiro(int x, int y) {
    if(x >= TAM_TABULEIRO || x < 0 || y >= TAM_TABULEIRO || y < 0) {
        return 0;
    }
    return 1;
}


/**
 * Imprime o tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 */
void ImprimeTabuleiro(tTabuleiro* tabuleiro) {
    for(int i = 0 ; i < TAM_TABULEIRO ; i++) {
        printf("\t");
        for(int j = 0 ; j < TAM_TABULEIRO ; j++) {
            printf("%c", tabuleiro->posicoes[i][j]);
        }
        printf("\n");
    }
}


