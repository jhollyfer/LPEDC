// 0023 · Break e continue
// Exercício E138 · ★★★

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    double soma = 0.0, nota;
    int contadas = 0;
    bool continuar = true;

    while (continuar) {
        printf("Nota (-1 encerra): ");
        if (scanf("%lf", &nota) != 1 || nota < 0) {
            continuar = false;
        } else if (nota > 10) {
            printf("  nota %.1f ignorada\n", nota);
        } else {
            soma += nota;
            contadas++;
        }
    }
    if (contadas > 0) {
        printf("Média de %d notas: %.2f\n", contadas, soma / contadas);
    }
    return 0;
}
