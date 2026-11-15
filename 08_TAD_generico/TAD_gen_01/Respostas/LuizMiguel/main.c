#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

int main () {
    printf("tad_gen_01\n");

    int tipoVariavel;
    int qtd;
    tGeneric *numeros;

    printf("Digite o tipo e numero de elementos: ");

    scanf("%d %d", &tipoVariavel, &qtd);

    numeros = CriaGenerico(tipoVariavel, qtd);
    LeGenerico(numeros);
    ImprimeGenerico(numeros);

    DestroiGenerico(numeros);

    return 0;
}