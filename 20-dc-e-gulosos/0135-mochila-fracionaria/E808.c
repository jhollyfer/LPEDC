// 0135 · Mochila fracionária
// Exercício E808 · ★★☆
//
// A mochila fracionária ao contrário: em vez de MAXIMIZAR o valor levado,
// MINIMIZAR o custo de uma compra. Um posto precisa de 30 000 litros de
// gasolina. Quatro distribuidoras vendem, cada uma, até um limite de litros
// por um preço fixo por litro:
//
//   A: até 12 000 L a R$ 5,10    B: até 8 000 L a R$ 4,95
//   C: até 15 000 L a R$ 5,25    D: até 6 000 L a R$ 4,89
//
// Compre da mais barata para a mais cara, até completar. Guarde os preços
// em CENTAVOS (int) e o custo em centavos num long long; mostre em reais
// com / 100 e % 100.
//
//   Saída esperada:
//   D:  6000 L a R$ 4.89 = R$ 29340.00
//   B:  8000 L a R$ 4.95 = R$ 39600.00
//   A: 12000 L a R$ 5.10 = R$ 61200.00
//   C:  4000 L a R$ 5.25 = R$ 21000.00
//   Total: R$ 151140.00
//
// Dicas:
// 1. Uma struct Oferta { char nome; int litros; int centavos; } e qsort em
//    ordem CRESCENTE de preço.
// 2. compra = o menor entre a oferta e o que falta. O custo parcial é
//    (long long)compra * centavos: 12000 * 510 já passa de 6 milhões, e com
//    pedidos maiores um int estouraria.
// 3. Resposta esperada: a saída acima. Para mostrar R$ 4.89 a partir de 489:
//    printf("%d.%02d", 489 / 100, 489 % 100).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
