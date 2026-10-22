#include <stdio.h>
#include "jogo.h"

int main() {
    tJogo *jogo;
    jogo = CriaJogo();

    ComecaJogo(jogo);

    DestroiJogo(jogo);
    
    return 0;
}