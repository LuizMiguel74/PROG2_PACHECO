/**
 * @file banco.h
 * @brief Este arquivo contém a declaração da estrutura tBanco e suas funções relacionadas.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "banco.h"
#include "agencia.h"
#include "vector.h"

#define MAX_NOME 51

/**
 * @brief Estrutura para representar um banco.
 */

struct Banco {
    int qtdAgencias;
    char* nome;
    DataType* agencias;
};



/**
 * @brief Função para criar um novo banco.
 * @return Um ponteiro para o novo banco criado. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tBanco *CriaBanco() {
    tBanco *b = (tBanco *) calloc (1, sizeof(tBanco));

    if(b == NULL) {
        printf("ERRO\nalocacao(banco)");
        exit(1);
    }
    return b;
}

/**
 * @brief Função para destruir um banco.
 * @param banco O banco a ser destruído.
 */
void DestroiBanco(tBanco *banco) {
    for(int i = 0 ; i < banco->qtdAgencias ; i++) {
        DestroiAgencia(((tBanco *)banco)->agencias [i]);
    }
    free(banco->agencias);
    free(banco->nome);
    free(banco);
}

/**
 * @brief Função para ler o nome de um banco.
 * @param banco O banco a ser lido.
 */
void LeBanco(tBanco *banco) {
    banco->nome = (char *) calloc (MAX_NOME, sizeof(char));
    
    scanf("%[^\n]", banco->nome);
}

/**
 * @brief Função para adicionar uma agência a um banco.
 * @param banco O banco.
 * @param agencia A agência a ser adicionada.
 */
void AdicionaAgencia(tBanco *banco, tAgencia *agencia) {
    banco->qtdAgencias += 1;

    banco->agencias = (DataType *) realloc (banco->agencias ,banco->qtdAgencias * sizeof(DataType));

    banco->agencias[banco->qtdAgencias - 1] = agencia;
}

/**
 * @brief Função para inserir uma conta em uma agência pertencente ao banco.
 * @param banco O banco.
 * @param numAgencia O número da agência.
 * @param cliente A conta a ser inserida.
 * @pre A agência deve pertencer ao banco.
*/
void InsereContaBanco(tBanco *banco, int numAgencia, tConta *cliente) {
    for(int i = 0 ; i < banco->qtdAgencias ; i++) {
        if(ComparaAgencia(numAgencia, banco->agencias[i])) {
            AdicionaConta(banco->agencias[i], cliente);
            break;
        }
    }
    
}

/**
 * @brief Função para imprimir o relatório de um banco, com o nome do banco e a lista de agências.
 * @param banco O banco.
 */
void ImprimeRelatorioBanco(tBanco *banco) {
    printf("%s\n", banco->nome);
    printf("Lista de agencias:\n");

    for(int i = 0 ; i < banco->qtdAgencias ; i++) {
        ImprimeDadosAgencia(banco->agencias[i]);
    }
}

