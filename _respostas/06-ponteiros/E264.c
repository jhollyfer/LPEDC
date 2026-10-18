// 0044 · Memória e endereços
// Exercício E264 · ★★★

#include <stdio.h>

int total_vendas = 0;

void registra(int valor) {
    static int chamadas = 0;
    chamadas++;
    total_vendas += valor;
    printf("registra(%d): chamadas em %p, valor em %p\n", valor, (void *)&chamadas, (void *)&valor);
}

int main(void) {
    int caixa = 100;
    const char *loja = "Feira";

    registra(10);
    registra(20);
    printf("vivem o programa todo:\n");
    printf("  total_vendas em %p\n", (void *)&total_vendas);
    printf("  texto \"%s\" em %p\n", loja, (void *)loja);
    printf("nascem e morrem:\n");
    printf("  caixa em %p\n", (void *)&caixa);
    printf("total_vendas = %d\n", total_vendas);
    return 0;
}
