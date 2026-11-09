// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1726 · ★★★ · Busca na tabela de fretes: escada contra quadrantes
//
// A transportadora tem uma tabela n × n de fretes, em reais, crescente em
// cada linha (peso) e em cada coluna (distância): frete[i][j] = 10i + 7j.
// Dado um valor, ela quer saber se ele aparece na tabela. Escreva as duas
// buscas e conte as comparações com elementos da tabela:
//
// - ESCADA: comece no canto de cima à direita. Se o valor é menor, vá para a
//   esquerda; se é maior, desça. No máximo 2n - 1 passos: Θ(n).
// - QUADRANTES: compare com o elemento do meio m = frete[mi][mj]. Se o valor
//   é menor, ele não está no quadrante de baixo à direita (linhas >= mi e
//   colunas >= mj); se é maior, não está no de cima à esquerda (linhas <= mi
//   e colunas <= mj). Procure recursivamente nos TRÊS pedaços que sobram. A
//   recorrência é T(n) = 3 T(n/2) + 1, caso 1: Θ(n^(lg 3)) ≈ Θ(n^1,585).
//
// Para n = 8, 16, 32 e 64, procure TODOS os valores de 0 até o maior da
// tabela e mostre o pior caso de cada busca, 2n - 1 e n^(lg 3). Confira que as
// duas buscas concordam em todos os valores.
//
//   Saída esperada:
//    n  escada  2n-1  quadrantes  n^lg3  concordam
//    8      15    15          40     27        sim
//   16      25    31         121     81        sim
//   32      41    63         364    243        sim
//   64      73   127        1093    729        sim
//
// Dicas:
// 1. A busca por quadrantes trabalha num retângulo (l0, c0, l1, c1); se ele
//    está vazio (l0 > l1 ou c0 > c1), devolve falso sem comparar.
// 2. Com mi = (l0 + l1) / 2 e mj = (c0 + c1) / 2, os três pedaços para
//    "valor menor" são (l0, c0, mi - 1, mj - 1), (l0, mj, mi - 1, c1) e
//    (mi, c0, l1, mj - 1). Para "valor maior": (l0, mj + 1, mi, c1),
//    (mi + 1, c0, l1, mj) e (mi + 1, mj + 1, l1, c1).
// 3. Dividir parece sempre melhor, mas aqui não é: três subproblemas de
//    metade do lado dão n^1,585, que perde de 2n.
// 4. Resposta esperada: as buscas concordam; com n = 64, a escada faz no
//    pior caso 73 comparações (o limite é 127) e a de quadrantes, 1093.
//
// Escreva sua resposta abaixo:

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX 64

int frete[MAX][MAX];

int main(void) {
    int n = 8;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) frete[i][j] = 10 * i + 7 * j;

    printf("maior: %d\n", frete[n - 1][n - 1]);
    return 0;
}
