#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fila_imp.h"
#include "documento.h"

/*
    Estrutura do tipo FilaImp contendo os atributos necessários para a manipulação
*/

struct _FilaImp {
    int qtdDocumentos;
    Documento ** vetor;
};


/*
    Função que cria uma fila de impressão e retorna o seu endereço de memória
    @return: endereço de memória da fila de impressão criada
*/
FilaImp *criaFilaImp() {
    FilaImp* f = (FilaImp *) calloc (1, sizeof(FilaImp));

    if(f == NULL) {
        printf("ERRO\nalocacao(fila)");
        exit(1);
    }

    return f;
}

/*
    Função que desaloca uma fila de impressão
    @param f: ponteiro para a fila de impressão a ser desalocada
*/
void desalocaFilaImp(FilaImp *f) {
    for(int i = 0 ; i < f->qtdDocumentos ; i++) {
        desalocaDocumento(f->vetor[i]);
    }

    free(f->vetor);
    free(f);
}

/*
    Função que insere um documento na fila de impressão de acordo com a especificação
    @param f: ponteiro para a fila de impressão onde o documento será inserido
    @param dado: ponteiro genérico para o dado do documento a ser inserido
    @param imprime: ponteiro para a função de impressão do dado do documento genérico
    @param desaloca: ponteiro para a função de desalocação do dado do documento genérico
    @param calculaPreco: ponteiro para a função de cálculo do preço do dado do documento genérico
*/
void insereDocumentoFilaImp(FilaImp *f, void *dado, func_ptr_imprime imprime,
                            func_ptr_desaloca desaloca, func_ptr_calculaPreco calculaPreco) {

                                Documento *d = criaDocumento(dado, imprime, desaloca, calculaPreco);

                                f->qtdDocumentos += 1;
                                
                                f->vetor = (Documento **) realloc (f->vetor ,f->qtdDocumentos * sizeof(Documento *));

                                f->vetor[f->qtdDocumentos - 1] = d;
                            }

/*
    Função que retorna a quantidade de documentos na fila de impressão
    @param f: ponteiro para a fila de impressão
    @return: quantidade de documentos na fila de impressão
*/
int quantidadeDocumentosNaFilaImp(FilaImp *f) {
    return f->qtdDocumentos;
}

/*
    Função que calcula o preço total de impressão de todos os documentos na fila de impressão
    @param f: ponteiro para a fila de impressão
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço total de impressão da fila
*/
float precoTotalImpressaoFilaImp(FilaImp *f, float precoCaractere) {
    float precoTotal = 0;

    for(int i = 0 ; i < f->qtdDocumentos ; i++) {
        precoTotal += (calculaPrecoImpressaoDocumento(f->vetor[i], precoCaractere));
    }
    return precoTotal;
}

/*
    Função que imprime toda a fila de impressão
    Obviamente, se não houver elementos na fila, a função não deve fazer nada.
    @param f: ponteiro para a fila de impressão
*/
void imprimeFilaImp(FilaImp *f) {
    for(int i = 0 ; i < f->qtdDocumentos ; i++) {
        imprimeDocumento(f->vetor[i]);
    }
}
