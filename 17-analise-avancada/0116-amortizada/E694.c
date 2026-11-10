// 0116 · Análise amortizada
// Exercício E694 · ★★☆
//
// O contador binário tem custo amortizado menor que 2 por incremento. E se
// ele também puder DIMINUIR? Escreva:
//
// - decrementa(b): subtrai 1 do contador e devolve quantos bits mudaram
// (os 0 do fim viram 1, porque o empréstimo passa por eles, e o primeiro
// 1 vira 0);
// - carrega(b, x): coloca o número x nos bits (b[i] é o bit i de x);
// - um main que faz dois testes com um contador de 10 bits: 100
// incrementos a partir de 0, e 100 operações alternando incrementa e
// decrementa a partir de 511 (0111111111).
//
//   Saída esperada:
//   100 incrementos a partir de 0: 197 trocas (1.97 por operação)
//   inc/dec alternados a partir de 511: 1000 trocas (10.00 por operação)
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define BITS 10

int incrementa(int b[]) {
    int i = 0, trocas = 0;
    while (i < BITS && b[i] == 1) {
        b[i] = 0;
        trocas++;
        i++;
    }
    if (i < BITS) {
        b[i] = 1;
        trocas++;
    }
    return trocas;
}

int main(void) {

    return 0;
}
