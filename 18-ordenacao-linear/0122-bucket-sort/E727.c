// 0122 · Bucket sort
// Exercício E727 · ★☆☆
//
// A loja de R$ 1,99 virou "loja até R$ 50" e quer separar os produtos em 5
// prateleiras de preço: de 0 a 10, de 10 a 20, ..., de 40 a 50. Escreva
// int balde_de(double x, double max, int nb), que devolve o balde (de 0 a
// nb - 1) de um valor x entre 0 e max, com nb baldes de mesma largura. O
// preço máximo, R$ 50,00, vai para o último balde. Mostre o balde de cada
// preço.
//
//   Saída esperada:
//   R$ 12.50 -> balde 1
//   R$ 49.99 -> balde 4
//   R$ 50.00 -> balde 4
//   R$  0.00 -> balde 0
//   R$ 10.00 -> balde 1
//   R$ 37.20 -> balde 3
//   R$  9.99 -> balde 0
//
// Dicas:
// 1. x / max dá um número de 0 a 1; vezes nb, de 0 a nb. A parte inteira
//    é o balde: (int) (x / max * nb).
// 2. Só o próprio max dá nb, que não existe. Trate esse caso com um if.
// 3. Formato: "R$ %5.2f -> balde %d\n".
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    double precos[] = {12.50, 49.99, 50.00, 0.00, 10.00, 37.20, 9.99};
    (void) precos; // apague esta linha

    return 0;
}
