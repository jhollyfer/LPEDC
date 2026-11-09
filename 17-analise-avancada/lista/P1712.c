// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1712 · ★★☆ · Três funções, três casos, três fórmulas fechadas
//
// As três funções do esqueleto fazem um laço de n voltas (custo n) e se
// chamam com n/2, mudando só QUANTAS vezes:
//
//   quatro(n): T(n) = 4 T(n/2) + n   caso 1: Θ(n²)
//   duas(n):   T(n) = 2 T(n/2) + n   caso 2: Θ(n lg n)
//   uma(n):    T(n) = T(n/2) + n     caso 3: Θ(n)
//
// com T(1) = 1. Resolvendo exatamente para n potência de 2 (pela árvore de
// recursão), as fórmulas são 2n² - n, n lg n + n e 2n - 1. Instrumente as três
// com um contador global (some 1 em cada volta do laço e 1 no caso base) e
// mostre, para n = 1, 2, 4, ..., 1024, o custo contado e a fórmula de cada
// uma.
//
//   Saída esperada:
//      n    quatro   2n²-n   duas  nlgn+n   uma  2n-1
//      1         1       1      1       1     1     1
//      2         6       6      4       4     3     3
//      4        28      28     12      12     7     7
//      8       120     120     32      32    15    15
//     16       496     496     80      80    31    31
//     32      2016    2016    192     192    63    63
//     64      8128    8128    448     448   127   127
//    128     32640   32640   1024    1024   255   255
//    256    130816  130816   2304    2304   511   511
//    512    523776  523776   5120    5120  1023  1023
//   1024   2096128 2096128  11264   11264  2047  2047
//
// Dicas:
// 1. Zere o contador antes de cada chamada de topo. Use long: quatro(1024)
//    passa de 2 milhões.
// 2. Para o lg n, use um contador de expoente que sobe junto com n no laço do
//    main (n = 1 << k).
// 3. As fórmulas saem da soma por nível: quatro tem 4^i pedaços de n/2^i
//    (custo 2^i n no nível i); duas tem custo n em todo nível; uma tem
//    n/2^i no nível i.
// 4. Resposta esperada: as colunas contadas e as fórmulas batem em todas as
//    linhas; com n = 1024: 2096128, 11264 e 2047.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

void quatro(int n) {
    if (n == 1) return;
    for (int i = 0; i < n; i++) {
        // trabalho da chamada
    }
    for (int k = 0; k < 4; k++) quatro(n / 2);
}

void duas(int n) {
    if (n == 1) return;
    for (int i = 0; i < n; i++) {
    }
    for (int k = 0; k < 2; k++) duas(n / 2);
}

void uma(int n) {
    if (n == 1) return;
    for (int i = 0; i < n; i++) {
    }
    uma(n / 2);
}

int main(void) {
    quatro(8);
    duas(8);
    uma(8);
    return 0;
}
