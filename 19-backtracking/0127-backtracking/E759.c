// 0127 · Backtracking
// Exercício E759 · ★★☆
//
// A caminhonete do frete aguenta 100 kg e há cinco caixas para levar, com
// 47, 39, 28, 23 e 16 kg. Não dá para levar todas. Que caixas levar para
// aproveitar ao máximo a carga, sem passar de 100 kg? Agora não existe um
// alvo exato: o backtracking precisa guardar a MELHOR solução vista até o
// momento. Escreva o programa do zero.
//
//   Saída esperada:
//   melhor carga: 98 kg
//   caixas: 47 28 23
//
// Dicas:
// 1. A poda continua: se a soma passou de 100, volte.
// 2. Em toda chamada que não foi podada, compare soma com a melhor até
//    agora. Se for maior, guarde a soma e copie leva[0..i-1] para um vetor
//    melhor[] (e zere melhor[i..N-1]).
// 3. Não pare quando achar uma carga boa: só no fim da busca você sabe que
//    ela é a melhor.
// 4. Bônus: uma segunda poda corta os ramos em que soma + (tudo o que
//    ainda falta decidir) não passa da melhor carga até agora.
// 5. Resposta esperada: as 2 linhas acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
