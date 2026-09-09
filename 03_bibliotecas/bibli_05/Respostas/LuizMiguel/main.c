#include <stdio.h>
#include "string_utils.h"
#define MAX 100

void leString(char *string) {
    int i = 0;

    while(1) {
        if(scanf("%c", &string[i]) == 1) {
            if(string[i] == '\n') {
                break;
            }
            i++; 

        } else {
            break;
        }
    }
    
    string[i] = '\0';
}

int main() {
    int escolha;
    int tamanhoString;
    char string[MAX];
    char stringNumero2[MAX];

    leString(string);

    do {
        printf("1 - Tamanho da string\n2 - Copiar string\n");
        printf("3 - Converter string para letras maiusculas\n4 - Converter string para letras minusculas\n");
        printf("5 - Imprimir string ao contrario\n6 - Encerrar o programa\n");
        printf("Opcao escolhida:\n");

        scanf("%d", &escolha);

        if(escolha == 1) {
            tamanhoString = string_length(string);
            printf("Tamanho da string: %02d\n\n", tamanhoString);
        }
        if(escolha == 2) {
            string_copy(string, stringNumero2);
            printf("String copiada: %s\n\n", stringNumero2);
        }
        if(escolha == 3) {
            string_upper(string);
            printf("String convertida para maiusculas: %s\n\n", string);
        }
        if(escolha == 4) {
            string_lower(string);
            printf("String convertida para minusculas: %s\n\n", string);
        }
        if(escolha == 5) {
            string_reverse(string);
            printf("String invertida: %s\n\n", string);
        }
        
    } while(escolha != 6);

    return 0;
}