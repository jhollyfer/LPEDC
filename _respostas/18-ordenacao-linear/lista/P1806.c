// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1806 · ★☆☆ · De trás para frente ou da frente para trás?

#include <stdbool.h>
#include <stdio.h>

#define N 8
#define K 4

typedef struct {
    const char *nome;
    int cat;
    int ordem; // ordem de inscrição
} Inscricao;

void counting(const Inscricao v[], Inscricao saida[], int n, bool de_tras) {
    int c[K] = {0};
    for (int i = 0; i < n; i++) c[v[i].cat]++;
    for (int x = 1; x < K; x++) c[x] += c[x - 1];
    for (int t = 0; t < n; t++) {
        int i = de_tras ? n - 1 - t : t;
        saida[--c[v[i].cat]] = v[i]; // a última vaga livre do bloco
    }
}

bool estavel(const Inscricao s[], int n) {
    for (int i = 0; i + 1 < n; i++)
        if (s[i].cat == s[i + 1].cat && s[i].ordem > s[i + 1].ordem) return false;
    return true;
}

void mostra(const char *rotulo, const Inscricao s[], int n) {
    printf("%s:", rotulo);
    for (int i = 0; i < n; i++) printf(" %s(%d)", s[i].nome, s[i].cat);
    printf(" -> %s\n", estavel(s, n) ? "estável" : "NÃO estável");
}

int main(void) {
    Inscricao v[N] = {{"Ana", 1, 1}, {"Bruno", 0, 2}, {"Carla", 3, 3}, {"Davi", 1, 4},
                      {"Elis", 0, 5}, {"Fabio", 2, 6}, {"Gil", 1, 7}, {"Hana", 3, 8}};
    Inscricao saida[N];

    counting(v, saida, N, true);
    mostra("de trás", saida, N);
    counting(v, saida, N, false);
    mostra("da frente", saida, N);
    return 0;
}
