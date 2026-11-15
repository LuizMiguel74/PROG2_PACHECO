#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacote.h"

/*
typedef enum {
    INT = 1,
    CHAR = 0
} Type;
*/

struct pacote {
    Type tipo;
    int qtd;
    int soma;
    void *vetor;
};


/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote* CriaPacote(Type type, int numElem) {
    tPacote *p = (tPacote *) calloc (1, sizeof(tPacote));

    if(p == NULL) {
        printf("ERRO\nalocacao (tipo generico)");
        exit(1);
    }

    p->tipo = type;
    p->qtd = numElem;

    return p;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote* pac) {
    free(pac->vetor);
    free(pac);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote* pac) {

    if(pac->tipo == CHAR) {
        pac->vetor = (char *) calloc (pac->qtd, sizeof(char));

        if(pac->vetor == NULL) {
            printf("ERRO\nalocacao (vetor generico CHAR)");
            exit(1);
        }

        if(pac->qtd > 0) {
            scanf(" %c", &((char *) pac->vetor)[0]);
            
            for(int i = 0 ; i < pac->qtd ; i++) {
               scanf("%c", &((char *) pac->vetor)[i]);
            }
        }
        

    } else if(pac->tipo == INT) {
        pac->vetor = (int *) calloc (pac->qtd, sizeof(int));
        
        if(pac->vetor == NULL) {
            printf("ERRO\nalocacao (vetor generico INT)");
            exit(1);
        }

        for(int i = 0 ; i < pac->qtd ; i++) {
            scanf("%d", &((int *) pac->vetor)[i]);
        }
    }
}

/**
 * @brief Imprime na tela um pacote que possui um id específico com seu valor calculado
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote* pac) {
    if(pac->tipo == INT) {
        for(int i = 0 ; i < pac->qtd ; i++) {
            printf("%d ", ((int *)pac->vetor) [i]);
        }

    } else if(pac->tipo == CHAR) {
        for(int i = 0 ; i < pac->qtd ; i++) {
            printf("%c ", ((char *)pac->vetor) [i]);
        }
    }
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote* pac) {
    pac->soma = 0;

    if(pac->tipo == CHAR) {
        for(int i = 0 ; i < pac->qtd ; i++) {
            pac->soma += (int) (((char *)pac->vetor) [i]);
        }
    } else if(pac->tipo == INT) {
        for(int i = 0 ; i < pac->qtd ; i++) {
            pac->soma += (((int *)pac->vetor) [i]);
        }
    }
}



