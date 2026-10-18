// 0034 · Módulos: .h, .c e compilação separada
// Exercício E202 · ★★☆
//
// Resposta: quem reclama é o ligador ("undefined reference to
// aplicar_desconto"). O compilador confere a chamada contra o protótipo; como
// o protótipo existe, ele confia que a função está em algum lugar e deixa um
// buraco no .o. A definição se chamava aplica_desconto, que é outra função; o
// ligador procura aplicar_desconto e não acha.

#include <stdio.h>

// "desconto.h"
double aplicar_desconto(double preco, double percentual);

int main(void) {
    printf("Tênis: R$ %.2f\n", aplicar_desconto(299.90, 20));
    return 0;
}

// "desconto.c"
double aplicar_desconto(double preco, double percentual) {
    return preco - preco * percentual / 100;
}
