// 0165 · Juntando tudo
// Exercício E986 · ★☆☆

#include <stdio.h>
#include "bancada.h"

#define N 1000
#define BUSCAS 10000

int main(void) {
    unsigned estado = 3;
    int ordem[N];
    for (int i = 0; i < N; i++) {
        ordem[i] = i + 1;
    }
    bc_embaralha(ordem, N, &estado);
    static int buscas[BUSCAS];
    for (int i = 0; i < BUSCAS; i++) {
        buscas[i] = bc_sorteio(&estado) % (2 * N) + 1; // de 1 a 2000
    }

    for (int k = 0; k < NUM_CONCORRENTES; k++) {
        const Estrutura *e = &CONCORRENTES[k];
        void *d = e->cria();
        for (int i = 0; i < N; i++) {
            e->insere(d, ordem[i]);
        }
        int achou = 0;
        long custo_achou = 0, custo_falhou = 0;
        for (int i = 0; i < BUSCAS; i++) {
            int custo;
            if (e->busca(d, buscas[i], &custo)) {
                achou++;
                custo_achou += custo;
            } else {
                custo_falhou += custo;
            }
        }
        e->libera(d);
        printf("%-10s achou %d; custo médio: %.1f quando acha, %.1f quando falha\n", e->nome,
               achou, (double)custo_achou / achou, (double)custo_falhou / (BUSCAS - achou));
    }
    return 0;
}
