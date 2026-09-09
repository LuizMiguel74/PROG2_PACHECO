#include <stdio.h>
#include <stdlib.h>
#include "data.h"

typedef struct {
    int dia, mes, ano;
}tData;

tData leData() {
    tData d;

    scanf("%02d/%02d/%04d", &d.dia, &d.mes, &d.ano);

    return d;
}

int main() {
    tData data;
    int qtdDias = 0;

    data = leData();

    if(!(verificaDataValida(data.dia, data.mes, data.ano))) {
        printf("A data informada eh invalida\n");
        exit(0);
    }

    printf("Data informada: ");
    imprimeDataExtenso(data.dia, data.mes, data.ano);

    if(verificaBissexto(data.ano)) {
        printf("O ano informado eh bissexto\n");
    } else {
        printf("O ano informado nao eh bissexto\n");
    }

    qtdDias = numeroDiasMes(data.mes, data.ano);
    printf("O mes informado possui %02d dias\n", qtdDias);
    
    printf("A data seguinte eh: ");
    imprimeProximaData(data.dia, data.mes, data.ano);

    return 0;
}