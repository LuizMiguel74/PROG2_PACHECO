#include <stdio.h>
#include "utils_char2.h"

int main() {
    char * string;
    int tamanho = TAM_PADRAO;

    string = CriaVetorTamPadrao();
    string = LeVetor(string, &tamanho);
    ImprimeString(string);

    LiberaVetor(string);
    return 0;
}