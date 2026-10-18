// 0103 · Heapsort
// Exercício E613 · ★☆☆
//
// No papel, faça a fase 1 do heapsort (descer cada pai, do último até a
// raiz) no vetor:
//
//   [3 9 2 7 5 8]
//
// Escreva o vetor depois de cada pai descer. Depois faça os dois primeiros
// passos da fase 2. O programa mostra tudo: rode só para conferir.
//
// Dicas:
// 1. Com n = 6, o último pai é o índice n / 2 - 1 = 2. Os pais são 2, 1 e 0.
// 2. Quando o 3 desce da raiz, ele pode descer mais de um nível.
// 3. Resposta esperada: pai 2 → [3 9 8 7 5 2]; pai 1 → igual (9 é maior que
//    7 e 5); pai 0 → [9 7 8 3 5 2]. Fase 2: [8 7 2 3 5 | 9] e
//    [7 5 2 3 | 8 9].
//
// Escreva sua resposta abaixo (como comentário):

#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

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
    for (int i = n / 2 - 1; i >= 0; i--) {
        desce(v, n, i);
        printf("pai %d desceu: ", i);
        mostra(v, n, n);
    }
    for (int fim = n - 1; fim >= n - 2; fim--) {
        troca(&v[0], &v[fim]);
        desce(v, fim, 0);
        printf("fase 2:        ");
        mostra(v, n, fim);
    }
    return 0;
}
