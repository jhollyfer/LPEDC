// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2812 · ★★☆ · Dispersão dupla
//
// Agora com dispersão dupla, numa tabela de m = 13: h(k, i) = (h1(k) + i ·
// h2(k)) mod 13, com h1(k) = k mod 13 e h2(k) = 1 + (k mod 11). Insira 14,
// 27, 40, 53, 66, 79 (todas com h1 = 1) e 5. Mostre o passo h2, a posição e
// as sondagens de cada uma, a tabela final e o total de sondagens.
//
//   Saída esperada:
//   14: passo  4 ->  1 (1 sondagens)
//   27: passo  6 ->  7 (2 sondagens)
//   40: passo  8 ->  9 (2 sondagens)
//   53: passo 10 -> 11 (2 sondagens)
//   66: passo  1 ->  2 (2 sondagens)
//   79: passo  3 ->  4 (2 sondagens)
//    5: passo  6 ->  5 (1 sondagens)
//   tabela: . 14 66 . 79 5 . 27 . 40 . 53 .
//   total de sondagens: 12
//
// Dicas:
// 1. h2 nunca é 0 por causa do + 1, e como 13 é primo, qualquer passo de 1
//    a 12 visita todas as posições.
// 2. Cada chave anda com o seu passo: as trilhas se separam logo na segunda
//    sondagem.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
