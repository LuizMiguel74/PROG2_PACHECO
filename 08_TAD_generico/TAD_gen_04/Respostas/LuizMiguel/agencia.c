#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "agencia.h"
#include "conta.h"
#include "vector.h"

#define MAX_NOME 51

/**
 * @brief Estrutura para representar uma agência bancária.
 */
struct Agencia {
    int numeroAgencia;
    char* nome;
    int qtdContas;
    DataType* vetor;
};


/**
 * @brief Função para criar uma nova agência bancária.
 * @return Um ponteiro para a nova agência bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tAgencia *CriaAgencia() {
    tAgencia *a = (tAgencia *) calloc (1, sizeof(tAgencia));
    
    if(a == NULL) {
        printf("ERRO\nalocacao(agencia)");
    }
    return a;
}

/**
 * @brief Função para destruir uma agência bancária.
 * @param agencia A agência bancária a ser destruída.
 */
void DestroiAgencia(DataType agencia) {
    for(int i = 0 ; i < ((tAgencia *)agencia)->qtdContas ; i++) {
        DestroiConta(((tAgencia *) agencia)->vetor [i]);
    }

    free(((tAgencia *)agencia)->vetor);
    free(((tAgencia *)agencia)->nome);
    free(agencia);
}

/**
 * @brief Função para ler uma agência bancária no formato "numero;nome".
 * @param agencia A agência bancária a ser lida.
 */
void LeAgencia(tAgencia *agencia) {
    
    agencia->nome = (char *) calloc (MAX_NOME, sizeof(char));

    scanf("%d", &agencia->numeroAgencia);
    scanf(";%[^\n]", agencia->nome);
}

/**
 * @brief Função para adicionar uma conta bancária a uma agência bancária.
 * @param agencia A agência bancária.
 * @param conta A conta bancária a ser adicionada.
 */
void AdicionaConta(tAgencia *agencia, tConta *conta) {
    agencia->qtdContas += 1;

    agencia->vetor = (DataType *) realloc (agencia->vetor, agencia->qtdContas * sizeof(DataType));

    agencia->vetor[agencia->qtdContas - 1] = conta;
}

/**
 * @brief Função para comparar um número de agência bancária com uma agência bancária.
 * @param numAgencia O número da agência bancária.
 * @param agencia2 A agência bancária a ser comparada.
 * @return 1 se os números forem iguais, 0 caso contrário.
 */
int ComparaAgencia(int numAgencia, tAgencia *agencia2) {
    return (numAgencia == agencia2->numeroAgencia);
}

/**
 * @brief Função para obter o saldo médio das contas de uma agência bancária.
 * @param agencia A agência bancária.
 * @return O saldo médio das contas da agência.
 */
float GetSaldoMedioAgencia (tAgencia *agencia) {
    float media = 0;

    for(int i = 0 ; i < agencia->qtdContas ; i++) {
       media += GetSaldoConta(agencia->vetor[i]);
    }

    if(agencia->qtdContas == 0) {
        return 0.0;
    }

    return (media / agencia->qtdContas);
}

/**
 * @brief Função para imprimir os dados de uma agência bancária (nome, número, número de contas cadastradas e saldo médio).
 * @param agencia A agência bancária.
 */
void ImprimeDadosAgencia(tAgencia *agencia) {
    printf("\tNome: %s\n", agencia->nome);
    printf("\tNumero: %d\n", agencia->numeroAgencia);
    printf("\tNumero de contas cadastradas: %d\n", agencia->qtdContas);
    printf("\tSaldo médio: R$%.2f\n\n", GetSaldoMedioAgencia(agencia));
}

