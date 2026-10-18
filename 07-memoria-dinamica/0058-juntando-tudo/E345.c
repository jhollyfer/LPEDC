// 0058 · Juntando tudo
// Exercício E345 · ★★☆
//
// Leia frutas, uma por linha, até aparecer a palavra fim. Guarde cada uma
// num vetor de strings (char **) que começa com capacidade 1 e dobra quando
// enche. Mostre as frutas na ordem contrária e quantas vezes o vetor
// cresceu.
//
//   Exemplo de uso:
//   uva
//   manga
//   caju
//   acerola
//   fim
//   Ao contrário: acerola caju manga uva
//   O vetor cresceu 2 vezes
//
// Para testar: printf 'uva\nmanga\ncaju\nacerola\nfim\n' | ~/LPEDC/rodar <este arquivo>
//
// Dicas:
// 1. Leia com fgets num buffer, tire o '\n' e compare com strcmp(buffer,
//    "fim").
// 2. O realloc é no vetor de ponteiros (sizeof(char *) por posição); cada
//    fruta ganha o seu próprio malloc de strlen + 1.
// 3. Resposta esperada: "Ao contrário: acerola caju manga uva" e 2 vezes
//    (1 -> 2 -> 4). No fim, um free por fruta e um para o vetor.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
