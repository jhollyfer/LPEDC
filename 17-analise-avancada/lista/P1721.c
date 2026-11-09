// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1721 · ★★★ · Matrizes por blocos: 8 chamadas contra as 7 de Strassen
//
// Uma rede de farmácias multiplica matrizes n × n (transferências entre
// filiais vezes custos) com n potência de 2. Dividindo cada matriz em quatro
// blocos n/2 × n/2, o produto sai de 8 produtos de blocos:
//
//   C11 = A11 B11 + A12 B21    C12 = A11 B12 + A12 B22
//   C21 = A21 B11 + A22 B21    C22 = A21 B12 + A22 B22
//
// Isso dá M(n) = 8 M(n/2) multiplicações escalares, com M(1) = 1: n³, igual ao
// laço triplo (caso 1 do mestre, n^(log₂ 8)). Strassen descobriu como fazer
// com 7 produtos de blocos: S(n) = 7 S(n/2) = n^(log₂ 7) ≈ n^2,807.
//
// Escreva:
//
// 1. mult_blocos(), recursiva com as 8 chamadas (trabalhe com deslocamentos
// de linha e coluna nas matrizes globais, sem copiar blocos), contando as
// multiplicações escalares;
// 2. a conferência com o laço triplo para n = 2, 4, 8 e 16;
// 3. a tabela de n³ e 7^(lg n) para n = 2, 4, ..., 1024, calculada pelas
// recorrências, com a razão entre elas.
//
//   Saída esperada:
//   n =  2:    8 multiplicações (n³ =    8), igual ao laço triplo: sim
//   n =  4:   64 multiplicações (n³ =   64), igual ao laço triplo: sim
//   n =  8:  512 multiplicações (n³ =  512), igual ao laço triplo: sim
//   n = 16: 4096 multiplicações (n³ = 4096), igual ao laço triplo: sim
//       n          8 blocos   Strassen  razão
//       2                 8          7   1.14
//       4                64         49   1.31
//       8               512        343   1.49
//      16              4096       2401   1.71
//      32             32768      16807   1.95
//      64            262144     117649   2.23
//     128           2097152     823543   2.55
//     256          16777216    5764801   2.91
//     512         134217728   40353607   3.33
//    1024        1073741824  282475249   3.80
//
// Dicas:
// 1. mult(ar, ac, br, bc, cr, cc, n): no caso base, C[cr][cc] += A[ar][ac] *
//    B[br][bc]. Senão, com h = n/2, cada bloco Cxy recebe dois produtos:
//    por exemplo, C11 += A11 B11 é mult(ar, ac, br, bc, cr, cc, h) e
//    C11 += A12 B21 é mult(ar, ac + h, br + h, bc, cr, cc, h).
// 2. Zere C antes de cada n: as chamadas SOMAM em C.
// 3. A razão n³ / 7^(lg n) = (8/7)^(lg n) cresce devagar: só fica grande
//    para n enorme, e por isso Strassen só compensa em matrizes grandes.
// 4. Resposta esperada: as multiplicações contadas são n³ e os produtos
//    batem com o laço triplo; com n = 1024, 1073741824 contra 282475249
//    (razão 3.80).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define N 16

int A[N][N], B[N][N], C[N][N], D[N][N];

int main(void) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            A[i][j] = (i * 3 + j) % 7;     // transferências
            B[i][j] = (i + 2 * j) % 5 + 1; // custos em reais
        }

    return 0;
}
