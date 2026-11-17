#include <stdio.h>
#include <stdlib.h>

#include "relatorio.h"
#include "aluno.h"
#include "vector.h"

/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 * 
 * @param alunos Ponteiro para o vetor de alunos.
*/
void ImprimeRelatorio(Vector *alunos) {
    float porcentagemHomens = 0, porcentagemMulheres = 0, porcentagemOutros = 0;
    float porcetangemAprovados = 0;
    float media = 0;

    for(int i = 0 ; i < VectorSize(alunos) ; i++) {
        media += GetNotaAluno(VectorGet(alunos, i));
        
        if(GetGeneroAluno(VectorGet(alunos, i)) == 'O') {
            porcentagemOutros += 1;
        } else if(GetGeneroAluno(VectorGet(alunos, i)) == 'F') {
            porcentagemMulheres += 1;
        } else if(GetGeneroAluno(VectorGet(alunos, i)) == 'M') {
            porcentagemHomens += 1;
        }

        if(GetNotaAluno(VectorGet(alunos, i)) >= 6) {
            porcetangemAprovados += 1;
        }

    }

    media = media / VectorSize(alunos);
    porcentagemHomens = (porcentagemHomens * 100.0) / VectorSize(alunos);
    porcentagemMulheres = (porcentagemMulheres * 100.0) / VectorSize(alunos);
    porcentagemOutros = (porcentagemOutros * 100.0) / VectorSize(alunos);
    porcetangemAprovados = (porcetangemAprovados * 100.0) / VectorSize(alunos);

    printf("Media das notas: %.2f\n", media);
    printf("Porcentagem de alunos aprovados: %.2f%%\n", porcetangemAprovados);
    
    printf("Porcentagem de cada genero:\n");

    printf("Masculino: %.2f%%\n", porcentagemHomens);
    printf("Feminino: %.2f%%\n", porcentagemMulheres);
    printf("Outro: %.2f%%", porcentagemOutros);
}

