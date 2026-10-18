// 0108 · Juntando tudo: o contador de palavras
// Exercício E646 · ★★☆
//
// A tabela já contou as palavras da lista da feira e entregou o vetor
// abaixo, fora de ordem. Complete a função compara para o qsort deixar o
// ranking com mais vezes primeiro e, no empate, em ordem alfabética.
//
//   Saída esperada:
//   banana 5
//   ovo 5
//   alface 3
//   caqui 3
//   feira 3
//   queijo 1
//
// Dicas:
// 1. compara recebe dois const void *: converta para const Contagem *.
// 2. Devolva um número negativo se a deve vir antes de b. Para "mais vezes
//    primeiro", a conta é y->vezes - x->vezes; no empate, use strcmp.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    const char *palavra;
    int vezes;
} Contagem;

int compara(const void *a, const void *b) {
    (void)a; // apague estas duas linhas
    (void)b; // quando usar os parâmetros

    // complete aqui

    return 0;
}

int main(void) {
    Contagem lista[] = {{"feira", 3}, {"banana", 5}, {"alface", 3},
                        {"ovo", 5},   {"queijo", 1}, {"caqui", 3}};
    int n = (int)(sizeof lista / sizeof lista[0]);

    qsort(lista, (size_t)n, sizeof lista[0], compara);
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", lista[i].palavra, lista[i].vezes);
    }
    return 0;
}
