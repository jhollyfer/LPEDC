// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1702 · ★☆☆ · A maior nota dividindo a turma em três
//
// Complete a função maior3(v, ini, n), que acha a maior nota de v[ini ..
// ini + n - 1] dividindo o pedaço em TRÊS terços iguais (n é potência de 3),
// achando a maior de cada terço com uma chamada recursiva e comparando as
// três. Um contador global soma 1 a cada chamada.
//
// A recorrência das chamadas é C(1) = 1 e C(n) = 3 C(n/3) + 1. Pela árvore
// de recursão, C(n) = 1 + 3 + 9 + ... + n = (3n - 1) / 2. Mostre, para n = 1,
// 3, 9, 27, 81 e 243, a maior nota, as chamadas contadas e (3n - 1) / 2.
//
//   Saída esperada:
//     n  maior  chamadas  (3n-1)/2
//     1     11         1         1
//     3     85         4         4
//     9     95        13        13
//    27     98        40        40
//    81    100       121       121
//   243    100       364       364
//
// Dicas:
// 1. Caso base: n == 1, devolve v[ini]. Senão, t = n / 3 e as chamadas são
//    em ini, ini + t e ini + 2t, todas com tamanho t.
// 2. A árvore tem log₃ n + 1 níveis, com 3^i nós no nível i: a soma da
//    progressão geométrica dá (3n - 1) / 2.
// 3. Pelo teorema mestre, T(n) = 3 T(n/3) + Θ(1) é o caso 1 (n^(log₃ 3) = n
//    ganha de 1): Θ(n), como um laço.
// 4. Resposta esperada: com n = 243, 364 chamadas, igual a (3 · 243 - 1) / 2.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define N 243

int nota[N];
long chamadas;

int maior3(const int v[], int ini, int n) {
    chamadas++;
    (void)v; // apague e escreva a função
    (void)ini;
    (void)n;
    return 0;
}

int main(void) {
    for (int i = 0; i < N; i++) nota[i] = (i * 37 + 11) % 101; // notas de 0 a 100

    int ns[] = {1, 3, 9, 27, 81, 243};
    printf("  n  maior  chamadas  (3n-1)/2\n");
    for (int k = 0; k < 6; k++) {
        chamadas = 0;
        int m = maior3(nota, 0, ns[k]);
        printf("%3d %6d %9ld %9d\n", ns[k], m, chamadas, (3 * ns[k] - 1) / 2);
    }
    return 0;
}
