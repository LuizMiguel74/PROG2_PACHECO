#include <stdio.h>
#include <stdlib.h>
#include "datahora.h"


struct DataHora {
    int dia, mes, ano;
    int hora, minuto;
};


/**
 * @brief   Cria uma data/hora a partir dos valores informados.
 *
 * @param dia     [entrada]  Dia do mês, inteiro em [1, 31] (válido para o mês/ano).
 * @param mes     [entrada]  Mês, inteiro em [1, 12].
 * @param ano     [entrada]  Ano com 4 dígitos (ex.: 2026), inteiro >= 1.
 * @param hora    [entrada]  Hora do dia, inteiro em [0, 23].
 * @param minuto  [entrada]  Minuto, inteiro em [0, 59].
 *
 * @return  Ponteiro para o DataHora criado (alocado dinamicamente);
 *          NULL se a alocação de memória falhar.
 *
 * @pre     Os valores formam uma data/hora válida (a função NÃO valida).
 * @post    O chamador é dono do DataHora retornado e deve liberá-lo com
 *          liberaDataHora() (ou transferir a posse para outro TAD que o libere).
 */
DataHora *criaDataHora(int dia, int mes, int ano, int hora, int minuto) {
    DataHora *dt = (DataHora *) calloc (1, sizeof(DataHora));

    if(dt == NULL) {
        printf("ERRO\nalocacao (dataHora)");
    }

        dt->dia = dia;
        dt->mes = mes;
        dt->ano = ano;
        dt->hora = hora;
        dt->minuto = minuto;
   
    
    return dt;
}

/**
 * @brief   Lê uma data/hora da entrada padrão e cria o DataHora correspondente.
 *
 * Lê UMA linha no formato "DD/MM/AAAA HH:MM" (data, um espaço, horário), por
 * exemplo "27/10/2026 08:05", consumindo também a quebra de linha final.
 *
 * @return  Ponteiro para o DataHora lido (mesmas regras de posse de criaDataHora()).
 *
 * @pre     A próxima linha da entrada padrão contém uma data/hora válida no formato
 *          acima.
 */
DataHora *lerDataHora() {
    int dia, mes, ano;
    int hora, minuto;
    
    DataHora *dt = NULL;

    scanf("%02d/%02d/%04d %02d:%02d", &dia, &mes, &ano, &hora, &minuto);

    dt = criaDataHora(dia, mes, ano, hora, minuto);

    return dt;
}

/**
 * @brief   Calcula quantos minutos se passaram entre duas datas/horas.
 *
 * O cálculo considera o calendário real:
 *   - meses com 31 dias: 1, 3, 5, 7, 8, 10, 12; com 30 dias: 4, 6, 9, 11;
 *   - fevereiro tem 29 dias em ano bissexto e 28 nos demais;
 *   - um ano é bissexto se for divisível por 400, ou se for divisível por 4 e NÃO
 *     for divisível por 100 (ex.: 2028 e 2000 são bissextos; 2026 e 2100 não são);
 *   - cada dia tem 24 * 60 = 1440 minutos.
 * Exemplos:
 *   inicio = 27/10/2026 08:50, fim = 27/10/2026 10:05  ->  75
 *   inicio = 27/10/2026 23:30, fim = 28/10/2026 00:10  ->  40
 *   inicio = 28/02/2028 12:00, fim = 01/03/2028 12:00  ->  2880 (2028 é bissexto)
 *
 * @param inicio  [entrada]  Data/hora inicial (não-nula).
 * @param fim     [entrada]  Data/hora final (não-nula).
 *
 * @return  Diferença em minutos (fim - inicio). É >= 0 sempre que fim não for
 *          anterior a inicio.
 *
 * @pre     inicio != NULL e fim != NULL.
 * @note    Nenhuma das duas datas/horas é modificada ou liberada.
 */
int diferencaMinutosDataHora(DataHora *inicio, DataHora *fim) {
    int diferencaTotalMinutos = 0;
    int diferencaDias = 0;

   diferencaDias = diferencaTotalDias(inicio, fim);

   diferencaTotalMinutos = (diferencaDias * 1440) + ((fim->hora * 60) + fim->minuto) -
   ((inicio->hora * 60) + inicio->minuto);
   
   diferencaTotalMinutos = abs(diferencaTotalMinutos);


    return diferencaTotalMinutos;

}

/**
 * @brief   Imprime a data/hora na saída padrão no formato "DD/MM/AAAA HH:MM".
 *
 * Dia, mês, hora e minuto são impressos SEMPRE com dois dígitos e o ano com quatro
 * (zeros à esquerda quando necessário). Ex.: "05/03/2027 08:05". Há exatamente um
 * espaço entre a data e o horário. NÃO imprime quebra de linha nem espaços
 * antes/depois.
 *
 * @param dh  [entrada]  Data/hora a imprimir (não-nula).
 * @pre     dh != NULL.
 */
void imprimeDataHora(DataHora *dh) {
    printf("%02d/%02d/%04d %02d:%02d", dh->dia, dh->mes, dh->ano, dh->hora, dh->minuto);
}

/**
 * @brief   Libera a memória alocada para uma data/hora.
 *
 * @param dh  [entrada]  Data/hora a liberar.
 * @post    A memória apontada por dh é liberada; o ponteiro não deve mais ser usado.
 */
void liberaDataHora(DataHora *dh) {
    free(dh);
}


int verificaDataValida(int dia, int mes, int ano) {
    int diasMes;
    
    if(ano > 0) {
        if(mes > 0 && mes < 13) {
            diasMes = quantosDiasNoMes(mes, ano);
            
            if(dia > 0 && dia <= diasMes) {
                return 1;
            }
        }
    }

    return 0;
}

int verificaAnoBissexto(int ano) {
    return (ano % 400 == 0 || ano %4 == 0 && ano %100 != 0) ;
}

int quantosDiasNoMes(int mes, int ano) {
    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
        return 31;
    }

    if(verificaAnoBissexto(ano)) {
        if(mes == 2) {
            return 29;
        }
    }

    if(mes == 2) {
        return 28;
    }

    return 30;
}

int primeiraDataEhMenor(DataHora *dt1, DataHora *dt2) {
    if(dt1->ano < dt2->ano) {
        return 1;
    }
    if(dt1->mes < dt2->mes) {
        return 1;
    }
    if(dt1->dia < dt2->dia) {
        return 1;
    }
    return 0;
}

int diferencaTotalDias(DataHora *dt1, DataHora *dt2) {
    DataHora *aux = (DataHora *) calloc (1, sizeof(DataHora));
    
    aux->ano = dt1->ano;
    aux->dia = dt1->dia;
    aux->mes = dt1->mes;

    int totalDiferencaDias = 0;

    while(1) {
        if(primeiraDataEhMenor(aux, dt2)) {
            totalDiferencaDias += 1;

            if(verificaDataValida(aux->dia + 1, aux->mes, aux->ano)) {
                aux->dia += 1;
            } else {
                aux->dia = 1;
                
                if(verificaDataValida(aux->dia, aux->mes + 1, aux->ano)) {
                    aux->dia = 1;
                    aux->mes += 1;
                } else {
                    aux->mes = 1;
                    aux->ano += 1;
                }
            }
        } else {
            break;
        }
    }

    liberaDataHora(aux);
    return totalDiferencaDias;
}