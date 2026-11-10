// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2626 · ★★★ · Mesma soma, pilha menor
//
// A soma recursiva soma(v, n) = v[n-1] + soma(v, n-1) empilha n + 1 frames.
// Escreva soma_meio(v, ini, fim), também recursiva, que divide o pedaço ao
// meio e soma as duas metades (pedaço vazio dá 0, pedaço de 1 dá o próprio
// valor). Meça chamadas e profundidade máxima das duas versões para os
// 100000 consumos de energia do main (consumo[i] = i % 50 + 100):
//
//   Saída esperada:
//   linear: soma 12450000, 100001 chamadas, profundidade 100001
//   metade: soma 12450000, 199999 chamadas, profundidade 18
//
// Dicas:
// 1. soma_meio faz uns 2n chamadas (o tempo continua Θ(n)), mas a
//    profundidade cai para uns log2 n + 1.
// 2. Use dois contadores globais por versão, ou zere os mesmos antes de cada
//    medida.
// 3. Espaço Θ(n) contra Θ(log n), com o mesmo resultado e o mesmo tempo.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
