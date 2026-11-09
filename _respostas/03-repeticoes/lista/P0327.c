// Lista · Módulo 03 · Laços
// Exercício P0327 · ★★★ · O juro escondido no parcelamento

#include <math.h>
#include <stdio.h>

int main(void) {
    const double VALOR = 1000.00;
    const double PARCELA = 120.00;
    const int N = 10;

    double baixo = 0.0001, alto = 1.0, meio = 0.0;
    int voltas = 0;

    while (alto - baixo > 0.0000001) {
        meio = (baixo + alto) / 2;
        double p = VALOR * meio / (1 - pow(1 + meio, -N));
        if (p > PARCELA) {
            alto = meio;
        } else {
            baixo = meio;
        }
        voltas++;
    }

    double conferindo = VALOR * meio / (1 - pow(1 + meio, -N));
    printf("Taxa mensal: %.2f%%\n", meio * 100);
    printf("Voltas da bissecção: %d\n", voltas);
    printf("Conferindo: parcela de R$ %.2f\n", conferindo);
    return 0;
}
