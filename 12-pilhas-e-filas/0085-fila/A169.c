// A169 · Só as 8 últimas corridas: a mais antiga dá lugar

#include <stdio.h>
#include "fila.h"

int main(void) {
    Fila *historico = fila_cria(); // o app mostra as 8 corridas mais recentes
    if (historico == NULL) {
        return 1;
    }

    int corridas[] = {18, 25, 12, 40, 9, 31, 22, 15, 27, 33, 11}; // em R$
    int total = sizeof corridas / sizeof corridas[0];

    for (int i = 0; i < total; i++) {
        // cheia? em vez de recusar a nova, descarta a mais antiga (o início)
        if (!fila_insere(historico, corridas[i])) {
            int velha;
            fila_retira(historico, &velha);
            fila_insere(historico, corridas[i]);
            printf("Corrida de R$ %d saiu do histórico para entrar a de R$ %d\n", velha, corridas[i]);
        }
    }

    // percorre sem perder ninguém: retira, mostra e devolve ao fim
    int soma = 0;
    printf("Histórico (%d):", fila_tamanho(historico));
    for (int i = 0; i < fila_tamanho(historico); i++) {
        int valor;
        fila_retira(historico, &valor);
        printf(" %d", valor);
        soma += valor;
        fila_insere(historico, valor);
    }
    printf("\nGasto nas últimas 8: R$ %d\n", soma);

    fila_libera(historico);
    return 0;
}
// Saída:
// Corrida de R$ 18 saiu do histórico para entrar a de R$ 27
// Corrida de R$ 25 saiu do histórico para entrar a de R$ 33
// Corrida de R$ 12 saiu do histórico para entrar a de R$ 11
// Histórico (8): 40 9 31 22 15 27 33 11
// Gasto nas últimas 8: R$ 188
