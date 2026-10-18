// 0139 · Troco com programação dinâmica
// Exercício E834 · ★★★
//
// A máquina de café do escritório custa R$ 1,00, aceita moedas de 5, 10, 25
// e 50 centavos, mas trava se você colocar mais de 6 moedas. Quantas
// combinações de moedas pagam exatamente R$ 1,00 com até 6 moedas? Mostre
// também quantas usam exatamente 1, 2, ..., 6 moedas.
//
// Um vetor jeitos[v] não basta: ele não sabe quantas moedas cada combinação
// usou. Acrescente essa informação como uma segunda dimensão:
// w[q][v] = combinações com EXATAMENTE q moedas que somam v centavos.
//
//   Saída esperada:
//   exatamente 1 moeda: 0
//   exatamente 2 moedas: 1
//   exatamente 3 moedas: 1
//   exatamente 4 moedas: 1
//   exatamente 5 moedas: 1
//   exatamente 6 moedas: 3
//   até 6 moedas: 7 combinações
//
// Dicas:
// 1. Base: w[0][0] = 1 (nenhuma moeda soma zero); o resto começa em 0.
// 2. Mantenha a estrutura das combinações (moeda no laço de fora, valor v
//    crescente por dentro) e acrescente um terceiro laço em q:
//    w[q][v] += w[q - 1][v - moeda].
// 3. Ao usar mais uma moeda, o valor cai de moeda e a contagem cai de 1.
// 4. Confira as 3 de seis moedas: 50+10+10+10+10+10, 50+25+10+5+5+5 e
//    25+25+25+10+10+5.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
