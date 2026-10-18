// A223 · O estacionamento do condomínio: a próxima vaga livre

#include <stdio.h>
#include "aberta.h"

int main(void) {
    Aberta *vagas = aberta_cria(11);
    if (vagas == NULL) {
        return 1;
    }
    int aptos[] = {101, 202, 301, 1104, 504};
    int horas[] = {7, 8, 8, 9, 10};
    for (int i = 0; i < 5; i++) {
        int s;
        int vaga = aberta_insere(vagas, aptos[i], horas[i], &s);
        printf("apto %4d: hash %d -> vaga %d, sondagens: %d\n", aptos[i], aptos[i] % 11, vaga, s);
    }
    aberta_mostra(vagas);

    int hora, s;
    if (aberta_busca(vagas, 1104, &hora, &s)) {
        printf("1104 entrou às %dh, sondagens: %d\n", hora, s);
    }
    if (!aberta_busca(vagas, 303, &hora, &s)) {
        printf("303 não está, sondagens: %d\n", s);
    }
    aberta_libera(vagas);
    return 0;
}
// Saída:
// apto  101: hash 2 -> vaga 2, sondagens: 1
// apto  202: hash 4 -> vaga 4, sondagens: 1
// apto  301: hash 4 -> vaga 5, sondagens: 2
// apto 1104: hash 4 -> vaga 6, sondagens: 3
// apto  504: hash 9 -> vaga 9, sondagens: 1
// [ 0] -
// [ 1] -
// [ 2] 101
// [ 3] -
// [ 4] 202
// [ 5] 301
// [ 6] 1104
// [ 7] -
// [ 8] -
// [ 9] 504
// [10] -
// 1104 entrou às 9h, sondagens: 3
// 303 não está, sondagens: 2
