#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gerenciadorpacotes.h"

#include "pacote.h"

struct gerenciadorpacotes {
    Type tipo;
    tPacote **pacotes;
    int qtdPacotes;
    int soma;
};


/**
 * @brief Cria uma TAD que gerencia pacotes. O pacote é um TAD genérico.
 *
 *
 * @return O gerenciador de pacotes
 */
tGerenciador* CriaGerenciador() {
    tGerenciador *g = (tGerenciador *) calloc (1, sizeof(tGerenciador));

    if(g == NULL) {
        printf("ERRO\nalocacao(gerenciador)");
        exit(1);
    }

    return g;
}

/**
 * @brief Adiciona um pacote ao gerenciador de pacotes.
 *
 * @param geren O gerenciador de pacotes que armazenará o pacote 
 * @param pac O pacote que queremos adicionar no gerenciador.
 *
 */
void AdicionaPacoteNoGerenciador(tGerenciador* geren, tPacote* pac) {
    geren->qtdPacotes += 1;

    geren->pacotes = (tPacote **) realloc (geren->pacotes, (geren->qtdPacotes * sizeof(tPacote *)));

    geren->pacotes[geren->qtdPacotes - 1] = pac;
}


/**
 * @brief Destrói um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que será destruído (memória liberada)
 *
 */
void DestroiGerenciador(tGerenciador* geren) {
    for(int i = 0 ; i < geren->qtdPacotes ; i++) {
        DestroiPacote(geren->pacotes[i]);
    }
    free(geren->pacotes);
    free(geren);
}

/**
 * @brief Imprime um pacote específico do gerenciador de pacotes.
 *
 * @param geren - O gerenciador de pacotes que terá um pacote impresso
 * @param idx - O índice do pacote a ser impresso (começa em zero!)
 *
 */
void ImprimirPacoteNoIndice(tGerenciador* geren, int idx) {
    ImprimePacote(geren->pacotes[idx]);
}


/**
 * @brief Imprime todos os pacotes de um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que terá seus pacotes impressos
 *
 */
void ImprimirTodosPacotes(tGerenciador* geren) {
    for(int i = 0 ; i < geren->qtdPacotes ; i++) {
        ImprimirPacoteNoIndice(geren, i);
    }
}
