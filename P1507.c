// Lista · Módulo 15 · Tabelas hash
// Exercício P1507 · ★☆☆ · O hash djb2 dos nomes
//
// Um hash clássico para strings é o djb2: começa com h = 5381 e, para cada
// caractere c, faz h = h * 33 + c. Complete a função djb2 (com
// unsigned long long, para o estouro ser bem definido) e mostre o hash e o
// balde (h % 16) de cada nome.
//
//   Saída esperada:
//   ana   193486357 -> balde 5
//   bia   193487281 -> balde 1
//   caio  6385107873 -> balde 1
//   davi  6385144233 -> balde 9
//   eva   193490977 -> balde 1
//   abc   193485963 -> balde 11
//   acb   193485995 -> balde 11
//
// Dicas:
// 1. Converta o char com (unsigned char)*s antes de somar.
// 2. Em unsigned, o estouro dá a volta (aritmética módulo 2⁶⁴); em int com
//    sinal, estourar é comportamento indefinido.
// 3. "abc" e "acb" têm hashes diferentes (a ordem conta, ao contrário da
//    soma dos códigos), mas a diferença é 32: com m = 16, potência de 2, só
//    os 4 bits de baixo contam, e eles batem. Um m primo separaria os dois.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

#define M 16

unsigned long long djb2(const char *s) {
    unsigned long long h = 5381;
    // complete aqui
    (void)s;
    return h;
}

int main(void) {
    const char *nomes[] = {"ana", "bia", "caio", "davi", "eva", "abc", "acb"};
    for (int i = 0; i < 7; i++) {
        unsigned long long h = djb2(nomes[i]);
        printf("%-5s %llu -> balde %llu\n", nomes[i], h, h % M);
    }
    return 0;
}
