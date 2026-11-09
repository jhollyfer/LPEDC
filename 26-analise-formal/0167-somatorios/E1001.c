// 0167 · Somatórios que saem de laços
// Exercício E1001 · ★★★
//
// Conserte as fórmulas. O programa conta as execuções de três laços com
// n = 1024 e compara com uma fórmula fechada para cada um. Os laços estão
// certos; as três fórmulas, erradas:
//
//   Saída que aparece:
//   a: 523776 e 524800, confere: não
//   b: 1023 e 10240, confere: não
//   c: 342 e 341, confere: não
//
// Corrija só as linhas formula_a, formula_b e formula_c (sem laço, só
// conta com n) até as três conferirem:
//
//   Saída esperada:
//   a: 523776 e 523776, confere: sim
//   b: 1023 e 1023, confere: sim
//   c: 342 e 342, confere: sim
//
// Dicas:
// 1. a: some i para i de 0 até n-1. Teste com n = 2: o laço roda 1 vez.
// 2. b: 1 + 2 + 4 + ... + 512. Quanto falta para 1024?
// 3. c: i = 0, 3, 6, ..., 1023 são quantos valores? n / 3 em inteiro
//    corta a parte quebrada; você quer arredondar para cima: (n + 2) / 3.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    long n = 1024;

    long a = 0;                          // laço dependente: j < i
    for (long i = 0; i < n; i++) {
        for (long j = 0; j < i; j++) {
            a++;
        }
    }
    long formula_a = n * (n + 1) / 2;

    long b = 0;                          // laço que dobra
    for (long t = 1; t < n; t *= 2) {
        for (long j = 0; j < t; j++) {
            b++;
        }
    }
    long formula_b = n * 10;             // n log2 n, com log2 1024 = 10

    long c = 0;                          // de 3 em 3
    for (long i = 0; i < n; i += 3) {
        c++;
    }
    long formula_c = n / 3;

    printf("a: %ld e %ld, confere: %s\n", a, formula_a, a == formula_a ? "sim" : "não");
    printf("b: %ld e %ld, confere: %s\n", b, formula_b, b == formula_b ? "sim" : "não");
    printf("c: %ld e %ld, confere: %s\n", c, formula_c, c == formula_c ? "sim" : "não");
    return 0;
}
