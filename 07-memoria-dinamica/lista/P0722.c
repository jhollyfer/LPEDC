// Lista · Módulo 07 · Memória dinâmica
// Exercício P0722 · ★★★ · Somar duas matrizes esparsas
//
// Duas fiscalizações anotaram as multas por quarteirão de um bairro (grade de
// 100 x 100), e quase todos os quarteirões têm zero. Cada matriz é guardada
// como triplas (linha, coluna, valor) em ordem de linha e coluna, num vetor
// de int no heap (3 int por tripla):
//
//   int a[] = {0, 4, 2,   3, 7, 1,   3, 9, 5,   42, 0, 3};   // 4 triplas
//   int b[] = {3, 7, 4,   10, 10, 1,   42, 0, 2,   99, 99, 6}; // 4 triplas
//
// Escreva int *somar(const int *a, int na, const int *b, int nb, int *n),
// que devolve a soma também em triplas ordenadas, sem montar a grade de
// 10.000 casas: ande nas duas listas ao mesmo tempo (como na união do
// P0719), somando os valores quando a posição for a mesma. O resultado começa
// com capacidade 2 triplas e dobra com realloc. Mostre as triplas e quantos
// bytes a soma ocupa contra a grade cheia:
//
//   Saída esperada:
//   Soma (6 triplas): (0,4,2) (3,7,5) (3,9,5) (10,10,1) (42,0,5) (99,99,6)
//   Esparsa: 72 bytes; grade cheia: 40000 bytes
//
// Dicas:
// 1. Compare posições pela chave linha * 100 + coluna: quem tem a chave
//    menor entra primeiro.
// 2. Escreva bool anexar(int **v, int *n, int *cap, int l, int c, int x),
//    que cresce o vetor e acrescenta uma tripla em (*v)[3 * *n] em diante.
// 3. Se a soma de uma posição der 0, ela não entra (aqui não acontece, mas
//    a regra da matriz esparsa é guardar só o que não é zero).
// 4. Bytes: 3 * n * sizeof(int) contra 100 * 100 * sizeof(int).
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    int a[] = {0, 4, 2,   3, 7, 1,   3, 9, 5,   42, 0, 3};
    int b[] = {3, 7, 4,   10, 10, 1,   42, 0, 2,   99, 99, 6};
    (void) a, (void) b; // apague esta linha quando escrever

    return 0;
}
