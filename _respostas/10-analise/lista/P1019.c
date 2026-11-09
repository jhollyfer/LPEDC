// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1019 · ★★☆ · O resumo da corrida em O(1)

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// ---- resumo.h -------------------------------------------------------------
typedef struct resumo Resumo;

Resumo *resumo_cria(void);
void resumo_adiciona(Resumo *r, double x);
int resumo_quantidade(const Resumo *r);
double resumo_media(const Resumo *r);
double resumo_menor(const Resumo *r);
double resumo_maior(const Resumo *r);
double resumo_desvio(const Resumo *r); // desvio padrão populacional
void resumo_libera(Resumo *r);

// ---- resumo.c -------------------------------------------------------------
struct resumo {
    int n;
    double soma, soma_quad, menor, maior;
};

Resumo *resumo_cria(void) {
    Resumo *r = malloc(sizeof *r);
    if (r != NULL) {
        r->n = 0;
        r->soma = r->soma_quad = r->menor = r->maior = 0;
    }
    return r;
}

void resumo_adiciona(Resumo *r, double x) {
    if (r->n == 0 || x < r->menor) {
        r->menor = x;
    }
    if (r->n == 0 || x > r->maior) {
        r->maior = x;
    }
    r->soma += x;
    r->soma_quad += x * x;
    r->n++;
}

int resumo_quantidade(const Resumo *r) {
    return r->n;
}

double resumo_media(const Resumo *r) {
    return r->n > 0 ? r->soma / r->n : 0;
}

double resumo_menor(const Resumo *r) {
    return r->menor;
}

double resumo_maior(const Resumo *r) {
    return r->maior;
}

double resumo_desvio(const Resumo *r) {
    if (r->n == 0) {
        return 0;
    }
    double m = resumo_media(r);
    double var = r->soma_quad / r->n - m * m;
    return var > 0 ? sqrt(var) : 0;
}

void resumo_libera(Resumo *r) {
    free(r);
}

// ---- cliente --------------------------------------------------------------
int main(void) {
    double tempos[6] = {32, 29, 35, 31, 28, 33};
    Resumo *r = resumo_cria();
    if (r == NULL) {
        printf("Sem memória\n");
        return 1;
    }
    for (int i = 0; i < 6; i++) {
        resumo_adiciona(r, tempos[i]);
    }
    printf("Corridas: %d\n", resumo_quantidade(r));
    printf("Média: %.2f min\n", resumo_media(r));
    printf("Melhor: %.0f min\n", resumo_menor(r));
    printf("Pior: %.0f min\n", resumo_maior(r));
    printf("Desvio: %.2f min\n", resumo_desvio(r));
    resumo_libera(r);
    return 0;
}
