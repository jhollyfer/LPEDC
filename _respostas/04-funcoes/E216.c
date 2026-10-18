// 0036 · Juntando tudo: o caixa da lanchonete
// Exercício E216 · ★★★
//
// Por que quase o dobro: cada chamada que não está na borda gera exatamente
// duas, e as bordas devolvem 1. A árvore de chamadas tem uma folha por
// caminho, e uma árvore em que todo nó interno tem dois filhos tem
// (folhas - 1) nós internos: chamadas = 2 * caminhos - 1. O que se repete: a
// mesma esquina (c, l) é calculada de novo por cada caminho que passa por ela,
// como fib(3) dentro de fib(5).

#include <stdio.h>

long long chamadas = 0;

long long caminhos(int c, int l) {
    chamadas++;
    if (c == 0 || l == 0) {
        return 1;
    }
    return caminhos(c - 1, l) + caminhos(c, l - 1);
}

void mostrar(int n) {
    chamadas = 0;
    long long total = caminhos(n, n);
    printf("%d x %d: %lld caminhos (%lld chamadas)\n", n, n, total, chamadas);
}

int main(void) {
    mostrar(2);
    mostrar(3);
    mostrar(5);
    mostrar(12);
    return 0;
}
