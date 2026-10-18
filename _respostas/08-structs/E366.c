// 0061 · Vetor de structs
// Exercício E366 · ★★★

#include <math.h>
#include <stdio.h>

typedef struct {
    double x;
    double y;
} Ponto;

double area(Ponto p[], int n) {
    double soma = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        soma += p[i].x * p[j].y - p[j].x * p[i].y;
    }
    return fabs(soma) / 2;
}

double perimetro(Ponto p[], int n) {
    double total = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        double dx = p[j].x - p[i].x;
        double dy = p[j].y - p[i].y;
        total += sqrt(dx * dx + dy * dy);
    }
    return total;
}

int main(void) {
    Ponto terreno[] = {{0, 0}, {6, 0}, {6, 4}, {3, 7}, {0, 4}};
    int n = sizeof terreno / sizeof terreno[0];

    printf("Área: %.2f m2\n", area(terreno, n));
    printf("Perímetro: %.2f m\n", perimetro(terreno, n));
    return 0;
}
