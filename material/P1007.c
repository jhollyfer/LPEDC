// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1007 · ★☆☆ · O caixa que o invariante dedurou
//
// A função soma abaixo devia somar as vendas do dia, e alguém já deixou o
// invariante escrito num assert: no começo de cada volta, s é a soma de
// v[0..i-1]. Rode: o assert dispara logo na primeira volta, porque o laço
// tem um erro de propósito. Conserte o LAÇO (não mexa no assert) para a
// saída ficar:
//
//   Saída esperada:
//   Caixa do dia: R$ 187
//   Média por venda: R$ 46.75
//
// Dicas:
// 1. Na primeira volta, quanto vale s e quanto vale soma_ate(v, i)?
// 2. Que venda o laço nunca soma?
// 3. Resposta esperada: o for começa em i = 1 e pula a primeira venda; com
//    i = 0 o invariante vale em toda volta e a soma dá 45 + 30 + 62 + 50 =
//    187.
//
// Escreva sua resposta abaixo (conserte o código):

#include <assert.h>
#include <stdio.h>

// soma de v[0..k-1], do jeito mais simples (só para conferir)
int soma_ate(const int v[], int k) {
    int s = 0;
    for (int j = 0; j < k; j++) {
        s += v[j];
    }
    return s;
}

int soma(const int v[], int n) {
    int s = 0;
    int i;
    for (i = 1; i < n; i++) {
        assert(s == soma_ate(v, i)); // invariante
        s += v[i];
    }
    assert(s == soma_ate(v, n)); // término
    return s;
}

int main(void) {
    int vendas[4] = {45, 30, 62, 50};
    int total = soma(vendas, 4);
    printf("Caixa do dia: R$ %d\n", total);
    printf("Média por venda: R$ %.2f\n", total / 4.0);
    return 0;
}
