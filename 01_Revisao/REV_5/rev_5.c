#include <stdio.h>
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
    
} tPosicoes;

tPosicoes lePosicao() {
    tPosicoes p;

    scanf("%d %d", &p.posX, &p.posY);

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


int main() {
    tPosicoes inicial, final;
    tCaminho caminho;
    char prioridade[4];

    caminho = iniciaMapa();
    inicial = lePosicao();
    final = lePosicao();

    return 0;
}