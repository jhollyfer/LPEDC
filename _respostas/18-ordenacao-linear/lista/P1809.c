// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1809 · ★☆☆ · A tabela do campeonato em ordem decrescente, estável

#include <stdio.h>

#define N 8
#define MAX 15

typedef struct {
    const char *nome;
    int pontos;
} Time;

int chave(Time t) { return MAX - t.pontos; } // mais pontos, chave menor

void ordena(const Time v[], Time saida[], int n) {
    int c[MAX + 1] = {0};
    for (int i = 0; i < n; i++) c[chave(v[i])]++;
    for (int x = 1; x <= MAX; x++) c[x] += c[x - 1];
    for (int i = n - 1; i >= 0; i--) saida[--c[chave(v[i])]] = v[i]; // estável
}

int main(void) {
    Time v[N] = {{"Amazonas", 9}, {"Bahia", 9}, {"Ceara", 9}, {"Distrito Federal", 2},
                 {"Espirito Santo", 7}, {"Fortaleza", 4}, {"Goias", 15}, {"Para", 12}};
    Time saida[N];

    ordena(v, saida, N);
    for (int i = 0; i < N; i++) printf("%d. %-16s %2d\n", i + 1, saida[i].nome, saida[i].pontos);
    return 0;
}
