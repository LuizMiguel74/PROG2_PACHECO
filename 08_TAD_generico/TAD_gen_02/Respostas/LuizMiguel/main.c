#include <stdio.h>
#include <stdlib.h>
#include "gerenciadorpacotes.h"

int main () {
    int escolha, tipoDoPacote, qtdDoPacote, indiceEspecifico;
    tGerenciador *gerenciador;
    tPacote *pacote;

    gerenciador = CriaGerenciador();

    printf("\n");

    do {
        printf("Escolha uma opcao: \n");

        printf("\t(1) Cadastrar um novo pacote\n\t(2) Imprimir um pacote especifico\n\t(3) Imprimir todos os pacotes e sair\n");
        

        scanf("%d", &escolha);

        if(escolha != 1 && escolha != 2 && escolha != 3) {
            printf("Escolha uma opcao valida para o menu!\n");
            continue;
        }

        if(escolha == 1) {
            printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem: \n");

            scanf("%d %d", &tipoDoPacote, &qtdDoPacote);

            if(tipoDoPacote != 0 && tipoDoPacote != 1) {
                printf("Digite um tipo valido!\n");
                continue;
            }

            if(qtdDoPacote <= 0) {
                printf("Digite uma quantidade valida!\n");
                continue;
            }

            pacote = CriaPacote(tipoDoPacote, qtdDoPacote);
            LePacote(pacote);
            AdicionaPacoteNoGerenciador(gerenciador, pacote);
        }

        if(escolha == 2) {
            scanf("%d", &indiceEspecifico);
            ImprimirPacoteNoIndice(gerenciador, indiceEspecifico);
        }

        if(escolha == 3) {
            ImprimirTodosPacotes(gerenciador);
        }

    } while(escolha != 3);

    DestroiGerenciador(gerenciador);

    return 0;
}