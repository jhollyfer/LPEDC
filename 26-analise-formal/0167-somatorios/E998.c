// 0167 · Somatórios que saem de laços
// Exercício E998 · ★☆☆
//
// A função abaixo compara cada produto da prateleira com ele mesmo e com
// os que vêm depois. O laço de dentro começa em j = i. Conte os
// passos com um contador global (passos++ dentro do laço de dentro) e
// mostre a contagem ao lado da fórmula n(n+1)/2 para n = 10, 100 e 1000:
//
//   Saída esperada:
//       n  passos  n(n+1)/2
//      10      55        55
//     100    5050      5050
//    1000  500500    500500
//
// Dicas:
// 1. Zere o contador antes de cada chamada.
// 2. Para i = 0, o laço de dentro roda n vezes; para i = n-1, uma vez.
//    A soma é n + (n-1) + ... + 1.
// 3. Calcule a fórmula com n do tipo long.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (mude o programa):

#include <stdio.h>

void confere_prateleira(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // compara o produto i com o produto j
        }
    }
}

int main(void) {
    confere_prateleira(10);
    printf("prateleira conferida\n");
    return 0;
}
