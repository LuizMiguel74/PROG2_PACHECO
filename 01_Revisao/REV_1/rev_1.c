#include <stdio.h>
#include <math.h>

typedef struct {
    float x, y;
    float raio;
} tCirculo;

tCirculo leCirculo() {
    tCirculo c;

    scanf("%f %f %f\n", &c.x, &c.y, &c.raio);

    return c;
}

float calculaDistanciaEntreCirculos(tCirculo c1, tCirculo c2) {
    float d = 0;

    d = pow((c2.x - c1.x), 2) + pow((c2.y - c1.y), 2);
    d = sqrt(d);

    return d;
}

int verificaSeCirculosColidem(tCirculo c1, tCirculo c2, float d) {
    float somaRaio = 0;

    somaRaio = c1.raio + c2.raio;

    if(d <= somaRaio) {
        return 1;
    }

    return 0;
}

void imprimeResultado(tCirculo c1, tCirculo c2, float d) {
   
    if(verificaSeCirculosColidem(c1, c2, d)) {
        printf("ACERTOU\n");
    
    } else {
        printf("ERROU\n");
    }
}

int main() {
    tCirculo alvo, disparo;
    float distancia;

    alvo = leCirculo();
    disparo = leCirculo();

    distancia = calculaDistanciaEntreCirculos(alvo, disparo);

    imprimeResultado(alvo, disparo, distancia);
    
    return 0;
}