// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1713 · ★★☆ · Quando o mestre não serve: 2T(n/2) + n lg n
//
// Um sistema de relatórios divide os registros ao meio, processa cada metade
// recursivamente e, para juntar, gasta n lg n (ele ordena o resultado). A
// recorrência é T(n) = 2 T(n/2) + n lg n, com T(1) = 1.
//
// Parece o caso 3 (n lg n é maior que n^(log₂ 2) = n), mas não é: n lg n
// não é POLINOMIALMENTE maior que n (não existe ε > 0 com n lg n = Ω(n^(1+ε))).
// O teorema mestre na forma básica não se aplica. A árvore de recursão
// resolve: o nível i custa n (lg n - i), e a soma dá
//
//   T(n) = n + n · lg n (lg n + 1) / 2 = Θ(n lg² n)
//
// Escreva relatorio(n), que conta n · lg n unidades de trabalho (lg n
// calculado com inteiros) e se chama duas vezes com n/2, e mostre, para
// n = 2, 4, 8, ..., 2^16, o custo contado, a fórmula, a razão custo/(n lg n)
// (que CRESCE) e a razão custo/(n lg² n) (que se aproxima de 1/2).
//
//   Saída esperada:
//       n      custo    fórmula  c/(n lg n)  c/(n lg² n)
//       2          4          4       2.000        2.000
//       4         16         16       2.000        1.000
//       8         56         56       2.333        0.778
//      16        176        176       2.750        0.688
//      32        512        512       3.200        0.640
//      64       1408       1408       3.667        0.611
//     128       3712       3712       4.143        0.592
//     256       9472       9472       4.625        0.578
//     512      23552      23552       5.111        0.568
//    1024      57344      57344       5.600        0.560
//    2048     137216     137216       6.091        0.554
//    4096     323584     323584       6.583        0.549
//    8192     753664     753664       7.077        0.544
//   16384    1736704    1736704       7.571        0.541
//   32768    3964928    3964928       8.067        0.538
//   65536    8978432    8978432       8.562        0.535
//
// Dicas:
// 1. lg n com inteiros: conte quantas vezes dá para dividir n por 2 até
//    chegar a 1.
// 2. Não precisa de laço de n lg n voltas: some n * lg(n) direto no
//    contador (o custo é o que interessa, não o tempo).
// 3. Uma razão que cresce sem parar mostra que o palpite Θ(n lg n) está
//    errado; uma razão que se estabiliza mostra a classe certa.
// 4. Resposta esperada: custo igual à fórmula em todas as linhas; com
//    n = 65536, 8978432, razões 8.562 e 0.535.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
