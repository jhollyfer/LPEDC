// 0099 · Merge sort
// Exercício E594 · ★★★
//
// Ana e Bia ranquearam as mesmas 8 séries. Numerando as séries pela ordem da
// Bia, o ranking da Ana fica: 3, 1, 7, 2, 8, 4, 6, 5. Quanto mais INVERSÕES
// (pares fora de ordem) esse vetor tem, mais os gostos discordam. É assim que
// sites de recomendação medem "pessoas parecidas com você".
//
// Contar inversões com dois laços é O(n²). Faça em O(n log n) pegando carona
// no merge sort: durante a intercalação, toda vez que um elemento da metade
// DIREITA sai antes, ele estava invertido com todos os que ainda restam na
// esquerda. Mostre o resultado do jeito rápido e confira com a força bruta.
//
//   Saída esperada:
//   força bruta: 10 discordâncias
//   merge sort:  10 discordâncias
//   de 28 pares possíveis
//
// Dicas:
// 1. Se v[j] (direita) vai para o rascunho e ainda há q - i elementos na
//    esquerda, some q - i às inversões.
// 2. conta(p, r) = conta(p, q) + conta(q, r) + o que a intercalação achou.
// 3. Rode a força bruta ANTES: a versão rápida ordena o vetor.
// 4. Use long long: com n = 100 mil, as inversões passam de 2 bilhões.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
