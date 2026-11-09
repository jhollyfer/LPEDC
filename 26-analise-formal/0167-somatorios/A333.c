// A333 · Dois laços e mesmo assim linear: a soma geométrica

#include <stdio.h>

// O backup do mercado dobra a pasta a cada mês e copia tudo o que tem:
// 1, 2, 4, 8, ... arquivos. Quanto custa copiar até passar de n?
long copias_dobrando(long n) {
    long copias = 0;
    for (long tam = 1; tam < n; tam *= 2) {  // 1, 2, 4, ..., a maior potência < n
        for (long j = 0; j < tam; j++) {
            copias++;
        }
    }
    return copias;
}

// O contrário: a fila cai pela metade a cada rodada, e cada rodada
// atende todo mundo que sobrou: n + n/2 + n/4 + ... + 1
long atendimentos_metade(long n) {
    long passos = 0;
    for (long resta = n; resta > 0; resta /= 2) {
        for (long j = 0; j < resta; j++) {
            passos++;
        }
    }
    return passos;
}

int main(void) {
    printf("       n  dobrando  metade  2n\n");
    long ns[] = {1024, 1000, 1000000};
    for (int i = 0; i < 3; i++) {
        long n = ns[i];
        printf("%8ld %9ld %7ld %8ld\n", n, copias_dobrando(n), atendimentos_metade(n), 2 * n);
    }
    // Os dois ficam abaixo de 2n: Θ(n), não Θ(n log n).
    return 0;
}
// Saída:
//        n  dobrando  metade  2n
//     1024      1023    2047     2048
//     1000      1023    1994     2000
//  1000000   1048575 1999993  2000000
