// Lista · Módulo 02 · Decisões
// Exercício P0229 · ★★★ · A tarifa do aplicativo de corrida
//
// O aplicativo de corrida calcula assim: R$ 4.00 fixos, mais R$ 1.80 por km e
// R$ 0.35 por minuto. A tarifa dinâmica multiplica tudo por 1.5 quando está
// chovendo ou quando é sexta (5) ou sábado (6) a partir das 22h. A corrida
// nunca sai por menos de R$ 9.00. Por fim, o cupom dá 10% de desconto, mas no
// máximo R$ 8.00. Escreva o programa para uma corrida de 10 km e 20 minutos,
// num sábado às 23h, sem chuva, com cupom:
//
//   Saída esperada:
//   Preço base: R$ 29.00
//   Dinâmica: sim (x1.5)
//   Antes do cupom: R$ 43.50
//   Desconto do cupom: R$ 4.35
//   Total: R$ 39.15
//
// Dicas:
// 1. bool dinamica = chovendo || ((dia == 5 || dia == 6) && hora >= 22); os
//    parênteses importam.
// 2. Aplique na ordem: dinâmica, mínimo de R$ 9.00, cupom.
// 3. O desconto é preco * 0.10, mas se passar de 8.00 vira 8.00 (um ternário
//    resolve).
// 4. Resposta esperada: Total: R$ 39.15.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
