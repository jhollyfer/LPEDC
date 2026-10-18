// 0030 · Escopo e tempo de vida
// Exercício E177 · ★★☆
//
// Este programa deveria somar os quatro itens da compra (R$ 12.50, R$ 8.00,
// R$ 30.00 e R$ 4.75) e mostrar "Total: R$ 55.25". Ele compila sem aviso, mas
// mostra "Total: R$ 4.75". Explique o erro usando as palavras escopo e tempo
// de vida, e conserte.
//
// Dicas:
// 1. Em que momento a variável total nasce? Quantas vezes?
// 2. Uma variável declarada dentro do corpo do for é criada de novo a cada volta.
// 3. Resposta esperada: total é local do corpo do for: nasce com 0 a cada volta
//    e só guarda o último item. Declare "double total = 0;" antes do for e
//    mostre depois do laço: Total: R$ 55.25.
//
// Escreva sua resposta abaixo (conserte o código):

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
    for (int i = 1; i <= 4; i++) {
        double total = 0;
        total += preco_item(i);
        if (i == 4) {
            printf("Total: R$ %.2f\n", total);
        }
    }
    return 0;
}
