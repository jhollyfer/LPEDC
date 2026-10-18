// A214 · O carro do 301 saiu: a marca de removida

#include <stdio.h>
#include "aberta.h"

int main(void) {
    Aberta *vagas = aberta_cria(11);
    if (vagas == NULL) {
        return 1;
    }
    int aptos[] = {101, 202, 301, 1104, 504};
    for (int i = 0; i < 5; i++) {
        aberta_insere(vagas, aptos[i], 8, NULL);
    }

    aberta_remove(vagas, 301); // a vaga 5 vira "removida", não livre
    int hora, s;
    if (aberta_busca(vagas, 1104, &hora, &s)) {
        printf("1104 ainda é encontrado, sondagens: %d\n", s); // passa pela 5
    }

    // 103 % 11 = 4. Olha a 4 (ocupada), a 5 (removida: guarda), a 6 e a 7
    // (livre: o 103 não está na tabela) e só então usa a 5
    int vaga = aberta_insere(vagas, 103, 11, &s);
    printf("103 -> vaga %d, sondagens: %d\n", vaga, s);
    aberta_mostra(vagas);
    aberta_libera(vagas);
    return 0;
}
// Saída:
// 1104 ainda é encontrado, sondagens: 3
// 103 -> vaga 5, sondagens: 4
// [ 0] -
// [ 1] -
// [ 2] 101
// [ 3] -
// [ 4] 202
// [ 5] 103
// [ 6] 1104
// [ 7] -
// [ 8] -
// [ 9] 504
// [10] -
