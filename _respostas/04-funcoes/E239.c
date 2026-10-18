// 0040 · Pré-processador: macros e #ifdef
// Exercício E239 · ★★★
//
// Resposta: m = 6, x = 7 / m = 5, x = 6 / m = 40, chamadas = 3 /
// m = 40, chamadas = 2.
// MAIOR(x++, y) vira ((x++) > (y) ? (x++) : (y)): o primeiro x++ compara 5 > 3
// e x vira 6; o segundo x++ devolve 6 e x vira 7. Na função, x++ roda uma vez
// só, antes da chamada: a recebe 5. Com pontos, a macro chama pontos(40) duas
// vezes (na comparação e no resultado) e pontos(25) uma: 3 chamadas.

#include <stdio.h>

#define MAIOR(a, b) ((a) > (b) ? (a) : (b))

int chamadas = 0;

int pontos(int p) {
    chamadas++;
    return p;
}

int maior(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int x = 5;
    int y = 3;
    int m = MAIOR(x++, y);
    printf("m = %d, x = %d\n", m, x);

    x = 5;
    m = maior(x++, y);
    printf("m = %d, x = %d\n", m, x);

    m = MAIOR(pontos(40), pontos(25));
    printf("m = %d, chamadas = %d\n", m, chamadas);

    chamadas = 0;
    m = maior(pontos(40), pontos(25));
    printf("m = %d, chamadas = %d\n", m, chamadas);
    return 0;
}
