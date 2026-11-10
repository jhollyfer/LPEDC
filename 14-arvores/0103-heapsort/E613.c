// 0103 · Heapsort
// Exercício E613 · ★☆☆
//
// As funções troca, mostra e desce já estão prontas. Complete o main para
// rodar a fase 1 do heapsort no vetor [3 9 2 7 5 8] (descer cada pai, do
// último até a raiz), mostrando o vetor depois de cada pai descer, e depois
// só os DOIS primeiros passos da fase 2 (o máximo vai para o fim e o heap
// encolhe uma casa), mostrando o vetor com a barra separando a parte já
// ordenada:
//
//   Saída esperada:
//   pai 2 desceu: [3 9 8 7 5 2]
//   pai 1 desceu: [3 9 8 7 5 2]
//   pai 0 desceu: [9 7 8 3 5 2]
//   fase 2:       [8 7 2 3 5 | 9]
//   fase 2:       [7 5 2 3 | 8 9]
//
// Escreva sua resposta abaixo (complete o main):

#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// mostra v[0..n-1]; a barra aparece antes da posição fim (se fim < n)
void mostra(const int v[], int n, int fim) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf(i == 0 ? "%d" : (i == fim ? " | %d" : " %d"), v[i]);
    }
    printf("]\n");
}

void desce(int v[], int n, int i) {
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && v[f + 1] > v[f]) {
            f++;
        }
        if (v[i] >= v[f]) {
            break;
        }
        troca(&v[i], &v[f]);
        i = f;
    }
}

int main(void) {
    int v[] = {3, 9, 2, 7, 5, 8};
    int n = 6;
    (void)v; // apague estas duas linhas quando escrever o main
    (void)n;

    return 0;
}
