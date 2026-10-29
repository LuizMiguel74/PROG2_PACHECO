#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estacionamento.h"

#include "veiculo.h"
#include "datahora.h"

struct Estacionamento {
    Veiculo **veiculo;
    int totalEntradasEstacionamento;
    int totalSaidasEstacionamento;
    int totaisNoPatio;
};


/**
 * @brief   Cria um estacionamento vazio (nenhum veículo registrado).
 *
 *
 * @return  Ponteiro para o Estacionamento criado; NULL se a alocação falhar.
 * @post    O chamador é dono do estacionamento e deve liberá-lo com
 *          liberaEstacionamento().
 */
Estacionamento *criaEstacionamento() {
    Estacionamento *e = (Estacionamento *) calloc (1, sizeof(Estacionamento));

    if(e == NULL) {
        printf("ERRO\nalocacao (estacionamento)");
    }


    return e;
}

/**
 * @brief   Registra a entrada de um veículo no estacionamento.
 *
 * O veículo é inserido no estacionamento considerando todo gerenciamento de memória necessário.
 *
 * @param e  [entrada/saída]  Estacionamento (não-nulo).
 * @param v  [entrada]        Veículo que está entrando (não-nulo, no pátio). O
 *                            Estacionamento passa a ser DONO do ponteiro.
 *
 * @pre     Não existe no estacionamento outro veículo com a mesma placa
 *          (a função NÃO verifica duplicidade).
 * @post    getTotalEntradasEstacionamento(e) aumenta em 1.
 */
void registraEntradaEstacionamento(Estacionamento *e, Veiculo *v) {
    int indice;

    indice = e->totalEntradasEstacionamento;

    e->totalEntradasEstacionamento += 1;
    e->totaisNoPatio += 1;
    
    
    e->veiculo = realloc (e->veiculo, e->totalEntradasEstacionamento * sizeof(Veiculo *));

    e->veiculo[indice] = v;

}

/**
 * @brief   Registra a saída do veículo de placa informada.
 *
 * Procura, na lista do estacionamento, o veículo cuja placa é IGUAL a placa
 * (comparação exata de strings) E que ainda está no pátio.
 *   - Se encontrar, registra nele a data/hora de saida (registraSaidaVeiculo()).
 *   - Se NÃO encontrar (placa nunca entrou, ou o veículo dessa placa já saiu), a
 *     saída é IGNORADA e nada é alterado.
 *
 * @param e      [entrada/saída]  Estacionamento (não-nulo).
 * @param placa  [entrada]        Placa do veículo que está saindo.
 * @param saida  [entrada]        Data/hora de saída (não-nula).
 *
 * @return  1 se a saída foi registrada; neste caso o veículo passa a ser DONO de
 *            saida (o chamador NÃO deve liberá-lo);
 *          0 se a saída foi ignorada; neste caso o chamador CONTINUA dono de saida
 *            e é responsável por liberá-lo com liberaDataHora().
 */
int registraSaidaEstacionamento(Estacionamento *e, char *placa, DataHora *saida) {
    char *placaNoEstacionamento;
    int liberado = 0;

    for(int i = 0 ; i < e->totalEntradasEstacionamento ; i++) {
       placaNoEstacionamento = getPlacaVeiculo(e->veiculo[i]);
       
       if(strcmp(placaNoEstacionamento, placa) == 0) {
            if(estaNoPatioVeiculo(e->veiculo[i])) {
                registraSaidaVeiculo(e->veiculo[i], saida); 
                liberado = 1;
                break;
            }
        }
    }

    
    if(liberado) {
        e->totalSaidasEstacionamento += 1;
        e->totaisNoPatio -= 1;

        return 1;
    }

    return 0;
}

/**
 * @brief   Retorna a quantidade total de entradas registradas.
 *
 * @param e  [entrada]  Estacionamento (não-nulo).
 * @return  Número de veículos registrados (estejam no pátio ou não).
 */
int getTotalEntradasEstacionamento(Estacionamento *e) {
    return e->totalEntradasEstacionamento;
}

/**
 * @brief   Retorna a quantidade de saídas registradas (veículos que já saíram).
 *
 * @param e  [entrada]  Estacionamento (não-nulo).
 * @return  Número de veículos cuja saída foi registrada (saídas ignoradas não contam).
 */
int getTotalSaidasEstacionamento(Estacionamento *e) {
    return e->totalSaidasEstacionamento;
}

/**
 * @brief   Retorna a quantidade de veículos que ainda estão no pátio (ocupação).
 *
 * @param e  [entrada]  Estacionamento (não-nulo).
 * @return  Número de veículos registrados cuja saída ainda não foi registrada.
 */
int getTotalNoPatioEstacionamento(Estacionamento *e) {
    return e->totaisNoPatio;
}

/**
 * @brief   Soma o tempo de permanência de todos os veículos que já saíram.
 *
 * @param e  [entrada]  Estacionamento (não-nulo).
 * @return  Soma, em minutos, de calculaPermanenciaVeiculo() de todos os veículos
 *          registrados (veículos no pátio contribuem com 0). 0 se não houver saídas.
 */
int calculaPermanenciaTotalEstacionamento(Estacionamento *e) {
    int total = 0;

    for(int i = 0 ; i < e->totalEntradasEstacionamento ; i++) {
        
        if(!(estaNoPatioVeiculo(e->veiculo[i]))) {
            total += calculaPermanenciaVeiculo(e->veiculo[i]);
        }
        
    }

    return total;
}

/**
 * @brief   Calcula o faturamento total do estacionamento.
 *
 * @param e  [entrada]  Estacionamento (não-nulo).
 * @return  Soma, em reais inteiros, de calculaTarifaVeiculo() de todos os veículos
 *          registrados (veículos no pátio contribuem com 0).
 */
int calculaFaturamentoEstacionamento(Estacionamento *e) {
    int totalCobranca = 0;

    for(int i = 0 ; i < e->totalEntradasEstacionamento ; i++) {
        if(!(estaNoPatioVeiculo(e->veiculo[i]))) {
            totalCobranca += calculaTarifaVeiculo(e->veiculo[i]);
        }
    }

    return totalCobranca;
}

/**
 * @brief   Imprime os veículos que ainda estão no pátio.
 *
 * Percorre a lista na ORDEM DE ENTRADA e chama imprimeVeiculo() para cada veículo
 * que ainda está no pátio (os que já saíram não são impressos). Não imprime nenhum
 * cabeçalho: se não houver veículos no pátio, nada é impresso.
 *
 * @param e  [entrada]  Estacionamento (não-nulo).
 */
void imprimeVeiculosNoPatioEstacionamento(Estacionamento *e) {
    if(e->totaisNoPatio) {
        for(int i = 0 ; i < e->totalEntradasEstacionamento ; i++) {
            if((estaNoPatioVeiculo(e->veiculo[i]))) {
                imprimeVeiculo(e->veiculo[i]);
            }
        }
    }
}

/**
 * @brief   Libera toda a memória associada ao estacionamento.
 *
 * Libera cada veículo registrado no estacionamento.
 * @param e  [entrada]  Estacionamento a liberar.
 * @post    e e todos os veículos que ele possuía não devem mais ser usados.
 */
void liberaEstacionamento(Estacionamento *e) {
    for(int i = 0 ; i < e->totalEntradasEstacionamento ; i++) {
        liberaVeiculo(e->veiculo[i]);
    }
    free(e->veiculo);
    free(e);

}

