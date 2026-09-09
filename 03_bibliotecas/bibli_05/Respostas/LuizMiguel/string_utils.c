#include <ctype.h>
#include "string_utils.h"

/**
 * @brief Retorna o tamanho de uma string.
 * @param str A string para obter o tamanho.
 * @return O tamanho da string.
 */
int string_length(char *str) {
    int t = 0;
    int i;

    for(i = 0 ; str[i] != '\0' ; i++) {
        t++;
    }

    return t;
}

/**
 * @brief Copia uma string de origem para destino.
 * @param src A string de origem.
 * @param dest A string de destino.
 */
void string_copy(char *src, char *dest) {
    int i;

    for(i = 0 ; src[i] != '\0' ; i++) {
        dest[i] = src[i];
    }
    dest[i + 1] = '\0';
}

/**
 * @brief Converte todos os caracteres de uma string para maiúsculas.
 * @param str A string para converter.
 */
void string_upper(char *str) {
    int i;

    for(i = 0 ; str[i] != '\0' ; i++) {
        str[i] = toupper(str[i]);
    }
}

/**
 * @brief Converte todos os caracteres de uma string para minúsculas.
 * @param str A string para converter.
 */
void string_lower(char *str) {
    int i;

    for(i = 0 ; str[i] != '\0' ; i++) {
        str[i] = tolower(str[i]);
    }
}

/**
 * @brief Inverte uma string.
 * @param str A string para inverter.
 */
void string_reverse(char *str) {
    int i, j = 0;
    int tamanhoString = 0;
    char auxiliar[100];

    for(i = 0 ; str[i] != '\0' ; i++) {
        tamanhoString++;
    }

    for(i = tamanhoString - 1 ; i >= 0 ; i--) {
        auxiliar[j] = str[i];
        j++;
    }
    auxiliar[j] = '\0';

    string_copy(auxiliar, str);
}

