// 0035 · Escopo e tempo de vida
// Exercício E207 · ★★☆
//
// Resposta: total foi declarada dentro do corpo do for. O escopo dela é só
// aquele bloco e o tempo de vida é uma volta: a cada volta nasce outra total,
// com 0, e soma só o item da vez. Na última volta ela vale 4.75. Declarada
// antes do for, ela vive o laço inteiro e acumula.

#include <stdio.h>

double preco_item(int i) {
    if (i == 1) {
        return 12.50;
    }
    if (i == 2) {
        return 8.00;
    }
    if (i == 3) {
        return 30.00;
    }
    return 4.75;
}

int main(void) {
    double total = 0;
    for (int i = 1; i <= 4; i++) {
        total += preco_item(i);
    }
    printf("Total: R$ %.2f\n", total);
    return 0;
}
