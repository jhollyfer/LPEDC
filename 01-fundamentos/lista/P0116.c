// Lista · Módulo 01 · Fundamentos de C
// Exercício P0116 · ★★☆ · O centavo que sumiu
//
// O caixa da padaria guarda o preço em reais (double) e converte para centavos
// inteiros antes de mandar para a maquininha. Com o pão a R$ 4.35, a maquininha
// recebe 434 centavos. O programa abaixo tem esse erro de propósito: conserte a
// conversão para a maquininha receber 435, e mostre os dois valores:
//
//   Saída esperada:
//   Preço: R$ 4.35
//   Centavos com (int): 434
//   Centavos com round: 435
//
// Dicas:
// 1. 4.35 não cabe exato em binário: 4.35 * 100 dá 434.99999999999994, e o
//    (int) corta tudo depois da vírgula.
// 2. Arredonde antes de converter: (int)round(preco * 100), com math.h.
// 3. Resposta esperada: 434 com (int) e 435 com round.
//
// Escreva sua resposta abaixo:

#include <math.h>
#include <stdio.h>

int main(void) {
    double preco = 4.35;
    int centavos = (int)(preco * 100);

    printf("Preço: R$ %.2f\n", preco);
    printf("Centavos para a maquininha: %d\n", centavos);
    return 0;
}
