#include <stdio.h>
#include "ponto.h"

int main() {
    Ponto ponto1, ponto2;
    float x, y;

    // cria pontos

    scanf("%f %f", &x, &y);    
    ponto1 = pto_cria(x, y);

    scanf("%f %f", &x, &y);
    ponto2 = pto_cria(x, y);

    printf("%g\n", pto_distancia(ponto1, ponto2));

    return 0;
}