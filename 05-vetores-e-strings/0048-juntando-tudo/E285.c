// 0048 · Juntando tudo
// Exercício E285 · ★★☆
//
// Uma rodada de forca, com tudo fixo no código: a palavra secreta é "BANANA"
// e os chutes, na ordem, estão no vetor abaixo. Depois de cada chute, mostre
// a palavra com '_' nas letras ainda escondidas (separadas por espaço) e, se
// a letra não existir na palavra, conte um erro. Pare assim que a palavra
// estiver completa (os chutes que sobrarem não são usados).
//
//   char secreta[] = "BANANA";
//   char chutes[] = {'A', 'E', 'N', 'B', 'O'};
//
//   Saída esperada:
//   Chute A: _ A _ A _ A
//   Chute E: _ A _ A _ A (erro 1)
//   Chute N: _ A N A N A
//   Chute B: B A N A N A
//   Venceu com 1 erro(s)!
//
// Dicas:
// 1. Um vetor de bool revelada[6], tudo false no começo. Cada chute marca true
//    nas posições onde secreta[i] == chute.
// 2. Se o chute não marcou nenhuma posição, é erro.
// 3. Para saber se venceu: todas as posições reveladas? Escreva uma função
//    bool completa(const bool revelada[], int n).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void) {

    return 0;
}
