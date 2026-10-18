// A172 · Simulando o caixa do mercado

#include <stdio.h>
#include "fila.h"

#define CLIENTES 5

int main(void) {
    int chegada[CLIENTES] = {0, 1, 2, 5, 6}; // minuto em que cada um chega
    int duracao[CLIENTES] = {3, 2, 4, 1, 2}; // minutos de atendimento

    Fila *fila = fila_cria(); // guarda o número de cada cliente
    if (fila == NULL) {
        return 1;
    }

    int proximo = 0;  // próximo cliente a chegar
    int restante = 0; // minutos que faltam para o caixa ficar livre
    int atendidos = 0, espera_total = 0, maior_fila = 0;

    for (int minuto = 0; atendidos < CLIENTES; minuto++) {
        while (proximo < CLIENTES && chegada[proximo] == minuto) {
            fila_insere(fila, proximo); // chegou: vai para o fim da fila
            proximo++;
        }
        if (restante == 0 && !fila_vazia(fila)) { // caixa livre: chama o próximo
            int c;
            fila_retira(fila, &c);
            int espera = minuto - chegada[c];
            printf("Minuto %2d: cliente %d no caixa (esperou %d)\n", minuto, c + 1, espera);
            espera_total += espera;
            restante = duracao[c];
            atendidos++;
        }
        if (fila_tamanho(fila) > maior_fila) {
            maior_fila = fila_tamanho(fila);
        }
        if (restante > 0) {
            restante--; // passa um minuto de atendimento
        }
    }
    printf("Espera média: %.1f min; maior fila: %d\n", (double)espera_total / CLIENTES, maior_fila);

    fila_libera(fila);
    return 0;
}
// Saída:
// Minuto  0: cliente 1 no caixa (esperou 0)
// Minuto  3: cliente 2 no caixa (esperou 2)
// Minuto  5: cliente 3 no caixa (esperou 3)
// Minuto  9: cliente 4 no caixa (esperou 4)
// Minuto 10: cliente 5 no caixa (esperou 4)
// Espera média: 2.6 min; maior fila: 2
