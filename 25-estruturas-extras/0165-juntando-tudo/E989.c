// 0165 · Juntando tudo
// Exercício E989 · ★★★
//
// Ache o bug. Este programa compara os quatro concorrentes com 10000
// buscas de códigos de 1 a 1500 (o catálogo só tem de 1 a 1000, então uma
// parte falha). Como as buscas são as mesmas para todos, a coluna "acharam"
// TEM que dar o mesmo número nas quatro linhas. Mas sai assim:
//
//   Saída que aparece:
//   BST        acharam 6750, custo médio 9.3
//   AVL        acharam 6782, custo médio 9.8
//   skip list  acharam 6631, custo médio 14.3
//   lista MTF  acharam 6803, custo médio 660.5
//
// Conserte o programa para que todos respondam às MESMAS buscas: sorteie a
// sequência uma vez só, antes de medir, num vetor que mede recebe.
//
//   Saída esperada:
//   BST        acharam 6750, custo médio 9.3
//   AVL        acharam 6750, custo médio 9.8
//   skip list  acharam 6750, custo médio 14.3
//   lista MTF  acharam 6750, custo médio 664.2
//
// Dicas:
// 1. O estado do sorteio é uma variável global. Quando mede termina de
//    sortear as 10000 buscas do BST, de onde o sorteio continua para a AVL?
// 2. Crie static int buscas[BUSCAS] no main, preencha uma vez com o mesmo
//    sorteio (bc_sorteio(&estado) % 1500 + 1) e passe o vetor para mede.
// 3. Resposta esperada: a saída acima. A primeira linha não muda, porque o
//    BST já recebia a primeira sequência sorteada.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include "bancada.h"

#define N 1000
#define BUSCAS 10000

unsigned estado = 3; // o estado do sorteio

void mede(const Estrutura *e, const int ordem[]) {
    void *d = e->cria();
    for (int i = 0; i < N; i++) {
        e->insere(d, ordem[i]);
    }
    int acharam = 0;
    long total = 0;
    for (int i = 0; i < BUSCAS; i++) {
        int chave = bc_sorteio(&estado) % 1500 + 1; // um código qualquer
        int custo;
        acharam += e->busca(d, chave, &custo);
        total += custo;
    }
    e->libera(d);
    printf("%-10s acharam %d, custo médio %.1f\n", e->nome, acharam, (double)total / BUSCAS);
}

int main(void) {
    int ordem[N];
    for (int i = 0; i < N; i++) {
        ordem[i] = i + 1;
    }
    unsigned outro = 9;
    bc_embaralha(ordem, N, &outro);

    for (int k = 0; k < NUM_CONCORRENTES; k++) {
        mede(&CONCORRENTES[k], ordem);
    }
    return 0;
}
