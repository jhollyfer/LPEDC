// Lista · Módulo 02 · Decisões
// Exercício P0220 · ★★☆ · Poupança ou CDB?

#include <math.h>
#include <stdio.h>

int main(void) {
    double valor = 5000.00;
    int meses = 6;

    double poupanca = valor * pow(1.005, meses) - valor;
    double cdb_bruto = valor * pow(1.009, meses) - valor;
    double cdb = cdb_bruto * (1 - 0.225);

    printf("Poupança: R$ %.2f\n", poupanca);
    printf("CDB: R$ %.2f\n", cdb);
    if (cdb > poupanca) {
        printf("Melhor opção: CDB\n");
    } else if (poupanca > cdb) {
        printf("Melhor opção: poupança\n");
    } else {
        printf("Tanto faz.\n");
    }
    return 0;
}
