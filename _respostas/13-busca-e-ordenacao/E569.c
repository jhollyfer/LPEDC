// 0095 · Busca binária
// Exercício E569 · ★★★
//
// Resposta: com size_t (sem sinal), quando meio vale 0 e a chave é menor que
// v[0], fim = meio - 1 não vira -1: dá a volta para SIZE_MAX (um número
// enorme). A condição ini <= fim continua verdadeira, o próximo meio é
// gigante e v[meio] lê longe do vetor (o ASan acusa). O mesmo acontece com
// n = 0, em fim = n - 1. Conserto: intervalo semiaberto [ini, fim), que
// nunca subtrai 1 de um size_t (ou usar int com sinal).

#include <stdio.h>
#include <stddef.h>

int busca(const int v[], size_t n, int x) {
    size_t ini = 0, fim = n;          // semiaberto: fim fica uma depois
    while (ini < fim) {
        size_t meio = ini + (fim - ini) / 2;
        if (v[meio] == x) {
            return (int) meio;
        }
        if (v[meio] < x) {
            ini = meio + 1;
        } else {
            fim = meio;               // sem "- 1": nunca dá a volta
        }
    }
    return -1;
}

int main(void) {
    int tempos[] = {10, 20, 28, 35, 41, 57, 63};
    size_t n = sizeof tempos / sizeof tempos[0];

    printf("35: posição %d\n", busca(tempos, n, 35));
    printf("3: posição %d\n", busca(tempos, n, 3));
    printf("vazio: posição %d\n", busca(tempos, 0, 35));
    return 0;
}
