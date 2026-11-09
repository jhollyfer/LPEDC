// Lista · Módulo 11 · Listas
// Exercício P1116 · ★★☆ · A agenda do consultório em vetor ordenado

#include <stdbool.h>
#include <stdio.h>

#define CAP 10

typedef struct {
    int v[CAP];
    int n;
} Agenda;

int ord_busca(const Agenda *a, int x, int *pos) {
    int ini = 0, fim = a->n - 1;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        if (a->v[meio] == x) {
            *pos = meio;
            return 1;
        }
        if (a->v[meio] < x) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    *pos = ini; // onde x entraria
    return 0;
}

bool ord_insere(Agenda *a, int x) {
    int p;
    if (a->n == CAP || ord_busca(a, x, &p)) {
        return false;
    }
    for (int i = a->n; i > p; i--) {
        a->v[i] = a->v[i - 1];
    }
    a->v[p] = x;
    a->n++;
    return true;
}

bool ord_remove(Agenda *a, int x) {
    int p;
    if (!ord_busca(a, x, &p)) {
        return false;
    }
    for (int i = p; i < a->n - 1; i++) {
        a->v[i] = a->v[i + 1];
    }
    a->n--;
    return true;
}

void hora(int minutos) {
    printf("%02d:%02d", minutos / 60, minutos % 60);
}

void mostra(const char *rotulo, const Agenda *a) {
    printf("%s:", rotulo);
    for (int i = 0; i < a->n; i++) {
        printf(" ");
        hora(a->v[i]);
    }
    printf("\n");
}

int main(void) {
    Agenda dia = {.n = 0};
    int pedidos[5] = {540, 600, 480, 720, 600};
    bool recusado[5];
    for (int i = 0; i < 5; i++) {
        recusado[i] = !ord_insere(&dia, pedidos[i]);
    }
    mostra("Agenda", &dia);
    for (int i = 0; i < 5; i++) {
        if (recusado[i]) {
            hora(pedidos[i]);
            printf(": horário ocupado\n");
        }
    }
    ord_remove(&dia, 540);
    mostra("Sem 09:00", &dia);
    int pos;
    if (ord_busca(&dia, 720, &pos)) {
        printf("12:00 está na posição %d\n", pos);
    }
    return 0;
}
