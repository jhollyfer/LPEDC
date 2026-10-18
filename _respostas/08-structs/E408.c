// 0068 · Enum
// Exercício E408 · ★★★

#include <stdio.h>

typedef enum { PESSIMA, RUIM, OK, BOA, OTIMA, QTD_NOTAS } Nota;

int main(void) {
    const char *nomes[QTD_NOTAS] = {"péssima", "ruim", "ok", "boa", "ótima"};
    Nota respostas[] = {OTIMA, BOA, OK, OTIMA, RUIM, BOA, OTIMA, OTIMA,
                        PESSIMA, BOA, OK, OTIMA, BOA, OTIMA, RUIM};
    int total = sizeof respostas / sizeof respostas[0];
    int contagem[QTD_NOTAS] = {0};

    for (int i = 0; i < total; i++) {
        contagem[respostas[i]]++;
    }
    for (Nota n = PESSIMA; n < QTD_NOTAS; n++) {
        printf("%s: %d (%.1f%%)\n", nomes[n], contagem[n], 100.0 * contagem[n] / total);
    }
    printf("Satisfação: %.1f%%\n", 100.0 * (contagem[BOA] + contagem[OTIMA]) / total);
    return 0;
}
