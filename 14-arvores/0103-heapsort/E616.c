// 0103 · Heapsort
// Exercício E616 · ★★☆
//
// SEM RODAR, preveja a saída. O heapsort recebe um vetor que JÁ está em
// ordem crescente. A fase 1 mexe nele? O programa mostra o vetor depois da
// fase 1 e quantas trocas cada fase fez.
//
// Dicas:
// 1. Pais: índices 2, 1 e 0. O 3 (índice 2) tem filhos 6 e 7.
// 2. Um vetor crescente é o "contrário" de um heap: a fase 1 trabalha muito.
//    E a fase 2 não tem moleza: o heapsort não percebe que o vetor estava
//    em ordem.
// 3. Resposta esperada:
//    depois da fase 1: 7 5 6 4 2 1 3
//    trocas na fase 1: 4
//    trocas na fase 2: 6
//    ordenado: 1 2 3 4 5 6 7
//
// Escreva sua resposta abaixo (a saída, como comentário):

#include <stdio.h>

int trocas = 0;

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
    trocas++;
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

void mostra(const char *rotulo, const int v[], int n) {
    printf("%s:", rotulo);
    for (int i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
    printf("\n");
}

int main(void) {
    int v[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    for (int i = n / 2 - 1; i >= 0; i--) {
        desce(v, n, i);
    }
    mostra("depois da fase 1", v, n);
    printf("trocas na fase 1: %d\n", trocas);

    trocas = 0;
    for (int fim = n - 1; fim > 0; fim--) {
        int t = v[0]; // troca sem contar: só as trocas do desce entram
        v[0] = v[fim];
        v[fim] = t;
        desce(v, fim, 0);
    }
    printf("trocas na fase 2: %d\n", trocas);
    mostra("ordenado", v, n);
    return 0;
}
