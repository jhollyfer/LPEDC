// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1905 · ★☆☆ · Os sócios que sumiram da mesa
//
// Este programa tem um erro de propósito. Ana, Bia e Caio vão sentar lado a
// lado na mesa do bar, e o programa devia mostrar as 3! = 6 ordens, gerando
// as permutações por trocas. Ele compila sem aviso e roda limpo, mas não
// mostra ordem nenhuma: "0 ordens". Conserte a linha errada.
//
//   Saída esperada:
//   Ana Bia Caio
//   Ana Caio Bia
//   Bia Ana Caio
//   Bia Caio Ana
//   Caio Bia Ana
//   Caio Ana Bia
//   6 ordens
//
// Dicas:
// 1. Na posição k, quem pode sentar? Todos os que ainda não sentaram:
//    v[k], v[k + 1], ..., v[n - 1]. Incluindo o próprio v[k].
// 2. O laço começa em k + 1, e aí v[k] nunca fica na posição k. Troque
//    v[k] com ele mesmo também: o laço começa em k.
// 3. Resposta esperada: for (int i = k; i < N; i++). As 6 ordens saem
//    na ordem de cima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define N 3

const char *v[N] = {"Ana", "Bia", "Caio"};
int total = 0;

void troca(int a, int b) {
    const char *t = v[a];
    v[a] = v[b];
    v[b] = t;
}

void permuta(int k) {
    if (k == N) {
        total++;
        printf("%s %s %s\n", v[0], v[1], v[2]);
        return;
    }
    for (int i = k + 1; i < N; i++) {
        troca(k, i);
        permuta(k + 1);
        troca(k, i);
    }
}

int main(void) {
    permuta(0);
    printf("%d ordens\n", total);
    return 0;
}
