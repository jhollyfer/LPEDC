// Lista · Módulo 02 · Decisões
// Exercício P0209 · ★☆☆ · O troco que não bate
//
// O caixa somou duas moedas de R$ 0.10 e R$ 0.20 e comparou com R$ 0.30 usando
// ==. O programa abaixo diz que o troco está errado, mas a conta está certa: o
// problema é a comparação de double, e ela está assim de propósito. Conserte o
// if: considere iguais os valores que diferem menos de 0.000001 (use fabs):
//
//   Saída esperada:
//   Soma: 0.30000000000000004
//   Troco certo.
//
// Dicas:
// 1. 0.1 e 0.2 não cabem exatos em binário: a soma fica um pouquinho acima de
//    0.3. Por isso o == falha.
// 2. if (fabs(soma - esperado) < 0.000001), com math.h.
// 3. Resposta esperada: Troco certo.
//
// Escreva sua resposta abaixo:

#include <math.h>
#include <stdio.h>

int main(void) {
    double soma = 0.10 + 0.20;
    double esperado = 0.30;

    printf("Soma: %.17f\n", soma);
    if (soma == esperado) {
        printf("Troco certo.\n");
    } else {
        printf("Troco errado!\n");
    }
    return 0;
}
