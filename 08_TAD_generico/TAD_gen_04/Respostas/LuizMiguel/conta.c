#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conta.h"
#include "vector.h"

#define MAX_NOME 51

/**
 * @brief Estrutura para representar uma conta bancária.
 */

struct Conta{
    int numeroConta;
    float saldo;
    char* nome;
};



/**
 * @brief Função para criar uma nova conta bancária.
 * @return Um ponteiro para a nova conta bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tConta *CriaConta() {
    tConta *c = (tConta *) calloc (1, sizeof(tConta));

    if(c == NULL) {
        printf("ERRO\nalocacao(conta)");
    }

    return c;
}

/**
 * @brief Função para destruir uma conta bancária.
 * @param conta A conta bancária a ser destruída.
 */
void DestroiConta(DataType conta) {
    free(((tConta *)conta)->nome);
    free(conta);
}

/**
 * @brief Função para ler uma conta bancária no formato "numero;nome do cliente;saldo inicial".
 * @param conta A conta bancária a ser lida.
 */
void LeConta(tConta *conta) {
    conta->nome = (char **) calloc (MAX_NOME, sizeof(char *));

    scanf("%d;", &conta->numeroConta);
    scanf("%[^;];", conta->nome);
    scanf("%f", &conta->saldo);
}

/**
 * @brief Função para obter o saldo de uma conta bancária.
 * @param conta A conta bancária.
 * @return O saldo da conta bancária.
 */
float GetSaldoConta(tConta *conta) {
    return conta->saldo;
}

