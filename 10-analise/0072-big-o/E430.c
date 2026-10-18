// 0072 · Notação O: como o custo cresce
// Exercício E430 · ★★☆
//
// A "regra do dobro": rode um algoritmo com n e com 2n e divida os passos.
// Razão perto de 1 (com +1 passo) é O(log n); perto de 2, O(n); perto de 4,
// O(n²). Complete o programa:
//
// 1. escreva const char *classe(double razao), que devolve "O(log n)" se a
// razão for menor que 1.2, "O(raiz n)" se for menor que 1.7, "O(n)" se for
// menor que 3 e "O(n^2)" nos outros casos;
// 2. no main, mostre, para cada função misteriosa, os passos com n = 1000 e
// n = 2000, a razão entre eles e a classe que a razão indica.
//
//   Saída esperada:
//   a:     334 ->     667  razão 2.00  O(n)
//   b:      10 ->      11  razão 1.10  O(log n)
//   c:  500000 -> 2000000  razão 4.00  O(n^2)
//   d:      32 ->      45  razão 1.41  O(raiz n)
//
// Dicas:
// 1. Use (double)p2 / p1 para a razão não virar divisão inteira.
// 2. Uma função void mostra(char nome, long p1, long p2) evita repetir o
//    printf quatro vezes.
// 3. A d) não é nenhuma das cinco classes do texto. Que número elevado ao
//    quadrado dá 2? Olhe a condição d * d < n.
// 4. Resposta esperada: a saída acima. a) n/3 passos; c) n²/2 passos;
//    d) raiz de n: dobrar n multiplica por √2 ≈ 1,41.
//
// Escreva sua resposta abaixo (complete o main):

#include <stdio.h>

long misterio_a(int n) {
    long passos = 0;
    for (int i = 0; i < n; i += 3) {
        passos++;
    }
    return passos;
}

long misterio_b(int n) {
    long passos = 0;
    for (int i = n; i > 0; i /= 2) {
        passos++;
    }
    return passos;
}

long misterio_c(int n) {
    long passos = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j += 2) {
            passos++;
        }
    }
    return passos;
}

long misterio_d(int n) {
    long passos = 0;
    for (int d = 0; d * d < n; d++) {
        passos++;
    }
    return passos;
}

int main(void) {
    // TODO: para cada função, mostre os passos com 1000 e 2000 e a razão
    printf("a: %7ld -> %7ld\n", misterio_a(1000), misterio_a(2000));
    return 0;
}
