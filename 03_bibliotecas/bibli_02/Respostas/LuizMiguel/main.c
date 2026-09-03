#include <stdio.h>
#include "matrix_utils.h"
#define MAX 30

int main() {
    int linha, coluna, linha2, coluna2;
    int escolha, escala, qualMatrix;
    int matrix[MAX][MAX], matrix2[MAX][MAX], result[MAX][MAX];

    scanf("%d %d", &linha, &coluna);

    matrix_read(linha, coluna, matrix);

    scanf("%d %d", &linha2, &coluna2);
    matrix_read(linha2, coluna2, matrix2);

    do {
        printf("1 - Somar matrizes\n2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n6 - Encerrar o programa\n");
        printf("Opcao escolhida: \n");

        scanf("%d", &escolha);
        
        if(escolha == 1) {
            
            if(possible_matrix_sum(linha, coluna, linha2, coluna2)) {
                matrix_add(linha, coluna, matrix, linha2, coluna2, matrix2, result);
                matrix_print(linha, coluna, result);
            } else {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        }
        if(escolha == 2) {
            
            if(possible_matrix_sub(linha, coluna, linha2, coluna2)) {
                matrix_sub(linha, coluna, matrix, linha2, coluna2, matrix2, result);
                matrix_print(linha, coluna, result);
            } else {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        }
        if(escolha == 3) {

            if(possible_matrix_multiply(coluna, linha2)) {
                matrix_multiply(linha, coluna, matrix, linha2, coluna2, matrix2, result);
                matrix_print(linha, coluna2, result);
            } else {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
            }
        }
        if(escolha == 4) {
            scanf("%d %d", &escala, &qualMatrix);

            if(qualMatrix == 1) {
                scalar_multiply(linha, coluna, matrix, escala);
                matrix_print(linha, coluna, matrix);
            } else {
                scalar_multiply(linha, coluna, matrix2, escala);
                matrix_print(linha, coluna, matrix2);
            }
        }
        if(escolha == 5) {
            transpose_matrix(linha, coluna, matrix, result);
            matrix_print(coluna, linha, result);
            
            //segunda matriz
            printf("\n");
            transpose_matrix(linha2, coluna2, matrix2, result);
            matrix_print(coluna2, linha2, result);
        }
        
    } while(escolha != 6);

    return 0;
}