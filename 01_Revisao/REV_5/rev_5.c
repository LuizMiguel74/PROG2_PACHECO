#include <stdio.h>
#include <stdlib.h>
#define MAX 50

/*
codigo que imprime o caminho que um robo fez até chegar em outro ponto especifico
de acordo com uma prioridade de movimento
*/

typedef struct {
    int mapa[50][50];
    int linha, coluna;

} tCaminho;

typedef struct {
    int posX, posY;
    
} tPosicao;

typedef struct {
    char caminho[6];
    int posLinha, posColuna;
} tJogador;

typedef struct {
    tCaminho matriz;
    tPosicao posF;
    tJogador jogador;
} tJogo;

tJogador lePosicaoJogador() {
    tJogador j;

    scanf("%d %d\n", &j.posLinha, &j.posColuna);
    /*thiago manda a posicao natural e nao em vetor*/
    j.posLinha --;
    j.posColuna --;
    return j;
}

tPosicao lePosicaoFinal() {
    tPosicao p;

    scanf("%d %d\n", &p.posX, &p.posY);
    /*thiago manda como entrada a posicao natural e nao em vetor*/
    p.posX --;
    p.posY --;
    return p;
}

tCaminho iniciaMapa() {
    tCaminho c;
    int i, j;

    scanf("%d %d", &c.linha, &c.coluna);

    for(i = 0 ; i < c.linha ; i++) {
        
        for(j = 0 ; j < c.coluna ; j++) {
            scanf("%d", &c.mapa[i][j]);
        }
    }

    return c;

}

tJogador leSequenciaDeCaminhada() {
    tJogador j;

    scanf("%s", j.caminho);

    return j;
}

int verificaLimiteDoMapa(char letra, tJogador j, tCaminho c) {
    /*verifica limite do mapa se baseando que a posicao
    que o robo ja andou é -1 e que nao pode andar 1*/

    if(letra == 'C') {
        if(j.posLinha -1 < 0 || c.mapa[j.posLinha - 1][j.posColuna] == 1 
            || c.mapa[j.posLinha - 1][j.posColuna] == -1) {
                return 0;
        }
    } else if(letra == 'B') {
        if(j.posLinha +1 >= c.linha || c.mapa[j.posLinha + 1][j.posColuna] == 1 
            || c.mapa[j.posLinha + 1][j.posColuna] == -1) {
                return 0;
        }

    } else if(letra == 'D') {
        if(j.posColuna +1 >= c.coluna || c.mapa[j.posLinha][j.posColuna + 1] == 1 
            || c.mapa[j.posLinha][j.posColuna + 1] == -1) {
                return 0;
        }
    } else if(letra == 'E') {
        if(j.posColuna -1 < 0 || c.mapa[j.posLinha][j.posColuna - 1] == 1 
            || c.mapa[j.posLinha][j.posColuna - 1] == -1) {
                return 0;
        }
    } else {
        return -1;
    }
    return 1;
}

void imprimePosicao(int x, int y) {
    /*adiciona +1 graças ao motivo do comentario na linha 32 funcao lePosicaoJogador*/
    printf("(%d,%d) ", x + 1, y + 1);
}

tJogador atualizaJogador(tJogador j, char l) {
    if(l == 'C') {
        j.posLinha --;
    } else if(l == 'B') {
        j.posLinha++;
    } else if(l == 'D') {
        j.posColuna++;
    } else {
        j.posColuna--;
    }
    return j;
}

void caminhaPeloMapa(tJogo jogo) {
    int i, andou;

    imprimePosicao(jogo.jogador.posLinha, jogo.jogador.posColuna);

    while(1) {
        i = 0, andou = 0;

        while(jogo.jogador.caminho[i] != '\0') {

            if(verificaLimiteDoMapa(jogo.jogador.caminho[i], jogo.jogador, jogo.matriz) == 1) {
                jogo.matriz.mapa[jogo.jogador.posLinha][jogo.jogador.posColuna] = -1;
                jogo.jogador = atualizaJogador(jogo.jogador, jogo.jogador.caminho[i]);
                imprimePosicao(jogo.jogador.posLinha, jogo.jogador.posColuna);

                andou = 1;

                if(jogo.jogador.posLinha == jogo.posF.posX && 
                    jogo.jogador.posColuna == jogo.posF.posY) {
                        exit(0);
                }
                break;

            } else {
                i++;
            }
        }
        if(!(andou)) {
            break;
        }
    }
        
}

int main() {
    tJogo jogo;
    jogo.matriz = iniciaMapa();
    jogo.jogador = lePosicaoJogador();
    jogo.posF = lePosicaoFinal();
    jogo.jogador = leSequenciaDeCaminhada();

    caminhaPeloMapa(jogo);
    return 0;
}