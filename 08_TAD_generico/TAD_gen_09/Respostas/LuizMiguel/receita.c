#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "receita.h"

#define MAX_MEDICO 100  
#define MAX_PACIENTE 100
#define MAX_MEDICAMENTO 100
#define MAX_INTRUCOES 200

/*
    Estrutura do tipo Receita contendo os atributos necessários para a manipulação
*/

struct _Receita {
    char* nomeMedico;
    char* nomePaciente;
    char* nomeMedicamento;
    char* instrucoes; 
};


/*
    Função que cria uma receita e retorna o seu endereço de memória
    @param nomeMedicamento: nome do medicamento prescrito na receita
    @param nomePaciente: nome do paciente para quem a receita foi prescrita
    @param nomeMedico: nome do médico que prescreveu a receita
    @param instrucoes: instruções para o uso do medicamento
    @return: endereço de memória da receita criada
*/
Receita *criaReceita(char *nomeMedicamento, char *nomePaciente, char *nomeMedico, char *instrucoes) {
    Receita* r = (Receita *) calloc (1, sizeof(Receita));

    if(r == NULL) {
        printf("ERRO\nalocacao(receita)");
    }

    r->instrucoes = (char *) calloc (MAX_INTRUCOES, sizeof(char));
    r->nomeMedicamento = (char *) calloc (MAX_MEDICAMENTO, sizeof(char));
    r->nomeMedico = (char *) calloc (MAX_MEDICO, sizeof(char));
    r->nomePaciente = (char *) calloc (MAX_PACIENTE, sizeof(char));


    strcpy(r->instrucoes, instrucoes);
    strcpy(r->nomeMedicamento, nomeMedicamento);
    strcpy(r->nomeMedico, nomeMedico);
    strcpy(r->nomePaciente, nomePaciente);

    return r;
}

/*
    Função que lê os dados de uma receita a partir da entrada padrão de acordo com a especificação
    @return: endereço de memória da receita lida
*/
Receita *leReceita() {
    Receita* r;

    char instrucoes[MAX_INTRUCOES], medicamento[MAX_MEDICAMENTO]; 
    char medico[MAX_MEDICO], paciente[MAX_PACIENTE]; 

    scanf("%[^\n]\n", medico);
    scanf("%[^\n]\n", paciente);
    scanf("%[^\n]\n", medicamento);
    scanf("%[^\n]\n", instrucoes);

    r = criaReceita(medicamento, paciente, medico, instrucoes);

    return r;
}

/*
    Função que calcula o preço de impressão de uma receita de acordo com a especificação
    @param dado: ponteiro genérico para a receita a ser calculada
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço de impressão da receita
*/
float calculaPrecoImpressaoReceita(void *dado, float precoCaractere) {
    int totalCaracteres = 0;

    totalCaracteres += strlen(((Receita *)dado)->instrucoes);
    totalCaracteres += strlen(((Receita *)dado)->nomeMedicamento);
    totalCaracteres += strlen(((Receita *)dado)->nomeMedico);
    totalCaracteres += strlen(((Receita *)dado)->nomePaciente);

   return ((float)totalCaracteres * precoCaractere);
}

/*
    Função que imprime uma receita de acordo com a especificação (veja os casos de teste)
    @param dado: ponteiro genérico para a receita a ser impressa
*/
void imprimeReceita(void *dado) {
    printf("- - RECEITA - -\n");

    printf("MEDICAMENTO: %s\n", ((Receita *)dado)->nomeMedicamento);
    printf("PACIENTE: %s\n", ((Receita *)dado)->nomePaciente);
    printf("INSTRUCOES: %s\n", ((Receita *)dado)->instrucoes);
    printf("MEDICO: %s\n", ((Receita *)dado)->nomeMedico);

    printf("- - - - - - - -\n");
}

/*
    Função que desaloca uma receita
    @param dado: ponteiro genérico para a receita a ser desalocada
*/
void desalocaReceita(void *dado) {
    free(((Receita *)dado)->instrucoes);
    free(((Receita *)dado)->nomeMedicamento);
    free(((Receita *)dado)->nomeMedico);
    free(((Receita *)dado)->nomePaciente);
    
    free(dado);
}

