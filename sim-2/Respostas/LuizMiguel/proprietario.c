#include <stdio.h>
#include <string.h>
#include "proprietario.h"

#define MAX_NOME_PROP 101    /* nome: até 100 caracteres + '\0'               */
#define MAX_CPF_PROP 15      /* CPF no padrão 000.000.000-00 (14 chars) + '\0' */

struct Proprietario {
    char *nome;
    char *cpf;
};


/**
 * @brief   Cria um proprietário com os dados informados.
 *
 * As strings são COPIADAS para dentro do proprietário; o chamador continua dono dos
 * buffers originais e pode reutilizá-los após a chamada.
 *
 * @param nome  [entrada]  Nome do proprietário (até MAX_NOME_PROP-1 caracteres;
 *                         pode conter espaços).
 * @param cpf   [entrada]  CPF no padrão "000.000.000-00" (exatamente 14 caracteres).
 *
 * @return  Ponteiro para o Proprietario criado; NULL se a alocação falhar.
 *
 * @pre     nome e cpf são strings válidas (não-nulas, com terminador).
 * @post    O chamador é dono do Proprietario retornado e deve liberá-lo com
 *          liberaProprietario() (ou transferir a posse ao Veiculo).
 */
Proprietario *criaProprietario(char *nome, char *cpf) {
    Proprietario *p = (Proprietario *) calloc (1, sizeof(Proprietario));

    if(p == NULL) {
        printf("ERRO\nalocacao (proprietario)");
    } 

    p->nome = (char *) calloc (MAX_NOME_PROP, sizeof(char));
    p->cpf = (char *) calloc (MAX_CPF_PROP, sizeof(char));

    if(p->nome == NULL || p->cpf == NULL) {
        printf("ERRO\nalocacao (nome ou cpf)");
    }

    strcpy(p->nome, nome);
    strcpy(p->cpf, cpf);

    return p;
}

/**
 * @brief   Lê os dados de um proprietário da entrada padrão e o cria.
 *
 * Lê, nesta ordem, uma informação por linha (consumindo a quebra de linha de cada):
 *   1. nome  (linha inteira, pode conter espaços)
 *   2. CPF   (ex.: "123.456.789-00")
 *
 * @return  Ponteiro para o Proprietario lido (mesmas regras de criaProprietario()).
 */
Proprietario *lerProprietario() {
    char nome[MAX_NOME_PROP];
    char cpf[MAX_CPF_PROP];

    scanf("%[^\n]\n", nome);
    scanf("%[^\n]\n", cpf);

    Proprietario *p = criaProprietario(nome, cpf);

    return p;
}

/**
 * @brief   Imprime o proprietário na saída padrão no formato "NOME (CPF)".
 *
 * Ex.: "DARTH VADER (111.222.333-44)". Há exatamente um espaço entre o nome e o
 * parêntese. NÃO imprime quebra de linha nem espaços antes/depois.
 *
 * @param p  [entrada]  Proprietário a imprimir (não-nulo).
 */
void imprimeProprietario(Proprietario *p) {
    printf("%s (%s)", p->nome, p->cpf);
}

/**
 * @brief   Libera a memória alocada para um proprietário.
 *
 * @param p  [entrada]  Proprietário a liberar.
 * @post    A memória apontada por p é liberada; o ponteiro não deve mais ser usado.
 */
void liberaProprietario(Proprietario *p) {
    free(p->nome);
    free(p->cpf);
    free(p);
}

