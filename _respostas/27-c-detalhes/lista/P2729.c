// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2729 · ★★★ · O relatório de vendas com quatro bugs

#include <stdio.h>

#define POR_VENDEDOR(total, n) ((total) / (n)) // bug 3: faltavam parênteses

// mostra os dias do último para o primeiro e devolve quantos mostrou
size_t de_tras_para_frente(const int *v, size_t n) {
    size_t mostrados = 0;
    for (size_t i = n; i-- > 0;) { // bug 4: com n = 0, n - 1 dava a volta
        printf(" %d", v[i]);
        mostrados++;
    }
    return mostrados;
}

int main(void) {
    int dias[] = {400, 500, 600};
    int bonus_meta = 0; // a meta não foi batida
    int total = dias[0] + dias[1] + dias[2] + (bonus_meta > 0 ? 100 : 0); // bug 1: o ?: engolia a soma
    printf("total: R$ %d\n", total);

    int comissao = total * 5 / 100; // bug 2: 5 / 100 é 0 em inteiros
    printf("comissão (5%%): R$ %d\n", comissao);

    printf("média por vendedor: R$ %d\n", POR_VENDEDOR(total, 1 + 2));

    printf("dias de trás para a frente:");
    de_tras_para_frente(dias, 3);
    printf("\n");
    printf("vendas sem nenhum dia: %zu dias\n", de_tras_para_frente(dias, 0));
    return 0;
}
