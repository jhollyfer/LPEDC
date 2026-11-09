// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2630 · ★★★ · Três jeitos do melhor trecho
//
// O saldo diário de uma lanchonete (lucro ou prejuízo, em reais) está no
// vetor do main, gerado com saldo[i] = sorteia(201) - 100. Qual trecho de
// dias seguidos dá a maior soma? Escreva três versões, cada uma com seu
// contador de passos (no laço mais interno):
// - cubica: para cada início e fim, soma o trecho do zero: Θ(n³);
// - quadratica: para cada início, vai somando ao estender o fim: Θ(n²);
// - linear (Kadane): uma passada, guardando a melhor soma que termina no
//   dia atual: Θ(n).
// Rode com n = 100 e n = 200 e mostre a maior soma e os passos de cada uma:
//
//   Saída esperada:
//   n = 100
//     cubica    : soma 669,   171700 passos
//     quadratica: soma 669,     5050 passos
//     linear    : soma 669,      100 passos
//   n = 200
//     cubica    : soma 669,  1353400 passos
//     quadratica: soma 669,    20100 passos
//     linear    : soma 669,      200 passos
//
// Dicas:
// 1. As três têm que dar a mesma soma. A cúbica faz Σ dos tamanhos de todos
//    os trechos: n(n+1)(n+2)/6.
// 2. Kadane: atual = max(saldo[i], atual + saldo[i]); melhor = max(melhor,
//    atual).
// 3. Gere os 200 saldos uma vez só; o caso n = 100 usa os 100 primeiros.
// 4. Ao dobrar n, os passos vão perto de × 8, × 4 e × 2.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
