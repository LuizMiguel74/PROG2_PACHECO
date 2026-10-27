#include <stdio.h>
#include <stdlib.h>
#include "eleicao.h"

#include "candidato.h"
#include "eleitor.h"


// #define MAX_CANDIDATOS_POR_CARGO 3
// #define MAX_ELEITORES 10

/*
typedef struct {
    tCandidato** presidentes;
    int totalPresidentes;

    tCandidato** governadores;
    int totalGovernadores;

    int votosBrancosPresidente;
    int votosNulosPresidente;

    int votosBrancosGovernador;
    int votosNulosGovernador;

    tEleitor** eleitores;
    int totalEleitores;
    
} tEleicao;
*/

/**
 * @brief Inicializa uma eleição com valores padrão (zerando as variáveis que armazenam votos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados
 * A memória necessária para os vetores "presidentes", "governadores" deve ser alocada aqui.
 * Demais ponteiros devem ser inicializado com NULL.
 * @return Eleição inicializada.
 */
tEleicao* InicializaEleicao() {
    int qtdPoliticos;
    int qtdGov = 0;
    int qtdPre = 0;
    char cargoRecebido;
    int naoTem;

    tCandidato *aux = NULL;

    scanf("%d", &qtdPoliticos);

    tEleicao *e = (tEleicao *) calloc (1, sizeof(tEleicao));
    e->totalEleitores = 0;
    e->totalGovernadores = 0;
    e->totalPresidentes = 0;
    e->votosBrancosGovernador = 0;
    e->votosBrancosPresidente = 0;
    e->votosNulosGovernador = 0;
    e->votosNulosPresidente = 0;

    e->presidentes = (tCandidato **) calloc (3, sizeof(tCandidato *));
    e->governadores = (tCandidato **) calloc (3, sizeof(tCandidato *));

    e->eleitores = NULL;

    if(qtdPoliticos == 0) {
        return e;
    }


    for(int i = 0 ; i < qtdPoliticos ; i++) {
        aux = CriaCandidato();
        LeCandidato(aux);
        cargoRecebido =  ObtemCargo(aux);
        naoTem = 1;

        if(cargoRecebido == 'P') {
            for(int j = 0 ; j < qtdPre ; j++) {
                if((EhMesmoCandidato(e->presidentes[j], aux))) {
                    naoTem = 0;
                    break;

                } else {
                    naoTem = 1;
                }
            }
            
            if(naoTem) {
                if(qtdPre < 3) {
                    e->presidentes[qtdPre] = aux;
                    qtdPre++;
                } else {
                    ApagaCandidato(aux);
                }
            } else {
                ApagaCandidato(aux);
            }
        }

         if(cargoRecebido == 'G') {
            for(int j = 0 ; j < qtdGov ; j++) {
                if((EhMesmoCandidato(e->governadores[j], aux))) {
                    naoTem = 0;
                    break;

                } else {
                    naoTem = 1;
                }
            }
            
            if(naoTem) {
                if(qtdGov < 3) {
                    e->governadores[qtdGov] = aux;
                    qtdGov++;
                } else {
                    ApagaCandidato(aux);
                }
            } else {
                ApagaCandidato(aux);
            }
        }
    }

    e->totalPresidentes = qtdPre;
    e->totalGovernadores = qtdGov;

    return e;
}


void ApagaEleicao(tEleicao* eleicao) {
    for(int i = 0 ; i < eleicao->totalGovernadores ; i++) {
        ApagaCandidato(eleicao->governadores[i]);
    }
    free(eleicao->governadores);

    for(int i = 0 ; i < eleicao->totalPresidentes ; i++) {
        ApagaCandidato(eleicao->presidentes[i]);
    }
    free(eleicao->presidentes);

    for(int i = 0 ; i < eleicao->totalEleitores ; i++) {
        ApagaEleitor(eleicao->eleitores[i]);
    }
    free(eleicao->eleitores);

    free(eleicao);
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada. 
 */
void RealizaEleicao(tEleicao* eleicao) {
    int qtdEleitores;
    int naoTem = 1;
    int idCandidato;
    int encontrouCandidato;
    int eleicaoAnulada = 0;

    tEleitor *aux = NULL;

    eleicao->eleitores = (tEleitor **) calloc (10, sizeof(tEleitor *));


    scanf("%d", &qtdEleitores);


    if(qtdEleitores > 10) {
        eleicao->eleitores = (tEleitor **) realloc(eleicao->eleitores, 
            qtdEleitores * sizeof(tEleitor *));
    }

    //le e aloca os eleitores
    for(int i = 0 ; i < qtdEleitores ; i++) {
        aux = CriaEleitor();
        LeEleitor(aux);
        naoTem = 1;

        for(int j = 0 ; j < eleicao->totalEleitores ; j++) {
            if(EhMesmoEleitor(eleicao->eleitores[j], aux)) {
                naoTem = 0;
                eleicaoAnulada = 1;
                break;
            }
        }

        if(eleicaoAnulada) {
            printf("ELEICAO ANULADA\n");
            ApagaEleitor(aux);
            ApagaEleicao(eleicao);
            exit(1);
        }

        if(naoTem) {
            if(eleicao->totalEleitores < qtdEleitores) {
                eleicao->eleitores[eleicao->totalEleitores] = aux; 
                eleicao->totalEleitores++;
            } else {
                ApagaEleitor(aux);
            }

        } else {
            ApagaEleitor(aux);
        }
    }
    //FIM
    
    //checagem de votos

    for(int i = 0 ; i < eleicao->totalEleitores ; i++) {
        idCandidato = ObtemVotoGovernador(eleicao->eleitores[i]);

        if(idCandidato == 0) {
            eleicao->votosBrancosGovernador += 1;

        } else {
            encontrouCandidato = 0;

            for(int j = 0 ; j < eleicao->totalGovernadores ; j++) {       
                if(VerificaIdCandidato(eleicao->governadores[j], idCandidato)) {
                    IncrementaVotoCandidato(eleicao->governadores[j]);
                    encontrouCandidato = 1;
                    break;
                }
            }

            if(!(encontrouCandidato)) {
                eleicao->votosNulosGovernador += 1;
            }
        }

        idCandidato = ObtemVotoPresidente(eleicao->eleitores[i]);

        if(idCandidato == 0) {
            eleicao->votosBrancosPresidente += 1;

        } else {
            encontrouCandidato = 0;

            for(int j = 0 ; j < eleicao->totalPresidentes ; j++) {
                if(VerificaIdCandidato(eleicao->presidentes[j], idCandidato)) {
                    IncrementaVotoCandidato(eleicao->presidentes[j]);
                    encontrouCandidato = 1;
                    break;
                }
            }

            if(!(encontrouCandidato)) {
                eleicao->votosNulosPresidente += 1;
            }
        }
        
    }

}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao* eleicao) {
    int totalVotosGov = 0;
    int totalVotosPref = 0;
    int indiceVencedorGov = 0; 
    int indiceVencedorPref = 0; 
    int vencedorPref = eleicao->presidentes[0]->votos;
    int vencedorGov = eleicao->governadores[0]->votos;
    float porcentagemGov;
    float porcentagemPref;
    int temEmpatePref = 0;
    int temEmpateGov = 0;

    //checa prefeito vencedor e acumula os votos de cada um

    for(int i = 0 ; i < eleicao->totalPresidentes ; i++) {
        totalVotosPref += eleicao->presidentes[i]->votos;

        if(vencedorPref < eleicao->presidentes[i]->votos) {
            vencedorPref = eleicao->presidentes[i]->votos;
            indiceVencedorPref = i;
        }
    }

    // checa vendedor governador e acumula os votos de cada um
    for(int i = 0 ; i < eleicao->totalGovernadores ; i++) {
        totalVotosGov += eleicao->governadores[i]->votos;

        if(vencedorGov < eleicao->governadores[i]->votos) {
            vencedorGov = eleicao->governadores[i]->votos;
            indiceVencedorGov = i;
        }

    }

    //checa empates

    for(int i = 0 ; i < eleicao->totalPresidentes ; i++) {
        if(eleicao->presidentes[indiceVencedorPref]->votos == 
            eleicao->presidentes[i]->votos) {
                
                if(indiceVencedorPref != i) {
                    temEmpatePref = 1;
                }
        }
    }


    for(int i = 0 ; i < eleicao->totalGovernadores ; i++) {
        if(eleicao->governadores[indiceVencedorGov]->votos == 
            eleicao->governadores[i]->votos) {
                
                if(indiceVencedorGov != i) {
                    temEmpateGov = 1;
                }
        }
    }

    //fim

    totalVotosGov += eleicao->votosNulosGovernador;
    totalVotosGov += eleicao->votosBrancosGovernador;
    
    totalVotosPref += eleicao->votosBrancosPresidente;
    totalVotosPref += eleicao->votosNulosPresidente;

    porcentagemGov = CalculaPercentualVotos(eleicao->governadores[indiceVencedorGov], totalVotosGov);
    porcentagemPref = CalculaPercentualVotos(eleicao->presidentes[indiceVencedorPref], totalVotosPref);

    
    printf("- PRESIDENTE ELEITO: ");
    if(temEmpatePref) {
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    
    } else if((eleicao->votosBrancosPresidente + eleicao->votosNulosPresidente) > 
    eleicao->presidentes[indiceVencedorPref]->votos) {
        printf("SEM DECISAO\n");

    } else {
        ImprimeCandidato(eleicao->presidentes[indiceVencedorPref], porcentagemPref);
    }
    
    printf("- GOVERNADOR ELEITO: ");
        if(temEmpateGov) {
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");

        } else if((eleicao->votosBrancosGovernador + eleicao->votosNulosGovernador) > 
        eleicao->governadores[indiceVencedorGov]->votos) {
        printf("SEM DECISAO\n");
        
        } else {
            ImprimeCandidato(eleicao->governadores[indiceVencedorGov], porcentagemGov);
        }
    
        printf("- NULOS E BRANCOS: %d, %d", (eleicao->votosNulosGovernador + eleicao->votosNulosPresidente), 
        (eleicao->votosBrancosGovernador + eleicao->votosBrancosPresidente));
    
}
