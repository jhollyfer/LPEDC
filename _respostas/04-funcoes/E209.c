// 0035 · Pré-processador: macros e #ifdef
// Exercício E209 · ★★★

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

int maior3(int a, int b, int c) {
    return maior(maior(a, b), c);
}

int main(void) {
    int x = 5;
    int y = 3;
    int m = MAIOR(x++, y);
    printf("macro:  m = %d, x = %d\n", m, x);

    x = 5;
    m = maior(x++, y);
    printf("função: m = %d, x = %d\n", m, x);

    chamadas = 0;
    m = MAIOR(pontos(40), pontos(25));
    printf("macro:  m = %d, chamadas = %d\n", m, chamadas);

    chamadas = 0;
    m = maior(pontos(40), pontos(25));
    printf("função: m = %d, chamadas = %d\n", m, chamadas);

    chamadas = 0;
    m = MAIOR(MAIOR(pontos(7), pontos(19)), pontos(12));
    printf("macro aninhada: m = %d, chamadas = %d\n", m, chamadas);

    chamadas = 0;
    m = maior3(pontos(7), pontos(19), pontos(12));
    printf("maior3: m = %d, chamadas = %d\n", m, chamadas);
    return 0;
}
