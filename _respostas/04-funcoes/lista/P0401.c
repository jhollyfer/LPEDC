// Lista · Módulo 04 · Funções e modularização
// Exercício P0401 · ★☆☆ · O desconto do Pix

#include <stdio.h>

double preco_pix(double preco) {
    return preco * 0.90; // 10% de desconto
}

int main(void) {
    printf("Tênis: R$ %.2f -> R$ %.2f no Pix\n", 299.90, preco_pix(299.90));
    printf("Mochila: R$ %.2f -> R$ %.2f no Pix\n", 159.00, preco_pix(159.00));
    printf("Boné: R$ %.2f -> R$ %.2f no Pix\n", 59.90, preco_pix(59.90));
    return 0;
}
