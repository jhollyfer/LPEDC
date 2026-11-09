// Lista · Módulo 07 · Memória dinâmica
// Exercício P0705 · ★☆☆ · Conserte os dois free
//
// O programa da padaria guarda as encomendas do dia no heap. Ele tem DOIS
// erros de propósito. O gcc já desconfia dos dois (leia os warnings), e o
// AddressSanitizer confirma, um de cada vez: rode, leia o relatório (a
// primeira linha diz o tipo do erro e a linha do programa), conserte e rode
// de novo. Ele deve mostrar:
//
//   Saída esperada:
//   Maior encomenda: 50
//   Total: 100 pães
//
// Dicas:
// 1. heap-use-after-free: o programa lê o bloco depois de devolvê-lo. Mova o
//    free para depois do último uso.
// 2. attempting free on address which was not malloc()-ed: só se passa para
//    o free um endereço que veio do malloc, calloc ou realloc. Variável
//    local mora na pilha e some sozinha.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int total_paes = 0;
    int *encomendas = malloc(4 * sizeof *encomendas);
    if (encomendas == NULL) {
        return 1;
    }
    encomendas[0] = 30; // pães da dona Graça
    encomendas[1] = 12;
    encomendas[2] = 50;
    encomendas[3] = 8;

    for (int i = 0; i < 4; i++) {
        total_paes += encomendas[i];
    }
    free(encomendas);

    printf("Maior encomenda: %d\n", encomendas[2]);
    printf("Total: %d pães\n", total_paes);
    free(&total_paes);
    return 0;
}
