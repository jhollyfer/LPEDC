// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1723 · ★★★ · Stooge sort: correto, recursivo e pior que o bubble
//
// O stooge sort (problema 7-3 do Cormen) ordena v[i..j] assim: se v[i] >
// v[j], troca os dois; se o pedaço tem 3 ou mais elementos, com t = ⌊(j - i +
// 1)/3⌋, ordena os primeiros 2/3, depois os últimos 2/3, depois os primeiros
// 2/3 de novo. Ele funciona, mas a recorrência é
//
//   T(n) = 3 T(2n/3) + Θ(1)  =>  Θ(n^(log_{3/2} 3)) ≈ Θ(n^2,71)
//
// pior que os Θ(n²) do bubble e do insertion sort.
//
// Escreva o stooge sort com um contador de chamadas e a profundidade máxima
// da recursão (a raiz tem profundidade 1), e ordene os tempos de volta de um
// kart (vetor do esqueleto) para n = 10, 20, 40, ..., 640. Mostre, para
// cada n: as chamadas, se ficou ordenado, a profundidade, log_{3/2} n e as
// n(n - 1)/2 comparações do bubble sort. No fim, estime o expoente entre n = 10 e
// n = 640 com log(c₆₄₀ / c₁₀) / log(64) e compare com log(3) / log(1,5).
//
//   Saída esperada:
//     n  chamadas  ordenado  prof  log1.5(n)  bubble
//    10       364       sim     6       5.68      45
//    20      3280       sim     8       7.39     190
//    40      9841       sim     9       9.10     780
//    80     88573       sim    11      10.81    3160
//   160    797161       sim    13      12.52   12720
//   320   7174453       sim    15      14.23   51040
//   640  21523360       sim    16      15.94  204480
//   Expoente estimado: 2.642 | teoria log(3) / log(1,5) = 2.7095
//
// Dicas:
// 1. Os dois "2/3" se sobrepõem: primeiros vão de i até j - t, últimos de
//    i + t até j. É essa sobreposição que garante que o maior chega ao fim.
// 2. Repare que as chamadas são sempre (3^p - 1)/2, com p a profundidade: a
//    árvore é ternária e cheia. Cada fator 3/2 no tamanho acrescenta um
//    nível, então p ≈ log_{3/2} n e as chamadas ≈ 3^(log_{3/2} n) =
//    n^(log_{3/2} 3).
// 3. Por causa do ⌊ ⌋, a profundidade anda aos saltos: a razão entre n e 2n
//    oscila. Estime o expoente num intervalo longo.
// 4. Resposta esperada: todos ordenados; com n = 640, 21523360 chamadas
//    (contra 204480 comparações do bubble); expoente estimado 2.642, teoria
//    2.7095.
//
// Escreva sua resposta abaixo:

#include <math.h>
#include <stdio.h>

#define MAX 640

int voltas[MAX];

int main(void) {
    for (int i = 0; i < MAX; i++) voltas[i] = 40000 + (i * 7919) % 5003; // milissegundos

    printf("%d %d\n", voltas[0], voltas[1]);
    return 0;
}
