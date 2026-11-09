// Lista · Módulo 25 · Estruturas especiais
// Exercício P2528 · ★★★ · As vendas lançadas fora de ordem
//
// O caixa das três lojas lançou as vendas do mês como triplas (loja, dia,
// valor em R$) na ordem em que foram chegando, com repetições (duas vendas
// no mesmo dia) e estornos (valor negativo). Para virar uma matriz esparsa
// de verdade, as triplas precisam estar em ordem, sem repetidas e sem
// zero. Escreva normaliza(t, n), que ordena com qsort por (loja, dia),
// junta as repetidas somando os valores e descarta as que somaram zero, no
// próprio vetor, e devolve quantas sobraram.
//
//   Lançamentos:
//   (2,14,300) (0,3,120) (1,7,80) (0,3,45) (2,1,60) (1,7,-80)
//   (0,20,210) (2,14,150) (1,2,95) (0,3,-30) (2,1,-60) (1,30,40)
//
//   Saída esperada:
//   Lançamentos: 12
//   loja 0, dia  3: R$ 135
//   loja 0, dia 20: R$ 210
//   loja 1, dia  2: R$ 95
//   loja 1, dia 30: R$ 40
//   loja 2, dia 14: R$ 450
//   Triplas que ficaram: 5
//
// Dicas:
// 1. Depois do qsort, as repetidas ficam vizinhas: some um grupo inteiro
//    de (loja, dia) iguais antes de decidir se ele fica.
// 2. Escreva por cima do próprio vetor com um índice m que anda mais
//    devagar que o de leitura.
// 3. Resposta esperada: 5 triplas; loja 0, dia 3 fica com R$ 135 e a
//    loja 1 perde o dia 7 (80 - 80 = 0).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
