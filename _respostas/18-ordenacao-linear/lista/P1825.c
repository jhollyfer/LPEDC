// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1825 · ★★★ · Counting sort sem vetor de saída: as camisas no lugar

#include <stdbool.h>
#include <stdio.h>

#define N 12
#define K 5

typedef struct {
    int codigo, tam; // tam: 0 P, 1 M, 2 G, 3 GG, 4 XG
} Camisa;

const char *tamanhos[K] = {"P", "M", "G", "GG", "XG"};
int trocas;

void ordena_no_lugar(Camisa v[], int n) {
    int c[K] = {0}, prox[K], fim[K];
    for (int i = 0; i < n; i++) c[v[i].tam]++;
    for (int k = 0; k < K; k++) {
        prox[k] = k ? fim[k - 1] : 0; // o bloco k começa onde o anterior termina
        fim[k] = prox[k] + c[k];
    }
    for (int k = 0; k < K; k++)
        while (prox[k] < fim[k]) {
            int t = v[prox[k]].tam;
            if (t == k) {
                prox[k]++; // já está no bloco certo
            } else {
                Camisa tmp = v[prox[k]]; // manda para a próxima vaga do bloco t
                v[prox[k]] = v[prox[t]];
                v[prox[t]] = tmp;
                prox[t]++;
                trocas++;
            }
        }
}

void mostra(const char *rotulo, const Camisa v[], int n) {
    printf("%-7s", rotulo);
    for (int i = 0; i < n; i++) printf(" %s(%d)", tamanhos[v[i].tam], v[i].codigo % 100);
    printf("\n");
}

int main(void) {
    Camisa v[N] = {{101, 2}, {102, 4}, {103, 0}, {104, 2}, {105, 1}, {106, 3},
                   {107, 1}, {108, 0}, {109, 4}, {110, 2}, {111, 3}, {112, 1}};

    mostra("antes:", v, N);
    ordena_no_lugar(v, N);
    mostra("depois:", v, N);
    bool estavel = true;
    for (int i = 0; i + 1 < N; i++)
        if (v[i].tam == v[i + 1].tam && v[i].codigo > v[i + 1].codigo) estavel = false;
    printf("Trocas: %d (n = %d) | estável: %s\n", trocas, N, estavel ? "sim" : "não");
    return 0;
}
