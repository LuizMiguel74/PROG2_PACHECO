#include <stdio.h>
#define Max 10000

typedef struct {
    int livros[Max];
    int qtd;
} tLivros;

tLivros leLivros() {
    tLivros l;
    int i;

    scanf("%d\n", &l.qtd);

    for(i = 0 ; i < l.qtd ; i++) {
        scanf("%d", &l.livros[i]);
    }

    return l;
}

int verificaSeJaTem(int l1, int l2) {
    return (l1 == l2);
}

tLivros encontraLivrosFaltantes(tLivros l1, tLivros lF) {
    int i, j, k = 0;
    int contagem;
    
    for(i = 0 ; i < l1.qtd ; i++) {
        contagem = 0;

        for(j = 0 ; j < l1.qtd ; j++) {
            if(((verificaSeJaTem(l1.livros[i], l1.livros[j])))) {
                contagem++;
            } 
        }

        if(contagem == 1) {
            lF.livros[k] = l1.livros[i];
            k++;
        }
    }

    lF.qtd = k;
    return lF;
}

int encontraMenor(int n1, int n2) {
    return (n2 < n1);
}

tLivros ordenaLivrosFaltantes(tLivros l) {
    int i, j;
    int auxiliar;

    for(i = 0 ; i < l.qtd ; i++) {
        for(j = i + 1 ; j < l.qtd ; j++) {
            if(encontraMenor(l.livros[i], l.livros[j])) {
                auxiliar = l.livros[i];
                l.livros[i] = l.livros[j];
                l.livros[j] = auxiliar;
            }
        }
    }
    return l;
}

void imprimeLivrosFaltantes(tLivros l) {
    int i;

    if(l.qtd == 0) {
        printf("NENHUM");
    }

    for(i = 0 ; i < l.qtd ; i++) {
        printf("%d ", l.livros[i]);
    }

    printf("\n");
}

int main() {
    tLivros livros, livrosFaltantes;

    livros = leLivros();
    livrosFaltantes = encontraLivrosFaltantes(livros, livrosFaltantes);

    if(livrosFaltantes.qtd > 100) {
        livrosFaltantes = ordenaLivrosFaltantes(livrosFaltantes);
    }

    imprimeLivrosFaltantes(livrosFaltantes);

    return 0;
}