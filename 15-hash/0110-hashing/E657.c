// 0110 · A ideia e a função hash
// Exercício E657 · ★★☆
//
// Complete a função hash_pol, que calcula o hash polinomial de base 31 de uma
// string e devolve o resto por M (13). A regra: começa com h = 0 e, para cada
// byte da string, faz h = h * 31 + byte. Use unsigned para h e converta
// cada char para unsigned char antes de somar.
//
//   Saída esperada:
//   pix    -> 0
//   ted    -> 8
//   doc    -> 8
//   boleto -> 1
//
// Dicas:
// 1. O laço é o mesmo da soma; só muda a conta de dentro.
// 2. Não se preocupe se h estourar: em unsigned a conta dá a volta, e isso
//    é bem definido em C.
// 3. Resposta esperada: a saída acima ("ted" e "doc" colidem com M = 13).
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

#define M 13

unsigned hash_pol(const char *s) {
    unsigned h = 0;
    (void)s; // apague esta linha quando usar s

    // complete aqui

    return h % M;
}

int main(void) {
    const char *meios[] = {"pix", "ted", "doc", "boleto"};
    for (int i = 0; i < 4; i++) {
        printf("%-6s -> %u\n", meios[i], hash_pol(meios[i]));
    }
    return 0;
}
