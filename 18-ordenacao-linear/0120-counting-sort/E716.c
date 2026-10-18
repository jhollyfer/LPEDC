// 0120 · Counting sort
// Exercício E716 · ★☆☆
//
// A sapataria guarda quantos pares tem de cada tamanho, do 34 ao 44, e quer
// arrumar a prateleira em ordem de tamanho, um par ao lado do outro. Complete
// o programa: transforme a contagem em acumulado e, para cada tamanho que
// tem estoque, mostre em que posições da prateleira ele fica.
//
//   Saída esperada:
//   total: 27 pares
//   tamanho 34: posições 0 a 1
//   tamanho 36: posições 2 a 4
//   tamanho 37: posições 5 a 9
//   tamanho 38: posições 10 a 13
//   tamanho 39: posições 14 a 19
//   tamanho 40: posições 20 a 22
//   tamanho 41: posições 23 a 24
//   tamanho 43: posição 25
//   tamanho 44: posição 26
//
// Dicas:
// 1. Depois do acumulado, c[x] diz quantos pares têm tamanho até x + 34.
//    O total é o último contador.
// 2. O bloco do tamanho x vai de c[x - 1] até c[x] - 1. Para x = 0, o
//    começo é 0.
// 3. Bloco vazio (começo igual a c[x]) não aparece; bloco de um par só usa
//    "posição", no singular.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete o programa):

#include <stdio.h>

#define MENOR 34
#define K 11 // tamanhos de 34 a 44

int main(void) {
    // pares no estoque de cada tamanho: c[0] é o 34, c[10] é o 44
    int c[K] = {2, 0, 3, 5, 4, 6, 3, 2, 0, 1, 1};
    (void) c; // apague esta linha

    return 0;
}
