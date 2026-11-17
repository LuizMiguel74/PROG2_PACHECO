#include <stdio.h>
#include <stdlib.h>

#include "agencia.h"
#include "conta.h"
#include "banco.h"
#include "vector.h"

int main () {
    char escolha = 'a';
    tBanco *banco;
    tAgencia *agencia;
    tConta *conta;
    int agenciaDaConta;

    banco = CriaBanco();
    LeBanco(banco);
    
    while(1) {
        if(escolha == 'F') {
            break;
        }

        scanf("%c", &escolha);

        if(escolha == 'A') {
            agencia = CriaAgencia();
            LeAgencia(agencia);
            AdicionaAgencia(banco, agencia);
        
        } else if(escolha == 'C') {
            conta = CriaConta();
            LeConta(conta);
            scanf("%d", &agenciaDaConta);
            InsereContaBanco(banco, agenciaDaConta, conta);
        }
    }

    ImprimeRelatorioBanco(banco);
    
    DestroiBanco(banco);
    return 0;
}