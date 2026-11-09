// Lista · Módulo 14 · Árvores
// Exercício P1427 · ★★★ · A mediana que acompanha o fluxo

#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// heap genérico: sinal = 1 para máximo, -1 para mínimo
void sobe(int h[], int i, int sinal) {
    while (i > 0 && sinal * h[i] > sinal * h[(i - 1) / 2]) {
        troca(&h[i], &h[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void desce(int h[], int n, int i, int sinal) {
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && sinal * h[f + 1] > sinal * h[f]) {
            f++;
        }
        if (sinal * h[i] >= sinal * h[f]) {
            break;
        }
        troca(&h[i], &h[f]);
        i = f;
    }
}

void insere(int h[], int *n, int x, int sinal) {
    h[*n] = x;
    sobe(h, *n, sinal);
    (*n)++;
}

int extrai(int h[], int *n, int sinal) {
    int topo = h[0];
    h[0] = h[--(*n)];
    desce(h, *n, 0, sinal);
    return topo;
}

int main(void) {
    int tempos[] = {35, 12, 50, 20, 41, 8, 27, 60};
    int baixo[8], nb = 0; // metade de baixo: heap de MÁXIMO
    int alto[8], na = 0;  // metade de cima: heap de MÍNIMO

    for (int i = 0; i < 8; i++) {
        int x = tempos[i];
        if (nb == 0 || x <= baixo[0]) {
            insere(baixo, &nb, x, 1);
        } else {
            insere(alto, &na, x, -1);
        }
        // equilibra: baixo tem o mesmo tamanho de alto ou um a mais
        if (nb > na + 1) {
            insere(alto, &na, extrai(baixo, &nb, 1), -1);
        } else if (na > nb) {
            insere(baixo, &nb, extrai(alto, &na, -1), 1);
        }
        double mediana = (nb > na) ? baixo[0] : (baixo[0] + alto[0]) / 2.0;
        printf("chegou %2d: mediana %.1f\n", x, mediana);
    }
    return 0;
}
