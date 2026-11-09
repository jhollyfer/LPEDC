// 0179 · Sondagem quadrática e dupla
// Exercício E1074 · ★★★

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *chave; // -1 livre, -2 lápide
    int m, n;
} Tabela;

bool eh_primo(int x) {
    if (x < 2) {
        return false;
    }
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) {
            return false;
        }
    }
    return true;
}

int primo_a_partir(int x) {
    while (!eh_primo(x)) {
        x++;
    }
    return x;
}

int *cria_vetor(int m) {
    int *v = malloc((size_t)m * sizeof(int));
    if (v == NULL) {
        exit(1);
    }
    for (int j = 0; j < m; j++) {
        v[j] = -1;
    }
    return v;
}

// insere com dispersão dupla sem conferir a carga; devolve as sondagens
int coloca(Tabela *t, int k) {
    int h1 = k % t->m, h2 = 1 + k % (t->m - 1);
    for (int i = 0; i < t->m; i++) {
        int j = (int)((h1 + (long)i * h2) % t->m);
        if (t->chave[j] < 0) {
            t->chave[j] = k;
            t->n++;
            return i + 1;
        }
    }
    return -1;
}

void cresce(Tabela *t) {
    int *velho = t->chave;
    int m_velho = t->m;
    t->m = primo_a_partir(2 * m_velho);
    t->chave = cria_vetor(t->m);
    t->n = 0;
    for (int j = 0; j < m_velho; j++) {
        if (velho[j] >= 0) { // as lápides ficam para trás
            coloca(t, velho[j]);
        }
    }
    free(velho);
    printf("cresceu: m = %d -> %d (n = %d)\n", m_velho, t->m, t->n);
}

void insere(Tabela *t, int k) {
    if ((double)(t->n + 1) / t->m > 0.5) {
        cresce(t);
    }
    coloca(t, k);
}

int main(void) {
    Tabela t = {cria_vetor(7), 7, 0};
    for (int i = 0; i < 40; i++) {
        insere(&t, 7919 * i % 100000);
    }
    long soma = 0;
    for (int i = 0; i < 40; i++) { // quantas sondagens a busca de cada uma faz
        int k = 7919 * i % 100000;
        int h1 = k % t.m, h2 = 1 + k % (t.m - 1);
        for (int s = 0; s < t.m; s++) {
            if (t.chave[(h1 + (long)s * h2) % t.m] == k) {
                soma += s + 1;
                break;
            }
        }
    }
    printf("fim: n = %d, m = %d, carga %.2f, média de sondagens %.2f\n", t.n, t.m,
           (double)t.n / t.m, soma / 40.0);
    free(t.chave);
    return 0;
}
