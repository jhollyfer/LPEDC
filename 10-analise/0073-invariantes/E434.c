// 0073 · Invariantes de laço e corretude
// Exercício E434 · ★☆☆
//
// As vendas da barraca na feira foram R$ 35, 12, 50, 8 e 27. Complete a
// função soma():
//
// 1. escreva o laço que soma v[0..n-1];
// 2. escreva o invariante como comentário dentro do laço;
// 3. confira o invariante com assert, usando a função soma_ate(), que já
// está pronta (ela recalcula a soma de v[0..i-1] do jeito lento).
//
//   Saída esperada:
//   Total: R$ 132
//
// Dicas:
// 1. Comece com s = 0 e i = 0. O assert vai logo no começo do corpo do laço.
// 2. assert(s == soma_ate(v, i));
// 3. Depois do laço, um último assert(s == soma_ate(v, n)) fecha o término.
// 4. Resposta esperada: Total: R$ 132. Invariante: s é a soma de v[0..i-1].
//
// Escreva sua resposta abaixo (complete a função soma):

#include <assert.h>
#include <stdio.h>

// Devolve a soma de v[0..i-1], recalculando tudo (só para conferir).
int soma_ate(const int v[], int i) {
    int s = 0;
    for (int k = 0; k < i; k++) {
        s += v[k];
    }
    return s;
}

// Recebe n >= 0 e v; devolve a soma de v[0..n-1].
int soma(const int v[], int n) {
    int s = 0;
    // TODO: o laço, o comentário do invariante e o assert
    (void)v;
    (void)n;
    return s;
}

int main(void) {
    int vendas[5] = {35, 12, 50, 8, 27};

    printf("Total: R$ %d\n", soma(vendas, 5));
    return 0;
}
