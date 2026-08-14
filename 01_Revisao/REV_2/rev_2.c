#include <stdio.h>

int leQuantidadeDeLinhas() {
    int l;

    scanf("%d", &l);

    return l;
}

/*
Imprime triangulo de Floyd
*/
void imprimeTrianguloEscada(int linha) {
    int i, j, numeroAtual = 0;
    int atualLinha = 0;

    for(i = 0 ; i < linha ; i++) {
        atualLinha++;
        for(j = 0 ; j < atualLinha ; j++) {
            numeroAtual++;
            printf("%d ", numeroAtual);

        }
        printf("\n");
    }
}

int main() {
    int linhas;

    linhas = leQuantidadeDeLinhas();
    imprimeTrianguloEscada(linhas);
    return 0;
}