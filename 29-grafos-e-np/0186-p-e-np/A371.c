// A371 · Quanto 2^n cresce

#include <stdbool.h>
#include <stdio.h>

#define MAXN 20

int n;            // variáveis em uso
long olhados = 0; // literais examinados pelo verificador

// fórmula insatisfatível de propósito: (x1) e (não x1), mais
// (x1 ou x2 ou ... ou xn); a força bruta precisa testar tudo
bool satisfaz(const bool x[]) {
    olhados++;
    if (!x[1]) return false; // cláusula (x1)
    olhados++;
    if (x[1]) return false;  // cláusula (não x1)
    for (int v = 1; v <= n; v++) {
        olhados++;
        if (x[v]) return true;
    }
    return false;
}

int main(void) {
    printf(" n    atribuições   literais olhados\n");
    for (n = 4; n <= MAXN; n += 4) {
        olhados = 0;
        bool achou = false;
        for (long m = 0; m < (1L << n) && !achou; m++) {
            bool x[MAXN + 1];
            for (int v = 1; v <= n; v++) x[v] = (m >> (v - 1)) & 1;
            achou = satisfaz(x);
        }
        printf("%2d  %13ld  %17ld\n", n, 1L << n, olhados);
    }
    printf("\nA um bilhão de atribuições por segundo:\n");
    double segundos = 1.0;
    for (int k = 1; k <= 30; k++) segundos *= 2;  // 2^30
    printf("  n = 30: %.1f segundo(s)\n", segundos / 1e9);
    for (int k = 31; k <= 50; k++) segundos *= 2; // 2^50
    printf("  n = 50: %.1f dias\n", segundos / 1e9 / 86400);
    for (int k = 51; k <= 70; k++) segundos *= 2; // 2^70
    printf("  n = 70: %.0f anos\n", segundos / 1e9 / 86400 / 365);
    return 0;
}
// Saída:
//  n    atribuições   literais olhados
//  4             16                 24
//  8            256                384
// 12           4096               6144
// 16          65536              98304
// 20        1048576            1572864
//
// A um bilhão de atribuições por segundo:
//   n = 30: 1.1 segundo(s)
//   n = 50: 13.0 dias
//   n = 70: 37436 anos
//
// O verificador é barato (aqui, 1 ou 2 literais por chamada, em média 1,5),
// mas a força bruta o chama 2^n vezes. Somar 4 variáveis multiplica o
// trabalho por 16. Com 70 variáveis (uma escala de plantão pequena), nem
// todos os computadores do mundo juntos dariam conta. É por isso que os
// programas de SAT de verdade cortam caminho com backtracking e
// propagação, e ainda assim existem fórmulas que os derrubam.
