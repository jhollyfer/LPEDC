// 0008 · Conversão e cast
// Exercício E044 · ★☆☆
//
// Cada linha do programa abaixo tem, no comentário, o valor que a pessoa
// QUERIA guardar. Algumas guardam outra coisa. Acrescente um printf para
// cada variável (%d para int, %.1f para double, %c para char), rode e
// conserte as linhas erradas mexendo só no lado direito do =, sem trocar o
// tipo de nenhuma variável, até a saída ficar igual à esperada.
//
//   Saída esperada (depois de consertar):
//   a = 7
//   b = 3.5
//   c = 3.5
//   d = -7
//   e = B
//   f = 3.5
//   g = 3
//
// Dicas:
// 1. Na atribuição, o valor vira o tipo da esquerda: real para int corta a
//    parte fracionária, em direção ao zero.
// 2. A conta da direita é feita primeiro, com os tipos dela: 7 / 2 entre
//    dois int dá 3, e só depois vira 3.0.
// 3. Resposta esperada: só b e f estavam erradas (as duas mostravam 3.0).
//    Conserto: double b = 7 / 2.0; e double f = (double) 7 / 2; (o cast
//    antes da divisão). E as sete linhas acima.
//
// Escreva sua resposta abaixo (complete e conserte o código):

#include <stdio.h>

int main(void) {
    int a = 7.9;                  // quero 7
    double b = 7 / 2;             // quero 3.5
    double c = 7 / 2.0;           // quero 3.5
    int d = -7.9;                 // quero -7
    char e = 66;                  // quero 'B'
    double f = (double) (7 / 2);  // quero 3.5
    int g = (int) 3.999;          // quero 3

    (void)a; (void)b; (void)c; (void)d; (void)e; (void)f; (void)g; // apague esta linha
    return 0;
}
