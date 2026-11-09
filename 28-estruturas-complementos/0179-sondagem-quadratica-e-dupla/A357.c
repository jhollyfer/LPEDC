// A357 · Medindo os agrupamentos

#include <stdio.h>
#include "sondagem.h"

static unsigned semente;

int sorteia(void) { // gerador congruente simples: chaves de 0 a 999999
    semente = semente * 1103515245u + 12345u;
    return (int)((semente >> 8) % 1000000);
}

int main(void) {
    int m = 1009;
    double cargas[] = {0.5, 0.7, 0.9};
    printf("busca sem sucesso: média de sondagens (m = %d)\n", m);
    printf("carga | 1/(1-a) | linear | quadrática | dupla\n");
    for (int c = 0; c < 3; c++) {
        double media[3];
        for (int modo = 0; modo < 3; modo++) {
            Sondagem *t = sd_cria(m, (ModoSondagem)modo);
            if (t == NULL) {
                return 1;
            }
            semente = 2024; // as mesmas chaves para os três modos
            while (sd_carga(t) < cargas[c]) {
                sd_insere(t, sorteia(), NULL);
            }
            long soma = 0;
            for (int i = 0; i < 1000; i++) { // chaves >= 1000000: nunca inseridas
                int s;
                sd_busca(t, 1000000 + i, &s);
                soma += s;
            }
            media[modo] = soma / 1000.0;
            sd_libera(t);
        }
        printf(" %.1f  | %7.1f | %6.1f | %10.1f | %5.1f\n", cargas[c], 1 / (1 - cargas[c]),
               media[0], media[1], media[2]);
    }
    return 0;
}
// Saída:
// busca sem sucesso: média de sondagens (m = 1009)
// carga | 1/(1-a) | linear | quadrática | dupla
//  0.5  |     2.0 |    2.7 |        2.1 |   2.0
//  0.7  |     3.3 |    5.8 |        3.6 |   3.3
//  0.9  |    10.0 |   44.9 |       10.6 |  10.4
