#include <stdio.h>
#include <string.h>
#define MAX 1001

/*programa que le rotulo com varios funkos e imprime 
quais podem entrar em promocao
*/

typedef struct {
/*
limite = quantidade minima de funkos para entrar em promocao 
*/
    char rotulo[MAX];
    int quantidadeFunko[100];
    int limite;
} tFunko;

tFunko leFunko() {
    tFunko f;

    scanf("%d %s\n", &f.limite, f.rotulo);

    return f;
}

int jaTemFunko(char a, char b) {
    return (a == b);
}

int verificaSePrimeiroEhMaior(int a, int b) {
    return (a > b);
}

tFunko ordenaFunko(tFunko f) {
/*
ordenacao baseado na tabela ASCII
*/
    int i, j;
    char auxiliar;
    int qtdAuxiliar;

    for(i = 0 ; i != '\0' ; i++) {
        for(j = i + 1 ; j != '\0' ; j++) {

            if(verificaSePrimeiroEhMaior((int)f.rotulo[i], (int)f.rotulo[j])) {
                auxiliar = f.rotulo[i];
                qtdAuxiliar = f.quantidadeFunko[i];
                f.rotulo[i] = f.rotulo[j];
                f.quantidadeFunko[i] = f.quantidadeFunko[j];
                f.rotulo[j] = auxiliar;
                f.quantidadeFunko[j] = qtdAuxiliar;
            }
        }
    }
    return f;
}

int jaTemFunkoAuxiliar(tFunko f, char a) {
/*
verifica se ja tem este funko no vetor auxiliar
*/    
    int i;
    
    /*pura precaucao para a primeira verificacao*/
    if(f.rotulo[0] == '\0') {
        return 0;
    }

    for(i = 0 ; i != '\0' ; i++) {
        if(jaTemFunko(f.rotulo[i], a)) {
            return 1;
        }
    }

    return 0;
}

tFunko encontraFunkosEmPromocao(tFunko f) {
    tFunko funkoAuxiliar;
    int i, j, k = 0;
    int contagem;
    
    funkoAuxiliar.limite = f.limite;
    funkoAuxiliar.rotulo[0] = '\0';

    for(i = 0 ; i != '\0' ; i++) {
        contagem = 0;
        
        for(j = 0 ; j != '\0' ; j++) {
            
            if(!(jaTemFunkoAuxiliar(funkoAuxiliar, f.rotulo[i]))) {
                if(jaTemFunko(f.rotulo[i], f.rotulo[j])) {
                    contagem++;
                }

            } else {
                break;
            }
        }

        if(contagem) {
            if(contagem >= f.limite) {
                funkoAuxiliar.rotulo[k] = f.rotulo[i];
                funkoAuxiliar.quantidadeFunko[k] = f.quantidadeFunko[i]; 
                funkoAuxiliar.rotulo[k + 1] = '\0';
                k++;
            }
        }
    }
    return funkoAuxiliar;
} 

void imprimeFunko(tFunko f) {
    int i;

    for(i = 0 ; i != '\0' ; i++) {
        printf("%c: %d\n", f.rotulo[i], f.quantidadeFunko[i]);
    }

}

int main() {
    tFunko funko;

    funko = leFunko();
    funko = encontraFunkosEmPromocao(funko);
    funko = ordenaFunko(funko);

    imprimeFunko(funko);
    return 0;
}