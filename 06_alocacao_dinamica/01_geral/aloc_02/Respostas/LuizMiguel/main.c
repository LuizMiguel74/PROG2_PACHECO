#include <stdio.h>
#include "utils.h"

int main() {
    int linha, coluna;

    scanf(" %d %d", &linha, &coluna);

    int **matriz = CriaMatriz(linha, coluna);

    LeMatriz(matriz, linha, coluna);

    ImprimeMatrizTransposta(matriz, linha, coluna);

    LiberaMatriz(matriz, linha);

    return 0;
}