#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aluno.h"
#include "vector.h"

#define NOME_MAX 51 //(50 caracteres + \0)

struct Aluno {
    char* nome;
    char genero;
    float nota;
};

/**
 * @brief Aloca memoria para um aluno
 * 
 * @return A estrutura tAluno inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
tAluno *CriaAluno() {
    tAluno *a = (tAluno *) calloc (1, sizeof(tAluno));

    if(a == NULL) {
        printf("ERRO\nalocacao(aluno)");
    }

    return a;
}

/**
 * @brief Libera a memoria alocada para um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * Dica: Foi usado data_type para generalizar a funcao e usar na estrutura Vector. Por isso, é necessário fazer um cast para tAluno* dentro da função.
*/
void DestroiAluno(data_type aluno) {
    free(((tAluno *) aluno)->nome);
    free(((tAluno *) aluno));
}

/**
 * @brief Le os dados de um aluno
 * 
 * @param aluno Ponteiro para o aluno
*/
void LeAluno(tAluno *aluno) {
    aluno->nome = (char *) calloc (NOME_MAX, sizeof(char));

    scanf(" %[^;];", aluno->nome);
    scanf("%c;", &aluno->genero);
    scanf("%f", &aluno->nota);

}

/**
 * @brief Retorna o genero de um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * @return char Genero do aluno
*/
char GetGeneroAluno(tAluno *aluno) {
    return aluno->genero;
}

/**
 * @brief Retorna a nota de um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * @return float Nota do aluno
*/
float GetNotaAluno(tAluno *aluno) {
    return aluno->nota;
}
