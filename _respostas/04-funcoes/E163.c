// 0028 · Funções
// Exercício E163 · ★☆☆

#include <stdio.h>

double area_comodo(double largura, double comprimento);

int main(void) {
    double sala = area_comodo(4.0, 3.5);
    double quarto = area_comodo(3.0, 3.0);

    printf("Sala: %.2f m2\n", sala);
    printf("Quarto: %.2f m2\n", quarto);
    printf("Total: %.2f m2\n", sala + quarto);
    return 0;
}

double area_comodo(double largura, double comprimento) {
    return largura * comprimento;
}
