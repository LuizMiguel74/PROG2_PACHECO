#ifndef _VEICULO_H
#define _VEICULO_H


#include "datahora.h"
#include "proprietario.h"

#define MAX_PLACA_VEIC 8      /* placa com 7 caracteres + '\0' */

/* Categorias válidas (caractere maiúsculo lido da entrada) */
#define CATEGORIA_CARRO      'C'
#define CATEGORIA_MOTO       'M'
#define CATEGORIA_UTILITARIO 'U'

/* Valor (em reais inteiros) cobrado POR HORA ou FRAÇÃO DE HORA, por categoria */
#define TARIFA_CARRO      6
#define TARIFA_MOTO       3
#define TARIFA_UTILITARIO 10

/* Permanência máxima (em minutos, inclusive) que é isenta de cobrança */
#define TOLERANCIA_MIN 15

typedef struct Veiculo Veiculo;

/**
 * @brief   Cria um veículo que acabou de entrar no estacionamento.
 *
 *
 * @param placa         [entrada]  Placa do veículo (string com exatamente 7
 *                                 caracteres, ex.: "ABC1D23").
 * @param proprietario  [entrada]  Proprietário do veículo (não-nulo).
 * @param categoria     [entrada]  CATEGORIA_CARRO, CATEGORIA_MOTO ou
 *                                 CATEGORIA_UTILITARIO.
 * @param entrada       [entrada]  Data/hora de entrada (não-nula).
 *
 * @return  Ponteiro para o Veiculo criado; NULL se a alocação falhar.
 *
 * @pre     Todos os ponteiros são não-nulos e a categoria é uma das três válidas.
 * @post    O veículo criado está NO PÁTIO (ainda não possui data/hora de saída).
 *          O chamador é dono do veículo e deve liberá-lo com liberaVeiculo() (ou
 *          transferir a posse ao Estacionamento).
 */
Veiculo *criaVeiculo(char *placa, Proprietario *proprietario, char categoria, DataHora *entrada);

/**
 * @brief   Lê os dados de entrada de um veículo da entrada padrão e o cria.
 *
 * Lê, nesta ordem, uma informação por linha (consumindo a quebra de linha de cada):
 *   1. placa                  (ex.: "ABC1D23")
 *   2. nome do proprietário   } lidos com lerProprietario()
 *   3. CPF do proprietário    }
 *   4. categoria              (um caractere: 'C', 'M' ou 'U')
 *   5. data/hora de entrada   ("DD/MM/AAAA HH:MM", lida com lerDataHora())
 * A letra de comando que antecede esses dados NÃO é lida por esta função.
 *
 * @return  Ponteiro para o Veiculo lido (mesmas regras de criaVeiculo()).
 */
Veiculo *lerVeiculo();

/**
 * @brief   Retorna a placa do veículo.
 *
 * @param v  [entrada]  Veículo a consultar (não-nulo).
 * @return  Ponteiro para a string INTERNA com a placa. O chamador pode apenas lê-la:
 *          não deve modificá-la nem liberá-la.
 */
char *getPlacaVeiculo(Veiculo *v);

/**
 * @brief   Informa se o veículo ainda está no pátio.
 *
 * @param v  [entrada]  Veículo a consultar (não-nulo).
 * @return  1 se a saída do veículo AINDA NÃO foi registrada;
 *          0 se a saída já foi registrada.
 */
int estaNoPatioVeiculo(Veiculo *v);

/**
 * @brief   Registra a data/hora de saída do veículo.
 *
 * O veículo passa a ser DONO do ponteiro saida e o liberará em liberaVeiculo().
 *
 * @param v      [entrada/saída]  Veículo que está saindo (não-nulo).
 * @param saida  [entrada]        Data/hora de saída (não-nula), nunca anterior à
 *                                data/hora de entrada.
 *
 * @pre     estaNoPatioVeiculo(v) == 1 (a função NÃO verifica; quem chama é que
 *          deve garantir que a saída ainda não foi registrada).
 * @post    estaNoPatioVeiculo(v) passa a retornar 0.
 */
void registraSaidaVeiculo(Veiculo *v, DataHora *saida);

/**
 * @brief   Calcula o tempo de permanência do veículo, em minutos.
 *
 * @param v  [entrada]  Veículo a consultar (não-nulo).
 * @return  Minutos entre a data/hora de entrada e a de saída (ver
 *          diferencaMinutosDataHora()), se o veículo já saiu;
 *          0 se o veículo ainda está no pátio.
 */
int calculaPermanenciaVeiculo(Veiculo *v);

/**
 * @brief   Calcula o valor cobrado do veículo na saída, em reais inteiros.
 *
 * Regras, aplicadas sobre a permanência P (em minutos) do veículo:
 *   - se P <= TOLERANCIA_MIN, o valor é 0 (isento);
 *   - caso contrário, cobra-se a tarifa da categoria por hora OU FRAÇÃO de hora,
 *     isto é, valor = ceil(P / 60) * tarifa.
 *     Ex.: carro com P = 16  -> 1 hora  -> 6;
 *          carro com P = 60  -> 1 hora  -> 6;
 *          carro com P = 61  -> 2 horas -> 12.
 *   - tarifa: TARIFA_CARRO (C), TARIFA_MOTO (M) ou TARIFA_UTILITARIO (U).
 * Não há tarifa diária: uma permanência de vários dias é cobrada pelo total de horas.
 *
 * @param v  [entrada]  Veículo a consultar (não-nulo).
 * @return  O valor calculado conforme as regras acima, se o veículo já saiu;
 *          0 se o veículo ainda está no pátio (nada a cobrar ainda).
 */
int calculaTarifaVeiculo(Veiculo *v);

/**
 * @brief   Imprime uma linha com os dados do veículo na saída padrão.
 *
 * Formato EXATO (seguido de UMA quebra de linha, sem espaços extras no final):
 *   - PLACA - NOME (CPF) - DD/MM/AAAA HH:MM
 * onde "NOME (CPF)" é impresso com imprimeProprietario() e "DD/MM/AAAA HH:MM" é a
 * data/hora de ENTRADA, impressa com imprimeDataHora().
 * Ex.: "- UTL3F45 - MARTY MCFLY (333.444.555-66) - 27/10/2026 09:10\n"
 *
 * @param v  [entrada]  Veículo a imprimir (não-nulo).
 */
void imprimeVeiculo(Veiculo *v);

/**
 * @brief   Libera toda a memória associada ao veículo.
 *
 * Libera o proprietário, a data/hora de entrada, a data/hora de saída (se houver) e
 * o próprio veículo.
 *
 * @param v  [entrada]  Veículo a liberar.
 * @post    v e os objetos que ele possuía não devem mais ser usados.
 */
void liberaVeiculo(Veiculo *v);

#endif
