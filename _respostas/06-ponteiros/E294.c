// 0049 · Memória e endereços
// Exercício E294 · ★★★
//
// Resposta: total_vendas, chamadas e o texto "Feira" ficam numa região baixa
// (0x55... ou 0x56...); caixa e valor ficam na pilha (0x7f...). O endereço
// de chamadas se repete nas duas chamadas (static vive o programa todo).

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
    printf("total_vendas em %p (vale %d)\n", (void *)&total_vendas, total_vendas);
    printf("texto \"%s\" em %p\n", loja, (void *)loja);
    printf("caixa em %p (vale %d)\n", (void *)&caixa, caixa);
    return 0;
}
