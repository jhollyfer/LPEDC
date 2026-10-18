// 0165 · Juntando tudo
// Exercício E988 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include "bancada.h"

#define N 1000
#define BUSCAS 10000
#define QUENTES 20
typedef struct {
    int *v;
    int n, cap;
} Vetor;

void *vet_cria(void) {
    Vetor *a = malloc(sizeof(Vetor));
    if (a == NULL) {
        exit(1);
    }
    a->cap = 16;
    a->n = 0;
    a->v = malloc(a->cap * sizeof(int));
    if (a->v == NULL) {
        exit(1);
    }
    return a;
}

// busca binária: devolve a posição da chave ou onde ela entraria
static int posicao(const Vetor *a, int chave, int *custo) {
    int ini = 0, fim = a->n - 1, c = 0;
    while (ini <= fim) {
        int meio = ini + (fim - ini) / 2;
        c++;
        if (a->v[meio] == chave) {
            *custo = c;
            return meio;
        }
        if (a->v[meio] < chave) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    *custo = c;
    return ini;
}

void vet_insere(void *e, int chave) {
    Vetor *a = e;
    int custo;
    int i = posicao(a, chave, &custo);
    if (i < a->n && a->v[i] == chave) {
        return; // repetida
    }
    if (a->n == a->cap) { // cheio: dobra (assunto 0055)
        int *maior = realloc(a->v, 2 * a->cap * sizeof(int));
        if (maior == NULL) {
            exit(1);
        }
        a->v = maior;
        a->cap *= 2;
    }
    for (int j = a->n; j > i; j--) { // abre espaço empurrando para a direita
        a->v[j] = a->v[j - 1];
    }
    a->v[i] = chave;
    a->n++;
}

bool vet_busca(void *e, int chave, int *custo) {
    const Vetor *a = e;
    int i = posicao(a, chave, custo);
    return i < a->n && a->v[i] == chave;
}

void vet_libera(void *e) {
    Vetor *a = e;
    free(a->v);
    free(a);
}

double mede(const Estrutura *e, const int ordem[], const int buscas[]) {
    void *d = e->cria();
    for (int i = 0; i < N; i++) {
        e->insere(d, ordem[i]);
    }
    long total = 0;
    for (int i = 0; i < BUSCAS; i++) {
        int custo;
        e->busca(d, buscas[i], &custo);
        total += custo;
    }
    e->libera(d);
    return (double)total / BUSCAS;
}

int main(void) {
    unsigned estado = 7;
    int crescente[N], embaralhada[N], sorteio[N];
    for (int i = 0; i < N; i++) {
        crescente[i] = embaralhada[i] = sorteio[i] = i + 1;
    }
    bc_embaralha(embaralhada, N, &estado);
    bc_embaralha(sorteio, N, &estado);
    static int buscas[BUSCAS];
    for (int i = 0; i < BUSCAS; i++) {
        if (bc_sorteio(&estado) % 100 < 80) {
            buscas[i] = sorteio[bc_sorteio(&estado) % QUENTES];
        } else {
            buscas[i] = bc_sorteio(&estado) % N + 1;
        }
    }

    Estrutura todos[NUM_CONCORRENTES + 1];
    for (int k = 0; k < NUM_CONCORRENTES; k++) {
        todos[k] = CONCORRENTES[k];
    }
    todos[NUM_CONCORRENTES] = (Estrutura){"vetor", vet_cria, vet_insere, vet_busca, vet_libera};

    printf("%-10s %12s %10s\n", "", "embaralhada", "crescente");
    for (int k = 0; k <= NUM_CONCORRENTES; k++) {
        printf("%-10s %12.1f %10.1f\n", todos[k].nome, mede(&todos[k], embaralhada, buscas),
               mede(&todos[k], crescente, buscas));
    }
    return 0;
}
