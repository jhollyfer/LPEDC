// 0063 · Enum
// Exercício E378 · ★★★
//
// O app pediu uma nota para a entrega e recebeu 15 respostas:
//
//   ótima, boa, ok, ótima, ruim, boa, ótima, ótima,
//   péssima, boa, ok, ótima, boa, ótima, ruim
//
// Crie o enum Nota { PESSIMA, RUIM, OK, BOA, OTIMA, QTD_NOTAS } e guarde as
// respostas num vetor de Nota. Conte quantas de cada (um vetor int de
// QTD_NOTAS posições, indexado pela nota), mostre a porcentagem de cada uma e
// a satisfação (boa + ótima).
//
//   Saída esperada:
//   péssima: 1 (6.7%)
//   ruim: 2 (13.3%)
//   ok: 2 (13.3%)
//   boa: 4 (26.7%)
//   ótima: 6 (40.0%)
//   Satisfação: 66.7%
//
// Dicas:
// 1. QTD_NOTAS vale 5 e serve de tamanho: int contagem[QTD_NOTAS] = {0};
// 2. Os nomes também cabem num vetor: const char *nomes[QTD_NOTAS] = {...};
// 3. contagem[respostas[i]]++ conta sem nenhum if.
// 4. Cuidado com divisão inteira: 100.0 * contagem[n] / total.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
