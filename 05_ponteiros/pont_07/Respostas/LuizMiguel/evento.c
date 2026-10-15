#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "evento.h"

#define MAX_EVENTOS 10

/*
//Estrutura para representar um evento no calendário. 
typedef struct {
    char nome[50]; // Nome do evento.
    int dia;       // Dia do evento.
    int mes;       // Mês do evento.
    int ano;       // Ano do evento.
} Evento;
*/

/**
 * Cadastra um novo evento no calendário e o insere na próxima posição do array.
 *
 * @param eventos Array de eventos onde o novo evento será cadastrado.
 * @param numEventos Ponteiro para o número atual de eventos cadastrados.
 */
void cadastrarEvento(Evento* eventos, int* numEventos) {
    if(*numEventos >= MAX_EVENTOS) {
        exit(1);
    }

    scanf(" %49[^\n]", eventos[*numEventos].nome);

    scanf("%02d %02d %04d", &eventos[*numEventos].dia, &eventos[*numEventos].mes, 
        &eventos[*numEventos].ano);

    *(numEventos) += 1;
    
    printf("Evento cadastrado com sucesso!\n");
}

/**
 * Exibe todos os eventos cadastrados no calendário.
 *
 * @param eventos Array de eventos a serem exibidos.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void exibirEventos(Evento* eventos, int* numEventos) {
    for(int i = 0 ; i < *numEventos ; i++) {
        printf("%d - %s - ", i, eventos[i].nome);
        printf("%02d/%02d/%04d\n", eventos[i].dia, eventos[i].mes, eventos[i].ano);
    }
}

/**
 * Troca a data de um evento específico no calendário.
 *
 * @param eventos Array de eventos onde o evento será modificado.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarDataEvento(Evento* eventos, int* numEventos) {
    int indiceEvento;
    scanf("%d", &indiceEvento);

    if(indiceEvento < 0 || indiceEvento >= *numEventos) {
        exit(1);
    }

    scanf("%02d %02d %04d\n", &eventos[indiceEvento].dia, &eventos[indiceEvento].mes, 
    &eventos[indiceEvento].ano);
    
    printf("Data modificada com sucesso!\n");
}

/**
 * Troca a posição de dois eventos, a partir do índice, dentro do array de eventos.
 *
 * @param eventos Array de eventos onde a troca será realizada.
 * @param indiceA Ponteiro para o primeiro índice.
 * @param indiceB Ponteiro para o segundo índice.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos) {
    Evento aux;

    if(*indiceA >= *numEventos || *indiceB >= *numEventos) {
        exit(1);
    }

    //copia evento no indiceA para aux;
    strcpy(aux.nome, eventos[*indiceA].nome);
    aux.dia = eventos[*indiceA].dia;
    aux.mes = eventos[*indiceA].mes;
    aux.ano = eventos[*indiceA].ano;

    //copia evento no indiceB para o "vazio" evento no indiceA
    strcpy(eventos[*indiceA].nome, eventos[*indiceB].nome);
    eventos[*indiceA].dia = eventos[*indiceB].dia;
    eventos[*indiceA].mes = eventos[*indiceB].mes;
    eventos[*indiceA].ano = eventos[*indiceB].ano;

    //copia aux para o "vazio" evento no indiceB
    strcpy(eventos[*indiceB].nome, aux.nome);
    eventos[*indiceB].dia = aux.dia;
    eventos[*indiceB].mes = aux.mes;
    eventos[*indiceB].ano = aux.ano;

}



