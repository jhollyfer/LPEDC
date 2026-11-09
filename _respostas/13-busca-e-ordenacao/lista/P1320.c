// Lista · Módulo 13 · Busca e ordenação
// Exercício P1320 · ★★☆ · Um selection sort estável

#include <stdio.h>

typedef struct {
    char nome[8];
    int prioridade;
} Cliente;

void mostra(const char *rotulo, const Cliente v[], int n) {
    printf("%s:", rotulo);
    for (int i = 0; i < n; i++) {
        printf(" %s%d", v[i].nome, v[i].prioridade);
    }
    printf("\n");
}

void selection_troca(Cliente v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j].prioridade < v[menor].prioridade) {
                menor = j;
            }
        }
        Cliente t = v[i];
        v[i] = v[menor];
        v[menor] = t;
    }
}

// em vez de trocar, tira o menor do lugar e empurra v[i..menor-1] uma casa
void selection_estavel(Cliente v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j].prioridade < v[menor].prioridade) {
                menor = j;
            }
        }
        Cliente x = v[menor];
        for (int k = menor; k > i; k--) {
            v[k] = v[k - 1];
        }
        v[i] = x;
    }
}

int main(void) {
    // ordem de chegada
    Cliente fila[] = {{"A", 3}, {"B", 2}, {"C", 3}, {"D", 1}, {"E", 2}, {"F", 1}};
    int n = 6;
    Cliente a[6], b[6];
    for (int i = 0; i < n; i++) {
        a[i] = b[i] = fila[i];
    }

    selection_troca(a, n);
    selection_estavel(b, n);
    mostra("com troca  ", a, n);
    mostra("deslocando ", b, n);
    return 0;
}
