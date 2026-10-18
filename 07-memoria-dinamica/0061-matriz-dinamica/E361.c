// 0061 · Matriz dinâmica
// Exercício E361 · ★☆☆
//
// Leia n e monte, com int ** (vetor de ponteiros), a tabuada n x n: a
// posição [i][j] guarda (i + 1) * (j + 1). Mostre a matriz com %4d e libere
// tudo na ordem certa.
//
//   Exemplo de uso:
//   Tamanho: 4
//      1   2   3   4
//      2   4   6   8
//      3   6   9  12
//      4   8  12  16
//
// Para testar: printf '4\n' | ~/LPEDC/rodar <este arquivo>
//
// Dicas:
// 1. int **t = malloc(n * sizeof *t); e, para cada i,
//    t[i] = malloc(n * sizeof *t[i]);
// 2. Libere cada t[i] e só depois t.
// 3. Resposta esperada: a tabela acima, sem relatório do AddressSanitizer.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
