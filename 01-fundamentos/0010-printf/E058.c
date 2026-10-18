// 0010 · printf
// Exercício E058 · ★★☆
//
// Este programa compila, mas o gcc mostra TRÊS avisos, e a saída sai
// errada (números sem sentido). Rode, leia cada aviso e conserte. O pedido
// tem 3 pizzas de R$ 45.90, total R$ 137.70.
//
//   Saída esperada (depois de consertar):
//   Pizzas: 3
//   Preço: R$ 45.90
//   Total: R$ 137.70
//
// Dicas:
// 1. Procure "format" nos avisos: cada um diz o que esperava e o que veio.
// 2. %d é para int e %f para double. Um % sem argumento lê lixo.
// 3. Resposta esperada: (1) %d com o double preco: use %.2f; (2) %.2f com o
//    int quantidade: use %d; (3) o terceiro printf tem %.2f, mas faltou o
//    argumento total.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int quantidade = 3;
    double preco = 45.90;
    double total = 137.70;

    printf("Pizzas: %.2f\n", quantidade);
    printf("Preço: R$ %d\n", preco);
    printf("Total: R$ %.2f\n");
    (void)total; // (só para o gcc não reclamar que total não é usado)
    return 0;
}
