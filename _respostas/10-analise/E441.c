// 0074 · TAD: interface (.h) e implementação (.c)
// Exercício E441 · ★★☆
//
// Resposta: 5.00 km e 10.00 km.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// ---- ponto.h --------------------------------------------------------------
typedef struct ponto Ponto;

Ponto *ponto_cria(double x, double y); // NULL se faltar memória
void ponto_libera(Ponto *p);           // aceita NULL
double ponto_x(const Ponto *p);
double ponto_y(const Ponto *p);
double ponto_distancia(const Ponto *a, const Ponto *b);

// ---- ponto.c --------------------------------------------------------------
struct ponto {
    double x;
    double y;
};

Ponto *ponto_cria(double x, double y) {
    Ponto *p = malloc(sizeof *p);
    if (p == NULL) {
        return NULL;
    }
    p->x = x;
    p->y = y;
    return p;
}

void ponto_libera(Ponto *p) {
    free(p);
}

double ponto_x(const Ponto *p) {
    return p->x;
}

double ponto_y(const Ponto *p) {
    return p->y;
}

double ponto_distancia(const Ponto *a, const Ponto *b) {
    double dx = b->x - a->x;
    double dy = b->y - a->y;
    return sqrt(dx * dx + dy * dy);
}

// ---- cliente --------------------------------------------------------------
int main(void) {
    Ponto *loja = ponto_cria(0, 0);
    Ponto *cliente = ponto_cria(3, 4);
    Ponto *a = ponto_cria(-2, 1);
    Ponto *b = ponto_cria(4, 9);
    if (loja == NULL || cliente == NULL || a == NULL || b == NULL) {
        printf("Sem memória\n");
    } else {
        printf("Loja (%.1f, %.1f) -> cliente (%.1f, %.1f): %.2f km\n", ponto_x(loja),
               ponto_y(loja), ponto_x(cliente), ponto_y(cliente),
               ponto_distancia(loja, cliente));
        printf("A -> B: %.2f km\n", ponto_distancia(a, b));
    }
    ponto_libera(loja);
    ponto_libera(cliente);
    ponto_libera(a);
    ponto_libera(b);
    return 0;
}
