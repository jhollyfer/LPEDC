// Lista · Módulo 08 · Tipos compostos
// Exercício P0801 · ★☆☆ · A distância entre as paradas

#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y;
} Ponto;

double distancia(Ponto a, Ponto b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    return sqrt(dx * dx + dy * dy);
}

Ponto meio(Ponto a, Ponto b) {
    return (Ponto) {(a.x + b.x) / 2, (a.y + b.y) / 2};
}

int main(void) {
    Ponto paradas[4] = {{0.0, 0.0}, {3.0, 4.0}, {6.0, 8.0}, {6.0, 11.5}};
    double total = 0;

    for (int i = 0; i < 3; i++) {
        double d = distancia(paradas[i], paradas[i + 1]);
        printf("Parada %d -> %d: %.2f km\n", i + 1, i + 2, d);
        total += d;
    }
    Ponto m = meio(paradas[0], paradas[3]);
    printf("Total: %.2f km\n", total);
    printf("Abrigo no meio: (%.2f, %.2f)\n", m.x, m.y);
    return 0;
}
