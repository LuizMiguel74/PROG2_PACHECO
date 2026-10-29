#include <stdio.h>
#include <stdlib.h>

#include "estacionamento.h"

char indentificaVeiculos() {
    char c;

    scanf("%c\n", &c);

    return c;
}

int main () {
    char identificador;
    int media = 0, faturamento = 0;
    char placaVerificada[MAX_PLACA_VEIC];

    Estacionamento *estacionamento =  criaEstacionamento();
    Veiculo *veiculo;
    DataHora *dataHoraAtual;

    while(1) {
        identificador = indentificaVeiculos();

        if(identificador != 'E' && identificador != 'S') {
            break;
        }

        if(identificador == 'E') {
            veiculo = lerVeiculo(); 

            registraEntradaEstacionamento(estacionamento, veiculo);       

        } else if(identificador == 'S') {
            scanf("%7[^\n]\n", placaVerificada);
            dataHoraAtual = lerDataHora();

            if((registraSaidaEstacionamento(estacionamento, placaVerificada, dataHoraAtual)) == 0) {
                liberaDataHora(dataHoraAtual);
            }

        }
    }

    if(getTotalSaidasEstacionamento(estacionamento)){
        media = calculaPermanenciaTotalEstacionamento(estacionamento);
        media = media / getTotalSaidasEstacionamento(estacionamento);
    }

    
    faturamento = calculaFaturamentoEstacionamento(estacionamento);

    
    printf("TOTAL ENTRADAS: %d\n", getTotalEntradasEstacionamento(estacionamento));
    printf("TOTAL SAIDAS: %d\n", getTotalSaidasEstacionamento(estacionamento));

    if(media == 0) {
        printf("PERMANENCIA MEDIA (MIN): -\n");
    
    } else {
        printf("PERMANENCIA MEDIA (MIN): %d\n", media);
    }

    printf("FATURAMENTO (R$): %d\n", faturamento);
    printf("VEICULOS NO PATIO: %d\n", getTotalNoPatioEstacionamento(estacionamento));
    printf("LISTA DE VEICULOS NO PATIO:\n");
    imprimeVeiculosNoPatioEstacionamento(estacionamento); 

    liberaEstacionamento(estacionamento);

    return 0;
}