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
// Dicas:
// 1. decrementa é o espelho de incrementa: troque os papéis de 0 e 1.
// 2. Em carrega, o bit i de x é (x >> i) & 1 (assunto 0065).
// 3. 511 + 1 = 512 = 1000000000: os 10 bits mudam. 512 - 1 volta a 511:
//    os 10 mudam de novo. Cada operação custa 10, para sempre.
// 4. Resposta esperada: a saída acima. O argumento amortizado só vale
//    para a sequência de operações que ele analisou. Com o decremento, o
//    cofrinho que os incrementos baratos enchiam nunca chega a encher.
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
