// Lista · Módulo 11 · Listas
// Exercício P1130 · ★★★ · Somar matrizes esparsas
//
// A planilha de estoque de 3 lojas x 5 produtos tem quase tudo zero. Uma
// MATRIZ ESPARSA guarda só o que não é zero: cada linha é uma lista
// encadeada de nós {coluna, valor}, em ordem crescente de coluna. Escreva:
//
//   No *insere(No *linha, int coluna, int valor)   // em ordem de coluna
//   No *soma_linhas(const No *a, const No *b)
//     cria uma lista nova com a soma, intercalando as duas linhas por
//     coluna e DESCARTANDO os resultados que derem zero;
//   void mostra_densa(No *m[], int linhas, int colunas)  // com os zeros
//
// Monte A e B pelos termos (linha, coluna, valor) e mostre A + B na forma
// densa (cada número com "%3d") e quantos não nulos ela guarda.
//
//   A: (0,1,5) (0,4,2) (1,0,3) (2,2,-4) (2,3,1)
//   B: (0,1,-5) (0,2,7) (1,0,1) (1,4,9) (2,3,2)
//
//   Saída esperada:
//     0  0  7  0  2
//     4  0  0  0  9
//     0  0 -4  3  0
//   Não nulos: 6 de 15
//
// Dicas:
// 1. A matriz é um vetor de 3 ponteiros No *, um por linha, começando NULL.
// 2. soma_linhas é a intercalação de duas listas ordenadas: coluna menor
//    entra sozinha; colunas iguais somam (e, se der 0, nada entra, como o
//    5 + (-5) da linha 0). Use um ponteiro para o fim da lista nova.
// 3. A soma custa O(não nulos de A + não nulos de B), não O(linhas x
//    colunas): é para isso que a matriz esparsa existe.
// 4. Resposta esperada: a saída acima. Libere as três matrizes.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int coluna;
    int valor;
    struct no *prox;
} No;

int main(void) {

    return 0;
}
