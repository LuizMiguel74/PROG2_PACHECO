#include <stdio.h>
#include "tDepartamento.h"

#define STRING_MAX 50

void leDepartamentos(char *nome, char * diretor, char * curso1, char * curso2, 
    char * curso3, int * nota, int * nota2, int * nota3) {
    
    scanf(" %49[^\n]", nome);
    scanf(" %49[^\n]", diretor);
    scanf(" %49[^\n]", curso1);
    scanf(" %49[^\n]", curso2);
    scanf(" %49[^\n]", curso3);
    scanf(" %d %d %d", nota, nota2, nota3);
}

int main () {
    int qtdDepartamentos;
    scanf("%d ", &qtdDepartamentos);
    tDepartamento departamentos[qtdDepartamentos];

    for(int i = 0 ; i < qtdDepartamentos ; i++) {
        char nome[STRING_MAX], diretor[STRING_MAX], curso1[STRING_MAX], curso2[STRING_MAX],
        curso3[STRING_MAX];
        int notaC1, notaC2, notaC3;

        leDepartamentos(nome, diretor, curso1, curso2, curso3, &notaC1, &notaC2, &notaC3);

        departamentos[i] = CriaDepartamento(curso1, curso2, curso3, nome, notaC1, notaC2,
        notaC3, diretor);
        
        //caso os valores de notas invalidos
        if(notaC1 < 0 || notaC2 < 0 || notaC3 < 0) {
            leDepartamentos(nome, diretor, curso1, curso2, curso3, &notaC1, &notaC2, &notaC3);
            departamentos[i] = CriaDepartamento(curso1, curso2, curso3, nome, notaC1, notaC2,
                notaC3, diretor);
        }
    }

    OrdenaDepartamentosPorMedia(departamentos, qtdDepartamentos);

    for(int i = 0; i < qtdDepartamentos ; i++) {
        ImprimeAtributosDepartamento(departamentos[i]);
    }

    return 0;
}