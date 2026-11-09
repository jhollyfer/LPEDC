// Lista · Módulo 03 · Laços
// Exercício P0301 · ★☆☆ · A tabela do pão francês

#include <stdio.h>

int main(void) {
    const double PRECO = 0.85;

    for (int qtd = 1; qtd <= 8; qtd++) {
        printf("%2d pão(es): R$ %5.2f\n", qtd, qtd * PRECO);
    }
    return 0;
}
