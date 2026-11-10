// A370 · Multiplicando de verdade e contando

#include <stdio.h>
#include <stdlib.h>

#define N 4

const int p[N + 1] = {10, 30, 5, 60, 10};
long contas = 0; // multiplicações de números feitas de verdade

typedef struct {
    int lin, col;
    long *v; // lin * col números, linha após linha
} Matriz;

Matriz nova(int lin, int col) {
    Matriz m = {lin, col, calloc((size_t)lin * col, sizeof(long))};
    if (m.v == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    return m;
}

Matriz multiplica(Matriz a, Matriz b) { // a.col == b.lin
    Matriz c = nova(a.lin, b.col);
    for (int i = 0; i < a.lin; i++)
        for (int j = 0; j < b.col; j++)
            for (int k = 0; k < a.col; k++) {
                c.v[i * c.col + j] += a.v[i * a.col + k] * b.v[k * b.col + j];
                contas++;
            }
    return c;
}

long soma(Matriz m) {
    long s = 0;
    for (int i = 0; i < m.lin * m.col; i++) s += m.v[i];
    return s;
}

int main(void) {
    Matriz a[N + 1];
    for (int t = 1; t <= N; t++) { // Ai: p[t-1] x p[t], valores pequenos
        a[t] = nova(p[t - 1], p[t]);
        for (int i = 0; i < a[t].lin * a[t].col; i++) a[t].v[i] = (i + t) % 3;
    }

    // ordem ótima da PD: (A1 A2)(A3 A4)
    contas = 0;
    Matriz x = multiplica(a[1], a[2]), y = multiplica(a[3], a[4]), r1 = multiplica(x, y);
    printf("(A1 A2)(A3 A4): %ld multiplicações, soma do resultado %ld\n", contas, soma(r1));

    // da esquerda para a direita: ((A1 A2) A3) A4
    contas = 0;
    Matriz z = multiplica(a[1], a[2]), w = multiplica(z, a[3]), r2 = multiplica(w, a[4]);
    printf("((A1 A2) A3) A4: %ld multiplicações, soma do resultado %ld\n", contas, soma(r2));

    Matriz todas[] = {x, y, r1, z, w, r2};
    for (int i = 0; i < 6; i++) free(todas[i].v);
    for (int t = 1; t <= N; t++) free(a[t].v);
    return 0;
}
// Saída:
// (A1 A2)(A3 A4): 5000 multiplicações, soma do resultado 986000
// ((A1 A2) A3) A4: 10500 multiplicações, soma do resultado 986000
//
// O resultado é o mesmo (a associatividade garante), e as contas batem com
// a tabela m: 5000 na ordem ótima, 10500 na ordem "natural". Repare também
// na memória: a ordem ruim cria uma intermediária de 10 x 60 (600 números);
// a ótima, uma de 10 x 5 e outra de 5 x 10 (100 números).
