#include <stdio.h>
#include <stdlib.h>
#include "data.h"

typedef struct {
    int dia, ano, mes;
}tData;

tData leData() {
    tData d;

    scanf("%02d/%02d/%04d", &d.dia, &d.mes, &d.ano);

    return d;
}

int main() {
    tData data1, data2;
    int difDias;

    data1 = leData();
    data2 = leData();
    
    if(!(verificaDataValida(data1.dia, data1.mes, data1.ano))) {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        exit(0);
    
    } else if(!(verificaDataValida(data2.dia, data2.mes, data2.ano))) {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        exit(0);
        }

    printf("Primeira data: ");
    imprimeDataExtenso(data1.dia, data1.mes, data1.ano);
    printf("Segunda data: ");
    imprimeDataExtenso(data2.dia, data2.mes, data2.ano);

    if(comparaData(data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano) == 1) {
        printf("A segunda data eh mais antiga\n");
    } else if(comparaData(data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano) == -1) {
        printf("A primeira data eh mais antiga\n");
    } else {
        printf("As datas sao iguais\n");
    }

    difDias = calculaDiferencaDias(data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano);

    printf("A diferenca em dias entre as datas eh: %02d dias\n", difDias);

    return 0;
}