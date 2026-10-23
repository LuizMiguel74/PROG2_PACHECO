#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

int main() {
    tJogo *jogo = CriaJogo();

    ComecaJogo(jogo);

    DestroiJogo(jogo);

    return 0;

}