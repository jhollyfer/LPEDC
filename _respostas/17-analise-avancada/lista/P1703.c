// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1703 · ★☆☆ · O hodômetro do ônibus: custo amortizado em base 10

#include <stdio.h>

int incrementa(int d[]) {
    int i = 0, custo = 0;
    while (i < 4 && d[i] == 9) { // 9 vira 0 e "vai um"
        d[i] = 0;
        i++;
        custo++;
    }
    if (i < 4) {
        d[i]++;
        custo++;
    }
    return custo;
}

int main(void) {
    int d[4] = {7, 9, 9, 0}; // 0997, das unidades para os milhares

    for (int k = 0; k < 3; k++) {
        int c = incrementa(d);
        printf("%d%d%d%d (giraram %d)\n", d[3], d[2], d[1], d[0], c);
    }

    int z[4] = {0, 0, 0, 0};
    long total = 0;
    int marcos[] = {10, 100, 1000, 10000}, m = 0;
    for (int km = 1; km <= 10000; km++) {
        total += incrementa(z);
        if (km == marcos[m]) {
            printf("%5d km: %5ld rodinhas, %.3f por km\n", km, total, (double)total / km);
            m++;
        }
    }
    return 0;
}
