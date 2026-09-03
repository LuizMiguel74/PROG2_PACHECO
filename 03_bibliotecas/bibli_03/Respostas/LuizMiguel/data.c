#include <stdio.h>
#include "data.h"

/**
 * @file data.h
 * @brief Biblioteca para manipulação de datas.
 * 
 * Esta biblioteca contém funções para verificar a validade de uma data, imprimir uma data por extenso,
 * verificar se um ano é bissexto, calcular o número de dias de um mês, comparar duas datas e calcular a
 * diferença em dias entre duas datas.
 * 
 */



/**
 * @brief Verifica se uma data é válida.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 * @return int Retorna 1 se a data é válida e 0 caso contrário.
 */
int verificaDataValida(int dia, int mes, int ano) {
    if(mes == 2) {
        if(verificaBissexto(ano)) {
            if(dia > 29) {
                return 0;
            }

        } else if(dia > 28) {
            return 0;
        }
    }
    
    
    if(dia < 1 || dia > 31) {
        return 0;

    } else if(mes < 1 || mes > 12) {
        return 0;
    } else if(ano < 1) {
        return 0;
    }

    if(mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        if(dia > 30) {
            return 0;
        }
    }

    return 1;
}

/**
 * @brief Imprime o nome do mês por extenso.
 * 
 * @param mes Mês a ser impresso.
 */
void imprimeMesExtenso(int mes) {
    if(mes == 1) {
        printf("Janeiro");
    
    } else if(mes == 2) {
        printf("Fevereiro");
    } else if(mes == 3) {
        printf("Março");
    } else if(mes == 4) {
        printf("Abril");
    } else if(mes == 5) {
        printf("Maio");
    } else if(mes == 6) {
        printf("Junho");
    } else if(mes == 7) {
        printf("Julho");
    } else if(mes == 8) {
        printf("Agosto");
    } else if(mes == 9) {
        printf("Setembro");
    } else if(mes == 10) {
        printf("Outubro");
    } else if(mes == 11) {
        printf("Novembro");
    } else if(mes == 12) {
        printf("Dezembro");
    }
    
}

/**
 * @brief Imprime a data por extenso.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeDataExtenso(int dia, int mes, int ano) {
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %04d\n", ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param ano Ano a ser verificado.
 * @return int Retorna 1 se o ano é bissexto e 0 caso contrário.
 */
int verificaBissexto(int ano) {
    return (ano %400 == 0 || (ano %4 == 0 && ano %100 != 0));
}

/**
 * @brief Calcula o número de dias de um mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias do mês.
 */
int numeroDiasMes(int mes, int ano) {
    if(mes == 2) {
        if(verificaBissexto(ano)) {
            return 29;
        } else {
            return 28;
        }
    }

    if(mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30;
    }
    return 31;
}

/**
 * @brief Compara duas datas.
 * 
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return int Retorna 1 se a primeira data é maior que a segunda, -1 se a primeira data é menor que a segunda
 * e 0 se as datas são iguais.
 * A data ser "maior" significa que ela está mais no futuro.
 */
int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
    if(ano1 > ano2) {
        return 1;
    }
    if(ano2 > ano1) {
        return -1;
    }
    if(mes1 > mes2) {
        return 1;
    }
    if(mes2 > mes1) {
        return -1;
    }
    if(dia1 > dia2) {
        return 1;
    }
    if(dia2 > dia1) {
        return -1;
    }
    
    return 0;
}


/**
 * @brief Calcula o número de dias até o mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias até o mês.
*/
int calculaDiasAteMes(int mes, int ano) {
    int soma = 0, i;

    for(i = 1 ; i < mes ; i++) {
        soma += numeroDiasMes(i, ano);
    }

    return soma;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return int Retorna o número de dias de diferença entre as datas.
 */
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
    int soma = 0, auxiliar;

    if((comparaData(dia1, mes1, ano1, dia2, mes2, ano2)) == 1) {
        auxiliar = dia1;
        dia1 = dia2;
        dia2 = auxiliar;

        auxiliar = mes1;
        mes1 = mes2;
        mes2 = auxiliar;

        auxiliar = ano1;
        ano1 = ano2;
        ano2 = auxiliar;
    }

    while(1) {
        if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == -1) {
            soma += 1;

            if(verificaDataValida(dia1 + 1, mes1, ano1)) {
                dia1 += 1;
            } else {
                dia1 = 1;
                if(verificaDataValida(dia1, mes1 + 1, ano1)) {
                    mes1++;
                } else {
                    mes1 = 1;
                    ano1++;
                }
            }

        } else {
            break;
        }
    }
    
    return soma;
}

