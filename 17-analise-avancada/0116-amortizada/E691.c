// 0116 · Análise amortizada
// Exercício E691 · ★☆☆
//
// O vetor abaixo começa com capacidade 1 e dobra quando enche. Acrescente
// à struct um campo long copias, que o insere aumenta a cada elemento
// copiado numa mudança. Depois troque o main: para n = 10, 100, 1000 e
// 1000000, crie um vetor novo, insira n números, mostre as cópias e a
// média de cópias por inserção, e libere o vetor:
//
//   Saída esperada:
//         n    cópias  cópias/n
//        10        15      1.50
//       100       127      1.27
//      1000      1023      1.02
//   1000000   1048575      1.05
//
// Dicas:
// 1. Comece cada vetor com Vetor v = {malloc(sizeof(int)), 0, 1, 0};
//    (confira o NULL) e copias = 0.
// 2. As cópias são 1 + 2 + 4 + ... até a última potência de 2 menor que
//    n. Para n = 10: 1 + 2 + 4 + 8 = 15.
// 3. Resposta esperada: a tabela acima. A média nunca passa de 2: é o
//    O(1) amortizado na prática.
//
// Escreva sua resposta abaixo (mude o programa):

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int n, cap;
} Vetor;

void insere(Vetor *v, int valor) {
    if (v->n == v->cap) {
        int nova = v->cap * 2;
        int *maior = malloc(nova * sizeof *maior);
        if (maior == NULL) {
            exit(1);
        }
        for (int i = 0; i < v->n; i++) {
            maior[i] = v->dados[i];
        }
        free(v->dados);
        v->dados = maior;
        v->cap = nova;
    }
    v->dados[v->n++] = valor;
}

int main(void) {
    Vetor v = {malloc(sizeof(int)), 0, 1};
    if (v.dados == NULL) {
        return 1;
    }
    for (int i = 0; i < 10; i++) {
        insere(&v, i);
    }
    printf("n = %d, cap = %d\n", v.n, v.cap);
    free(v.dados);
    return 0;
}
