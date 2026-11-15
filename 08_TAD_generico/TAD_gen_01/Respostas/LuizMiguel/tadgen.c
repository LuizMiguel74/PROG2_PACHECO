#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

/*
typedef enum {
    FLOAT = 0,
    INT = 1
} Type;
*/

struct generic {
    Type tipoVetor;
    int qtd;
    void *vetor;
};



/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric* CriaGenerico(Type type, int numElem) {
    tGeneric * v = (tGeneric *) calloc (1, sizeof(tGeneric));

    if(v == NULL) {
        printf("ERRO\nalocacao(tipo generico)");
    }

    if(type == INT) {
        v->vetor = (int *) calloc (numElem, sizeof(int));
    
    } else if(type == FLOAT) {
        v->vetor = (float *) calloc (numElem, sizeof(float));
    }
    
    if(v->vetor == NULL) {
        printf("ERRO\nalocacao (vetor)");
    }

    v->qtd = numElem;
    v->tipoVetor = type;

    return v;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric* gen) {
    free(gen->vetor);
    free(gen);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric* gen) {
    printf("\nDigite o vetor:\n");

    if(gen->tipoVetor == INT) {
        for(int i = 0 ; i < gen->qtd ; i++) {
            scanf("%d ", &((int *) gen->vetor)[i]);
        }

    } else if(gen->tipoVetor == FLOAT) {
        float *vetorFloat = (float *) gen->vetor;

        for(int i = 0 ; i < gen->qtd ; i++) {
            scanf("%f ", &vetorFloat[i]);
        }
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric* gen) {
    if(gen->tipoVetor == INT) {
        for(int i = 0 ; i < gen->qtd ; i++) {
            printf("%d ", ((int *) gen->vetor) [i]);
        }
    } else if(gen->tipoVetor == FLOAT) {
        for(int i = 0 ; i < gen->qtd ; i++) {
            printf("%.2f ", ((float *) gen->vetor) [i]);
        }
    }
}

