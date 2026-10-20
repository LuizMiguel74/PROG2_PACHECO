#include <stdio.h>
#include "utils.h"

int leTamanhoVetor() {
    int p;
    scanf("%d", &p);
    return p;
}

int main() {
    int p;
    float media;

    p = leTamanhoVetor();

    int *vetor = CriaVetor(p);

    LeVetor(vetor ,p);

    media = CalculaMedia(vetor, p);

    printf("%.2f", media);

    LiberaVetor(vetor);

    return 0;
}