// 0120 · Counting sort
// Exercício E719 · ★★★

#include <stdio.h>
#include <stdbool.h>

#define K 4 // prioridade de 0 (urgente) a 3 (pode esperar)

typedef struct {
    int chamado;    // número do chamado, na ordem de abertura
    int prioridade;
} Chamado;

void ordena(const Chamado v[], Chamado saida[], int n) {
    int c[K] = {0};
    for (int i = 0; i < n; i++) {
        c[v[i].prioridade]++;
    }
    for (int x = 1; x < K; x++) {
        c[x] += c[x - 1];
    }
    for (int i = n - 1; i >= 0; i--) {   // de trás para a frente: estável
        int x = v[i].prioridade;
        c[x]--;
        saida[c[x]] = v[i];
    }
}

// estável: entre prioridades iguais, os chamados seguem crescentes
bool estavel(const Chamado v[], int n) {
    for (int i = 1; i < n; i++) {
        if (v[i].prioridade == v[i - 1].prioridade && v[i].chamado < v[i - 1].chamado) {
            return false;
        }
    }
    return true;
}

int main(void) {
    Chamado abertos[] = {{101, 2}, {102, 0}, {103, 3}, {104, 2}, {105, 1},
                         {106, 0}, {107, 2}, {108, 1}, {109, 3}, {110, 0}};
    Chamado fila[10];
    int n = 10;

    ordena(abertos, fila, n);
    for (int i = 0; i < n; i++) {
        if (i == 0 || fila[i].prioridade != fila[i - 1].prioridade) {
            printf("%sp%d:", i == 0 ? "" : "\n", fila[i].prioridade);
        }
        printf(" %d", fila[i].chamado);
    }
    printf("\nestável? %s\n", estavel(fila, n) ? "sim" : "não");
    return 0;
}
