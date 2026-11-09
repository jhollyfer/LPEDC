// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1708 · ★☆☆ · Quão funda fica a pilha de chamadas

#include <stdio.h>

#define MAX 1000

int conta[MAX];
long chamadas;
int max_prof;

void anota(int prof) {
    chamadas++;
    if (prof > max_prof) max_prof = prof;
}

long soma_fila(const int v[], int n, int prof) {
    anota(prof);
    if (n == 0) return 0;
    return v[n - 1] + soma_fila(v, n - 1, prof + 1);
}

long soma_meio(const int v[], int ini, int fim, int prof) {
    anota(prof);
    if (ini == fim) return v[ini];
    int meio = (ini + fim) / 2;
    return soma_meio(v, ini, meio, prof + 1) + soma_meio(v, meio + 1, fim, prof + 1);
}

int main(void) {
    for (int i = 0; i < MAX; i++) conta[i] = 80 + (i * 13) % 150; // R$ por apartamento

    int ns[] = {10, 100, 1000};
    for (int k = 0; k < 3; k++) {
        int n = ns[k];
        chamadas = max_prof = 0;
        long s1 = soma_fila(conta, n, 1);
        long c1 = chamadas;
        int p1 = max_prof;
        chamadas = max_prof = 0;
        long s2 = soma_meio(conta, 0, n - 1, 1);
        printf("n = %4d  fila: soma %6ld, %4ld chamadas, profundidade %4d\n", n, s1, c1, p1);
        printf("          meio: soma %6ld, %4ld chamadas, profundidade %4d\n", s2, chamadas, max_prof);
    }
    return 0;
}
