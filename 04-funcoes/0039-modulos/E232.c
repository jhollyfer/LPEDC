// 0039 · Módulos: .h, .c e compilação separada
// Exercício E232 · ★★☆
//
// Este programa NÃO gera o executável, de propósito. Ele imita um módulo num
// arquivo só: o protótipo em cima (como se viesse de um desconto.h) e a
// definição embaixo (como se estivesse no desconto.c). Rode e leia a mensagem.
// Responda: quem reclamou, o compilador ou o ligador? Por que o compilador
// deixou passar? Conserte.
//
// Dicas:
// 1. Procure "undefined reference" na mensagem.
// 2. Compare letra por letra o nome do protótipo com o nome da definição.
// 3. Resposta esperada: o ligador ("undefined reference to
//    aplicar_desconto"). O compilador confere cada chamada contra o protótipo,
//    e o protótipo existe, então ele confia e deixa o buraco. A definição se
//    chama aplica_desconto: é outra função, e ninguém definiu
//    aplicar_desconto. Acertando o nome: "Tênis: R$ 239.92".
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

// "desconto.h"
double aplicar_desconto(double preco, double percentual);

int main(void) {
    printf("Tênis: R$ %.2f\n", aplicar_desconto(299.90, 20));
    return 0;
}

// "desconto.c"
double aplica_desconto(double preco, double percentual) {
    return preco - preco * percentual / 100;
}
