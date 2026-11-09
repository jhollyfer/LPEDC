// Lista · Módulo 25 · Estruturas especiais
// Exercício P2528 · ★★★ · As vendas lançadas fora de ordem

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int lin, col, valor;
} Tripla;

int compara(const void *a, const void *b) {
    const Tripla *x = a, *y = b;
    if (x->lin != y->lin) return x->lin - y->lin;
    return x->col - y->col;
}

// ordena, soma as repetidas e tira as que somaram zero; devolve o novo n
int normaliza(Tripla t[], int n) {
    qsort(t, n, sizeof(Tripla), compara);
    int m = 0;
    for (int i = 0; i < n;) {
        Tripla soma = t[i];
        int j = i + 1;
        while (j < n && t[j].lin == soma.lin && t[j].col == soma.col) soma.valor += t[j++].valor;
        if (soma.valor != 0) t[m++] = soma;
        i = j;
    }
    return m;
}

int main(void) {
    // (loja, dia, valor em R$); estorno é negativo
    Tripla vendas[] = {{2, 14, 300}, {0, 3, 120}, {1, 7, 80}, {0, 3, 45}, {2, 1, 60}, {1, 7, -80},
                       {0, 20, 210}, {2, 14, 150}, {1, 2, 95}, {0, 3, -30}, {2, 1, -60}, {1, 30, 40}};
    int n = 12;
    printf("Lançamentos: %d\n", n);
    n = normaliza(vendas, n);
    for (int k = 0; k < n; k++) printf("loja %d, dia %2d: R$ %d\n", vendas[k].lin, vendas[k].col, vendas[k].valor);
    printf("Triplas que ficaram: %d\n", n);
    return 0;
}
