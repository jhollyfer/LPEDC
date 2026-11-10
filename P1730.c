// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1730 · ★★★ · Contador em que trocar o bit i custa 2^i
//
// No contador binário comum, trocar qualquer bit custa 1, e n incrementos
// custam menos que 2n: O(1) amortizado. Agora imagine um contador de placas
// mecânicas em que a placa i é 2^i vezes mais pesada: trocar o bit i custa
// 2^i. O custo amortizado continua constante?
//
// Análise agregada: em n = 2^k incrementos a partir de 0, o bit i (i < k)
// troca n/2^i vezes, a 2^i cada: n por bit. Com k bits trocando, e mais a
// placa k ligada uma vez no fim (custo 2^k = n), o total é n(k + 1) =
// n(lg n + 1). Amortizado: lg n + 1, que CRESCE com n.
//
// Escreva o contador (24 bits) com os dois custos e mostre, para n = 2^k com
// k = 4, 8, 12, 16 e 20: o custo total comum, o total pesado, n(lg n + 1) e o
// custo pesado por incremento.
//
//   Saída esperada:
//         n    comum      pesado  n(lg n + 1)  pesado/n
//        16       31          80           80       5.0
//       256      511        2304         2304       9.0
//      4096     8191       53248        53248      13.0
//     65536   131071     1114112      1114112      17.0
//   1048576  2097151    22020096     22020096      21.0
//
// Dicas:
// 1. Um só incrementa() devolve as duas contagens por ponteiro: some 1 em
//    *comum e 1 << i em *pesado a cada bit i trocado.
// 2. Use long para o custo pesado: com n = 2^20, passa de 20 milhões.
// 3. A análise agregada não muda de método, só de conta: o que importa é
//    quantas vezes cada bit troca, multiplicado pelo preço do bit.
// 4. Resposta esperada: o comum fica em 2n - 1; o pesado bate com
//    n(lg n + 1) em todas as linhas (21 por incremento com n = 2^20).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define K 24

int b[K];

int main(void) {

    return 0;
}
