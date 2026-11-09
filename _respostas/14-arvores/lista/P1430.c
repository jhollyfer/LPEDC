// Lista · Módulo 14 · Árvores
// Exercício P1430 · ★★★ · O heapsort que embaralhava os empates

#include <stdio.h>

typedef struct {
    int numero;  // número de peito, em ordem de inscrição
    int tempo;   // minutos
    int ordem;   // posição original (para desempatar)
} Corredor;

int usa_ordem;

// a deve ficar DEPOIS de b no vetor ordenado? (heap de máximo)
int maior(const Corredor *a, const Corredor *b) {
    if (a->tempo != b->tempo) {
        return a->tempo > b->tempo;
    }
    return usa_ordem && a->ordem > b->ordem;
}

void troca(Corredor *a, Corredor *b) {
    Corredor t = *a;
    *a = *b;
    *b = t;
}

void desce(Corredor v[], int n, int i) {
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && maior(&v[f + 1], &v[f])) {
            f++;
        }
        if (!maior(&v[f], &v[i])) {
            break;
        }
        troca(&v[i], &v[f]);
        i = f;
    }
}

void heapsort(Corredor v[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        desce(v, n, i);
    }
    for (int fim = n - 1; fim > 0; fim--) {
        troca(&v[0], &v[fim]);
        desce(v, fim, 0);
    }
}

void mostra(const char *rotulo, const Corredor v[], int n) {
    printf("%s:", rotulo);
    for (int i = 0; i < n; i++) {
        printf(" #%d(%d)", v[i].numero, v[i].tempo);
    }
    printf("\n");
}

int main(void) {
    Corredor inscritos[] = {{101, 42, 0}, {102, 38, 1}, {103, 42, 2}, {104, 35, 3},
                            {105, 38, 4}, {106, 42, 5}, {107, 35, 6}};
    int n = 7;
    Corredor a[7], b[7];
    for (int i = 0; i < n; i++) {
        a[i] = b[i] = inscritos[i];
    }

    usa_ordem = 0;
    heapsort(a, n);
    mostra("só o tempo  ", a, n);
    usa_ordem = 1;
    heapsort(b, n);
    mostra("tempo, ordem", b, n);
    return 0;
}
