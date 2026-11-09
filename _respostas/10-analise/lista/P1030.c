// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1030 · ★★★ · Moda e mediana sem ordenar nada

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// ---- histograma.h ---------------------------------------------------------
typedef struct histograma Histograma;

Histograma *hist_cria(void);
bool hist_adiciona(Histograma *h, int nota); // false se fora de 0..10
int hist_quantidade(const Histograma *h);
int hist_moda(const Histograma *h, int *vezes); // a menor, no empate
int hist_mediana(const Histograma *h);          // o elemento (n + 1) / 2 na ordem
double hist_media(const Histograma *h);
void hist_libera(Histograma *h);

// ---- histograma.c ---------------------------------------------------------
// Invariante: n é a soma de cont[0..10] e soma é a soma de todas as notas.
struct histograma {
    int cont[11];
    int n;
    long soma;
};

Histograma *hist_cria(void) {
    Histograma *h = malloc(sizeof *h);
    if (h != NULL) {
        for (int i = 0; i <= 10; i++) {
            h->cont[i] = 0;
        }
        h->n = 0;
        h->soma = 0;
    }
    return h;
}

bool hist_adiciona(Histograma *h, int nota) {
    if (nota < 0 || nota > 10) {
        return false;
    }
    h->cont[nota]++;
    h->n++;
    h->soma += nota;
    return true;
}

int hist_quantidade(const Histograma *h) {
    return h->n;
}

int hist_moda(const Histograma *h, int *vezes) {
    int moda = 0;
    for (int i = 1; i <= 10; i++) {
        if (h->cont[i] > h->cont[moda]) {
            moda = i;
        }
    }
    *vezes = h->cont[moda];
    return moda;
}

int hist_mediana(const Histograma *h) {
    int alvo = (h->n + 1) / 2, acumulado = 0;
    for (int i = 0; i <= 10; i++) {
        acumulado += h->cont[i];
        if (acumulado >= alvo) {
            return i;
        }
    }
    return -1; // histograma vazio
}

double hist_media(const Histograma *h) {
    return h->n > 0 ? (double) h->soma / h->n : 0;
}

void hist_libera(Histograma *h) {
    free(h);
}

// ---- cliente --------------------------------------------------------------
int main(void) {
    int notas[11] = {7, 8, 5, 10, 7, 6, 9, 7, 4, 8, 7};
    Histograma *h = hist_cria();
    if (h == NULL) {
        return 1;
    }
    for (int i = 0; i < 11; i++) {
        hist_adiciona(h, notas[i]);
    }
    int vezes;
    int moda = hist_moda(h, &vezes);
    printf("Notas: %d\n", hist_quantidade(h));
    printf("Moda: %d (%d vezes)\n", moda, vezes);
    printf("Mediana: %d\n", hist_mediana(h));
    printf("Média: %.2f\n", hist_media(h));

    for (int i = 0; i < 12; i++) {
        hist_adiciona(h, 10);
    }
    moda = hist_moda(h, &vezes);
    printf("Depois de mais doze notas 10: moda %d (%d vezes), mediana %d\n", moda, vezes, hist_mediana(h));
    hist_libera(h);
    return 0;
}
