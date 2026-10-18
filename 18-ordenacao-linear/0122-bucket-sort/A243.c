// A243 · Quando todo mundo cai no mesmo balde

#include <stdio.h>
#include <stdlib.h>

#define N 1000

typedef struct No {
    double valor;
    struct No *prox;
} No;

static long comparacoes;
static unsigned semente;

// número entre 0 e 1 (sem chegar a 1), sempre a mesma sequência
double sorteia(void) {
    semente = semente * 1103515245u + 12345u;
    return ((semente >> 8) % 1000000) / 1000000.0;
}

No *insere_ordenado(No *lista, double x) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        exit(1);
    }
    novo->valor = x;
    No **p = &lista;                  // ponteiro para o elo que vai mudar
    while (*p != NULL) {
        comparacoes++;
        if ((*p)->valor > x) {
            break;
        }
        p = &(*p)->prox;
    }
    novo->prox = *p;
    *p = novo;
    return lista;
}

// n baldes para notas de 0 a 10: cada balde cobre uma faixa de 10 / n
void bucket_sort(double v[], int n, int *maior_balde) {
    No **baldes = calloc(n, sizeof(No *));
    int *tamanho = calloc(n, sizeof(int));
    if (baldes == NULL || tamanho == NULL) {
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        int b = (int) (v[i] / 10.0 * n);
        baldes[b] = insere_ordenado(baldes[b], v[i]);
        tamanho[b]++;
    }
    *maior_balde = 0;
    int k = 0;
    for (int b = 0; b < n; b++) {
        if (tamanho[b] > *maior_balde) {
            *maior_balde = tamanho[b];
        }
        while (baldes[b] != NULL) {
            No *p = baldes[b];
            v[k++] = p->valor;
            baldes[b] = p->prox;
            free(p);
        }
    }
    free(baldes);
    free(tamanho);
}

void testa(const char *nome, double base, double largura) {
    double v[N];
    semente = 42;
    for (int i = 0; i < N; i++) {
        v[i] = base + largura * sorteia();
    }
    comparacoes = 0;
    int maior;
    bucket_sort(v, N, &maior);
    printf("%-22s %7ld comparações, maior balde com %3d notas\n", nome, comparacoes, maior);
}

int main(void) {
    testa("notas de 0 a 10:", 0.0, 10.0);
    testa("notas de 5 a 6:", 5.0, 1.0);
    testa("notas de 5,0 a 5,01:", 5.0, 0.01);
    return 0;
}
// Saída:
// notas de 0 a 10:           469 comparações, maior balde com   6 notas
// notas de 5 a 6:           3237 comparações, maior balde com  18 notas
// notas de 5,0 a 5,01:    243539 comparações, maior balde com 1000 notas
//
// Os mesmos 1000 baldes, três distribuições. Espalhadas de 0 a 10, as notas
// caem em média uma por balde e o total é menos de meia comparação por nota.
// Concentradas entre 5 e 6, só 100 baldes trabalham. Entre 5,0 e 5,01, todas
// caem no balde 500 e sobra um insertion sort de 1000 elementos: perto de
// n²/4 comparações. O insere_ordenado usa um ponteiro para ponteiro (No **)
// para não tratar o começo da lista como caso especial.
