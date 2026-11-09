// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1821 · ★★★ · O painel de partidas do aeroporto

#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct {
    int numero, dia, hora, minuto;
    const char *destino;
} Voo;

int ch_numero(const Voo *v) { return v->numero; }
int ch_minuto(const Voo *v) { return v->minuto; }
int ch_hora(const Voo *v) { return v->hora; }
int ch_dia(const Voo *v) { return v->dia; }

void counting(Voo v[], int n, int (*chave)(const Voo *), int k) {
    static int c[10000];
    Voo saida[N];
    for (int x = 0; x < k; x++) c[x] = 0;
    for (int i = 0; i < n; i++) c[chave(&v[i])]++;
    for (int x = 1; x < k; x++) c[x] += c[x - 1];
    for (int i = n - 1; i >= 0; i--) saida[--c[chave(&v[i])]] = v[i]; // estável
    for (int i = 0; i < n; i++) v[i] = saida[i];
}

int compara(const void *pa, const void *pb) {
    const Voo *a = pa, *b = pb;
    if (a->dia != b->dia) return a->dia - b->dia;
    if (a->hora != b->hora) return a->hora - b->hora;
    if (a->minuto != b->minuto) return a->minuto - b->minuto;
    return a->numero - b->numero;
}

void numeros(const char *rotulo, const Voo v[], int n) {
    printf("%-11s", rotulo);
    for (int i = 0; i < n; i++) printf(" %d", v[i].numero);
    printf("\n");
}

int main(void) {
    Voo v[N] = {{3320, 10, 14, 5, "Belem"},     {1502, 9, 6, 15, "Brasilia"},
                {2788, 10, 14, 5, "Sao Paulo"}, {4410, 11, 23, 40, "Fortaleza"},
                {1190, 9, 21, 30, "Boa Vista"}, {2210, 10, 6, 15, "Porto Velho"},
                {1501, 9, 21, 30, "Brasilia"},  {3999, 11, 8, 0, "Recife"},
                {2011, 10, 14, 50, "Santarem"}, {1777, 11, 8, 0, "Rio"}};
    Voo q[N];
    for (int i = 0; i < N; i++) q[i] = v[i];

    counting(v, N, ch_numero, 10000);
    numeros("por número:", v, N);
    counting(v, N, ch_minuto, 60);
    numeros("por minuto:", v, N);
    counting(v, N, ch_hora, 24);
    numeros("por hora:", v, N);
    counting(v, N, ch_dia, 31);
    numeros("por dia:", v, N);

    printf("Data  Hora    Voo  Destino\n");
    for (int i = 0; i < N; i++)
        printf("%02d/11 %02d:%02d %5d  %s\n", v[i].dia, v[i].hora, v[i].minuto, v[i].numero, v[i].destino);

    qsort(q, N, sizeof q[0], compara);
    int iguais = 1;
    for (int i = 0; i < N; i++)
        if (q[i].numero != v[i].numero) iguais = 0;
    printf("qsort concorda: %s\n", iguais ? "sim" : "não");
    return 0;
}
