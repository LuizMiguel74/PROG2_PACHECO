#include <stdio.h>
#define MAX 20

typedef struct {
    int qtd;
    int n[MAX];
} tOctal;

int leNumero() {
    int n;

    scanf("%d\n", &n);
    
    return n;
}

tOctal transformaEmOctal(int n) {
    tOctal oc;
    int i = 0;

    while(n > 0) {
        oc.n[i] = n % 8;
        n = n / 8;
        i++;
    }
    oc.qtd = i;

    return oc;
}

void imprimeNumeroOctal(tOctal oc) {
    int i;
    
    for(i = oc.qtd - 1 ; i >= 0 ; i--) {
        printf("%d", oc.n[i]);
    }

    printf("\n");
}

int main() {
    tOctal numeroOctal;
    int numero;

    numero = leNumero();
    numeroOctal = transformaEmOctal(numero);
    imprimeNumeroOctal(numeroOctal);
    
    return 0;
}