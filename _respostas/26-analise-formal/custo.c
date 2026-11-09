// custo.c · implementação das cinco funções instrumentadas
#include <stdlib.h>
#include "custo.h"

long custo_passos = 0;
size_t custo_bytes = 0;
int custo_prof_max = 0;
static int prof = 0;

void custo_zera(void) {
    custo_passos = 0;
    custo_bytes = 0;
    custo_prof_max = 0;
    prof = 0;
}

static void entra(void) {
    prof++;
    if (prof > custo_prof_max) {
        custo_prof_max = prof;
    }
}

static void sai(void) {
    prof--;
}

// soma de todos: um passo por elemento
long custo_soma(const int v[], int n) {
    entra();
    long s = 0;
    for (int i = 0; i < n; i++) {
        custo_passos++;
        s += v[i];
    }
    sai();
    return s;
}

// busca binária com laço: um passo por elemento olhado
int custo_busca(const int v[], int n, int x) {
    entra();
    int ini = 0, fim = n, achou = -1;
    while (ini < fim) {
        custo_passos++;
        int meio = ini + (fim - ini) / 2;
        if (v[meio] == x) {
            achou = meio;
            break;
        }
        if (x < v[meio]) {
            fim = meio;
        } else {
            ini = meio + 1;
        }
    }
    sai();
    return achou;
}

// quantos pares (i < j) somam alvo: um passo por par testado
long custo_pares(const int v[], int n, int alvo) {
    entra();
    long achados = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            custo_passos++;
            if (v[i] + v[j] == alvo) {
                achados++;
            }
        }
    }
    sai();
    return achados;
}

// intercala v[ini..meio-1] e v[meio..fim-1]: um passo por elemento copiado
static void intercala(int v[], int aux[], int ini, int meio, int fim) {
    int i = ini, j = meio, k = ini;
    while (i < meio || j < fim) {
        custo_passos++;
        if (j >= fim || (i < meio && v[i] <= v[j])) {
            aux[k++] = v[i++];
        } else {
            aux[k++] = v[j++];
        }
    }
    for (k = ini; k < fim; k++) {
        v[k] = aux[k];
    }
}

static void ordena(int v[], int aux[], int ini, int fim) {
    entra();
    if (fim - ini > 1) {
        int meio = ini + (fim - ini) / 2;
        ordena(v, aux, ini, meio);
        ordena(v, aux, meio, fim);
        intercala(v, aux, ini, meio, fim);
    }
    sai();
}

// merge sort com um único vetor auxiliar de n posições
void custo_merge(int v[], int n) {
    entra();
    int *aux = malloc(n * sizeof(int));
    if (aux != NULL) {
        custo_bytes += n * sizeof(int);
        ordena(v, aux, 0, n);
        free(aux);
    }
    sai();
}

// soma recursiva: um passo por chamada, n + 1 chamadas empilhadas
long custo_soma_rec(const int v[], int n) {
    entra();
    custo_passos++;
    long s = (n == 0) ? 0 : v[n - 1] + custo_soma_rec(v, n - 1);
    sai();
    return s;
}
