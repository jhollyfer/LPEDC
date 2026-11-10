// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0501 · ★☆☆ · O melhor dia da padaria
//
// A padaria do bairro anotou o faturamento de cada dia da semana, em reais:
//
//   Dom 1830  Seg 920  Ter 1045  Qua 870  Qui 1110  Sex 1490  Sáb 2210
//
// Guarde os valores num vetor int vendas[7] e os nomes dos dias numa matriz
// de char dias[7][5]. Mostre o total da semana, a média (com 2 casas) e o dia
// de maior e o de menor faturamento, pelo nome.
//
//   Saída esperada:
//   Total da semana: R$ 9475
//   Média por dia: R$ 1353.57
//   Maior: Sáb (R$ 2210)
//   Menor: Qua (R$ 870)
//
// Dicas:
// 1. Comece com i_maior = i_menor = 0 e compare cada vendas[i] com
//    vendas[i_maior] e vendas[i_menor]. Guarde o ÍNDICE, não o valor.
// 2. Com o índice, o nome sai de dias[i_maior] e o valor de vendas[i_maior].
// 3. Para a média com casas, divida por 7.0, não por 7.
// 4. Por que [5] se "Sáb" tem 3 letras? Em UTF-8 o á ocupa 2 bytes: são 4
//    bytes mais o '\0'. Com [4], o '\0' não cabe e o printf passa do fim.
// 5. Resposta esperada: total 9475, média 1353.57, maior no sábado e menor na
//    quarta.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
