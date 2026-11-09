// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1722 · ★★★ · A árvore de recursão de qualquer a T(n/b) + n^k

#include <stdio.h>

long potencia(long x, int k) {
    long r = 1;
    while (k-- > 0) r *= x;
    return r;
}

long custo(int a, int b, int k, long n) { // a própria recorrência
    if (n == 1) return 1;
    return potencia(n, k) + a * custo(a, b, k, n / b);
}

void arvore(int a, int b, int k, long n) {
    printf("T(n) = %d T(n/%d) + n^%d, n = %ld\n", a, b, k, n);
    printf("  nível      nós  tamanho  custo/nó  custo do nível\n");
    long nos = 1, total = 0;
    int nivel = 0;
    for (long m = n; m >= 1; m /= b, nos *= a, nivel++) {
        long c = potencia(m, k); // com m == 1, a folha custa 1
        printf("  %5d %8ld %8ld %9ld %15ld\n", nivel, nos, m, c, nos * c);
        total += nos * c;
        if (m == 1) break;
    }
    long bk = potencia(b, k);
    printf("  total da tabela %ld, da recursão %ld\n", total, custo(a, b, k, n));
    if (a > bk) printf("  r = %d/%ld > 1: as folhas dominam (caso 1)\n", a, bk);
    else if (a == bk) printf("  r = 1: %d níveis iguais (caso 2)\n", nivel + 1);
    else printf("  r = %d/%ld < 1: a raiz domina (caso 3)\n", a, bk);
}

int main(void) {
    arvore(8, 2, 2, 64);
    arvore(4, 2, 2, 64);
    arvore(2, 2, 2, 64);
    arvore(9, 3, 1, 81);
    return 0;
}
