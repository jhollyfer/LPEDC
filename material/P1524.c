// Lista · Módulo 15 · Tabelas hash
// Exercício P1524 · ★★★ · Os períodos em que o caixa zerou
//
// O caixa da cantina registrou as movimentações de 10 dias, em reais:
// 50, -20, -30, 10, 40, -50, 20, -20, 30, -30. Quantos PERÍODOS de dias
// seguidos (do dia i ao dia j) têm soma exatamente zero?
//
// Truque: com S(j) = soma dos dias 1..j (e S(0) = 0), o período i+1..j zera
// quando S(j) == S(i). Então, para cada dia j, a resposta ganha o número de
// vezes que o saldo S(j) já tinha aparecido antes. Guarde essas contagens
// numa tabela hash aberta (m = 31, sondagem linear) com três vetores
// globais: int usada[31], soma[31], vezes[31]. Comece registrando S(0) = 0
// uma vez. Mostre cada dia que fecha algum período e, no fim, compare com a
// força bruta.
//
//   Saída esperada:
//   dia 3 (saldo 0): +1
//   dia 5 (saldo 50): +1
//   dia 6 (saldo 0): +2
//   dia 8 (saldo 0): +3
//   dia 9 (saldo 30): +1
//   dia 10 (saldo 0): +4
//   períodos que zeram: 12 (força bruta: 12)
//
// Dicas:
// 1. Os saldos podem ser negativos, e em C -7 % 31 é -7. Use
//    h(k) = ((k % M) + M) % M para cair sempre entre 0 e M - 1.
// 2. Como 0 pode ser um saldo de verdade, não dá para usar 0 como "vazio":
//    por isso o vetor usada[].
// 3. O dia 5 fecha o período 2..5 (-20 - 30 + 10 + 40 = 0): o saldo 50 já
//    tinha aparecido no dia 1.
// 4. O hash deixa O(n); a força bruta (todos os pares i, j) é O(n²).
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define M 31

int usada[M], soma[M], vezes[M];

int main(void) {
    int mov[] = {50, -20, -30, 10, 40, -50, 20, -20, 30, -30};
    (void)mov;

    return 0;
}
