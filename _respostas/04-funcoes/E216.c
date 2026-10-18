// 0036 · Juntando tudo: o caixa da lanchonete
// Exercício E216 · ★★★

#include <stdio.h>

long long chamadas = 0;
long long esquina = 0;

long long caminhos(int c, int l) {
    chamadas++;
    if (c == 1 && l == 1) {
        esquina++;
    }
    if (c == 0 || l == 0) {
        return 1; // borda: um caminho só
    }
    return caminhos(c - 1, l) + caminhos(c, l - 1);
}

void mostrar(int n) {
    chamadas = 0;
    esquina = 0;
    long long total = caminhos(n, n);
    printf("%d x %d: %lld caminhos, %lld chamadas (%s), esquina (1, 1): %lld vezes\n",
           n, n, total, chamadas,
           chamadas == 2 * total - 1 ? "confere" : "não confere", esquina);
}

int main(void) {
    mostrar(2);
    mostrar(3);
    mostrar(5);
    mostrar(12);
    return 0;
}
