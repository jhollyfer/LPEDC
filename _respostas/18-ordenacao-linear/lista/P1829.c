// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1829 · ★★★ · A classificação do campeonato com quatro critérios

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef struct {
    const char *nome;
    int pontos, vitorias, saldo;
} Time;

int ch_saldo(const Time *t) { return 30 - t->saldo; } // decrescente, deslocado para 0..60
int ch_vitorias(const Time *t) { return 38 - t->vitorias; }
int ch_pontos(const Time *t) { return 114 - t->pontos; }

void counting(Time v[], int n, int (*chave)(const Time *), int k) {
    int c[115] = {0}; // k <= 115
    Time saida[N];
    for (int i = 0; i < n; i++) c[chave(&v[i])]++;
    for (int x = 1; x < k; x++) c[x] += c[x - 1];
    for (int i = n - 1; i >= 0; i--) saida[--c[chave(&v[i])]] = v[i];
    for (int i = 0; i < n; i++) v[i] = saida[i];
}

int compara(const void *pa, const void *pb) {
    const Time *a = pa, *b = pb;
    if (a->pontos != b->pontos) return b->pontos - a->pontos;
    if (a->vitorias != b->vitorias) return b->vitorias - a->vitorias;
    if (a->saldo != b->saldo) return b->saldo - a->saldo;
    return strcmp(a->nome, b->nome);
}

void ordem(const char *rotulo, const Time v[], int n) {
    printf("%s", rotulo); // rótulos já alinhados (o "ó" ocupa 2 bytes)
    for (int i = 0; i < n; i++) printf(" %.4s", v[i].nome); // 4 letras bastam para distinguir
    printf("\n");
}

int main(void) {
    Time v[N] = {{"Arara Azul", 15, 4, 3},   {"Boto Rosa", 19, 6, 8},     {"Jaraqui", 19, 6, 5},
                 {"Onca Pintada", 10, 2, -6}, {"Peixe-Boi", 15, 5, -1},    {"Pirarucu", 15, 4, 3},
                 {"Sumauma", 7, 1, -12},     {"Tambaqui", 19, 5, 9},      {"Tucunare", 22, 7, 11},
                 {"Vitoria-Regia", 10, 3, -2}};
    Time q[N];
    memcpy(q, v, sizeof q);

    counting(v, N, ch_saldo, 61);
    ordem("por saldo:    ", v, N);
    counting(v, N, ch_vitorias, 39);
    ordem("por vitórias: ", v, N);
    counting(v, N, ch_pontos, 115);
    ordem("por pontos:   ", v, N);

    printf(" #  Time           Pts  V  Saldo\n");
    for (int i = 0; i < N; i++)
        printf("%2d  %-13s %4d %2d %+6d\n", i + 1, v[i].nome, v[i].pontos, v[i].vitorias, v[i].saldo);

    qsort(q, N, sizeof q[0], compara);
    int iguais = 1;
    for (int i = 0; i < N; i++)
        if (strcmp(q[i].nome, v[i].nome) != 0) iguais = 0;
    printf("qsort concorda: %s\n", iguais ? "sim" : "não");
    return 0;
}
