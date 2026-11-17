#include <stdio.h>
#include <stdlib.h>

#include "aluno.h"
#include "vector.h"
#include "relatorio.h"

int main () {
    int qtdAlunos;
    tAluno *aluno;
    Vector *vetor;

    scanf("%d", &qtdAlunos);

    vetor = VectorConstruct();

    for(int i = 0 ; i < qtdAlunos ; i++) {
        aluno = CriaAluno();
        LeAluno(aluno);

        VectorPushBack(vetor, aluno);
    }

    ImprimeRelatorio(vetor);

    VectorDestroy(vetor, DestroiAluno);

    return 0;
}