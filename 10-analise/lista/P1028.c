// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1028 · ★★★ · Quantos times de futsal? Recursão contra tabela
//
// Com 12 jogadores, quantos times de 5 dá para montar? É C(12, 5), e a
// relação de Pascal diz que C(n, k) = C(n - 1, k - 1) + C(n - 1, k), com
// C(n, 0) = C(n, n) = 1. Escreva:
//
//   long comb_rec(int n, int k, long *chamadas)
//     a recursão direta da fórmula, contando todas as chamadas;
//   long comb_tabela(int n, int k, long *somas)
//     monta o triângulo de Pascal linha por linha numa matriz long
//     t[21][21], só até a coluna k, contando as somas.
//
// Mostre os dois para C(12, 5) e C(20, 10).
//
//   Saída esperada:
//   C(12, 5) = 792 | recursão: 1583 chamadas | tabela: 45 somas
//   C(20, 10) = 184756 | recursão: 369511 chamadas | tabela: 145 somas
//
// Dicas:
// 1. A árvore de chamadas da recursão tem uma folha (valor 1) para cada
//    unidade do resultado, então tem C(n, k) folhas e 2 · C(n, k) - 1 nós:
//    o custo cresce como o próprio resultado, que é exponencial.
// 2. Na tabela, t[i][0] = 1 e t[i][i] = 1; para 0 < j < i e j <= k,
//    t[i][j] = t[i-1][j-1] + t[i-1][j]. São O(n · k) somas.
// 3. A recursão recalcula os mesmos C(a, b) muitas e muitas vezes; a tabela
//    calcula cada um uma vez só. É a ideia da programação dinâmica.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
