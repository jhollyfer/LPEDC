// 0125 · Subconjuntos
// Exercício E745 · ★☆☆
//
// O restaurante por quilo do trabalho tem uma marmita fixa (a carne) e três
// acompanhamentos opcionais: arroz, feijão e salada. Escreva do zero um
// programa que mostre todas as marmitas possíveis contando m de 0 a 7 e lendo
// os bits de m (bit 0 = arroz, bit 1 = feijão, bit 2 = salada), sem recursão.
//
//   Saída esperada:
//   0: só a carne
//   1: arroz
//   2: feijão
//   3: arroz feijão
//   4: salada
//   5: arroz salada
//   6: feijão salada
//   7: arroz feijão salada
//
// Dicas:
// 1. Com 3 itens, o laço de fora vai de 0 até (1 << 3) - 1.
// 2. O item i entra quando m & (1 << i) é diferente de zero.
// 3. Use uma variável para saber se algum item entrou; se nenhum entrou,
//    escreva "só a carne".
// 4. Resposta esperada: as 8 linhas acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
