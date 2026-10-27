#include <stdio.h>
#include <stdlib.h>
#include "candidato.h"

#define MAX_STRING 50

/*
typedef struct {
    char* nome;
    char* partido;
    char cargo;
    int id;
    int votos;
} tCandidato;
*/

/**
 * @brief Cria um candidato "vazio".
 * Os ponteiros devem ser inicializados com NULL e os campos numéricos com o valor -1.
 * @return Candidato criado.
 */
tCandidato* CriaCandidato() {
    tCandidato *c = (tCandidato *) calloc (1, sizeof(tCandidato));
   
    c->nome = NULL;
    c->partido = NULL;
    c->id = -1;
    c->votos = -1;
    c->cargo = '\0';

    return c;
}

/**
 * @brief Apaga toda a memória alocada dinamicamente para guardar as informações de um candidato
 * @param candidato Ponteiro para o candidato que terá a memória desalocada
 * @return Candidato criado.
 */
void ApagaCandidato(tCandidato* candidato) {
    free(candidato->nome);
    free(candidato->partido);
    free(candidato);
}

/**
 * @brief Lê um candidato. O número de votos de um candidato deve ser zerado aqui.
 * @param candidato Candidato a ser lido.
 */
void LeCandidato(tCandidato *candidato) {
    candidato->nome = (char *) calloc (MAX_STRING, sizeof(char));
    candidato->partido = (char *) calloc (MAX_STRING, sizeof(char));

    scanf("\n%[^,], ", candidato->nome);
    scanf("%[^,], ", candidato->partido);
    scanf("%c, ", &candidato->cargo);
    scanf("%d\n", &candidato->id);

    candidato->votos = 0;
}

/**
 * @brief Verifica se o identificador do candidato é igual ao informado.
 * @param candidato Candidato a ser verificado.
 * @param id Identificador a ser comparado.
 * @return 1 se o identificador é igual, 0 caso contrário.
 */
int VerificaIdCandidato(tCandidato *candidato, int id) {
    return (candidato->id == id);
}

/**
 * @brief Verifica se dois candidatos são iguais (dica: utilize para verificar se houve empate).
 * @param candidato1 Primeiro candidato a ser comparado.
 * @param candidato2 Segundo candidato a ser comparado.
 * @return 1 se os candidatos são iguais, 0 caso contrário.
 */
int EhMesmoCandidato(tCandidato *candidato1, tCandidato *candidato2) {
    return (candidato1->id == candidato2->id);
}

/**
 * @brief Obtém o cargo do candidato.
 * @param candidato Candidato a ser verificado.
 * @return Cargo do candidato.
 */
char ObtemCargo(tCandidato* candidato) {
    return candidato->cargo;
}

/**
 * @brief Incrementa 1 voto ao candidato.
 * @param candidato Candidato a ter os votos incrementados.
 */
void IncrementaVotoCandidato(tCandidato* candidato) {
    candidato->votos += 1;
}

/**
 * @brief Obtém a quantidade de votos do candidato.
 * @param candidato Candidato a ser verificado.
 * @return Quantidade de votos do candidato.
 */
int ObtemVotos(tCandidato* candidato) {
    if(candidato->votos == -1) {
        return 0;
    }
    return candidato->votos;
}

/**
 * @brief Calcula o percentual de votos do candidato em relação ao total de votos (do mesmo cargo).
 * @param candidato Candidato a ser verificado.
 * @param totalVotos Total de votos da eleição.
 * @return Percentual de votos do candidato.
 */
float CalculaPercentualVotos(tCandidato* candidato, int totalVotos) {
    float p;

    p = ((candidato->votos * 100.0) / (float)totalVotos);

    return p;
}

/**
 * @brief Imprime os dados do candidato na tela.
 * @param candidato Candidato a ser impresso.
 * @param percentualVotos Percentual de votos do candidato.
 */
void ImprimeCandidato (tCandidato* candidato, float percentualVotos) {
    printf("%s ", candidato->nome);
    printf("(%s), ", candidato->partido);
    printf("%d voto(s), %.2f%%\n", candidato->votos, percentualVotos);
}

