// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1827 · ★★★ · n números de 0 a n² - 1 em tempo linear
//
// Exercício clássico do Cormen (8.3-4): ordenar n inteiros no intervalo
// [0, n² - 1] em tempo O(n). O counting sort direto pagaria k = n². O radix
// sort em base 10 faria lg₁₀(n²) passadas. O truque: use BASE n. Todo número
// x < n² tem só dois "dígitos" nessa base, x % n e x / n, e cada passada
// custa Θ(n + n) = Θ(n).
//
// Uma cooperativa tem n = 1000 produtores, e cada código de lote vai de 0 a
// 999999 (= n² - 1). Ordene os códigos do esqueleto de três jeitos, contando
// as operações (por passada: n na contagem + b nas somas + n na colocação +
// n na cópia):
//
// - counting sort direto, com k = n²;
// - radix em base 10 (6 passadas);
// - radix em base n (2 passadas).
//
// Confira que os três dão o mesmo vetor e mostre as operações de cada um.
//
//   Saída esperada:
//   counting direto (k = n²):  1003000 operações
//   radix base 10 (6 passadas):  18060 operações
//   radix base n (2 passadas):    8000 operações
//   Iguais: sim | menor 581, maior 999150
//
// Dicas:
// 1. Escreva uma passada genérica que recebe o divisor e a base:
//    dígito = (x / div) % base. Na base n, div vale 1 e depois n.
// 2. O counting direto é uma "passada" com base n² e div = 1: Θ(n + n²).
// 3. Fórmulas: direto 3n + n² = 1003000; base 10: 6 · (3n + 10) = 18060;
//    base n: 2 · (3n + n) = 8000.
// 4. Resposta esperada: os três vetores iguais; 1003000, 18060 e 8000
//    operações.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

#define N 1000

unsigned semente = 31;

int sorteia(void) { // de 0 a N² - 1
    semente = semente * 1103515245u + 12345u;
    unsigned alto = (semente >> 16) % 1000;
    semente = semente * 1103515245u + 12345u;
    return (int)(alto * 1000 + (semente >> 16) % 1000);
}

int main(void) {
    int lote[N];
    for (int i = 0; i < N; i++) lote[i] = sorteia();

    printf("%d %d %d\n", lote[0], lote[1], lote[2]);
    return 0;
}
