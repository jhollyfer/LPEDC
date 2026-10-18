// 0165 · Juntando tudo
// Exercício E986 · ★☆☆
//
// No balcão, metade dos códigos digitados não existe: o catálogo vai de 1 a
// 1000, mas as 10000 buscas sorteiam de 1 a 2000. Busca que falha também
// custa. Escreva o laço do main: para cada concorrente, crie, insira as
// chaves de ordem, faça as buscas separando as que acharam das que falharam
// e mostre quantas acharam e o custo médio de cada grupo. Libere no fim.
//
//   Saída esperada:
//   BST        achou 5173; custo médio: 12.9 quando acha, 14.0 quando falha
//   AVL        achou 5173; custo médio: 9.1 quando acha, 11.0 quando falha
//   skip list  achou 5173; custo médio: 18.2 quando acha, 15.0 quando falha
//   lista MTF  achou 5173; custo médio: 492.5 quando acha, 1000.0 quando falha
//
// Dicas:
// 1. O valor devolvido por e->busca diz se achou. Use dois acumuladores de
//    custo (long) e um contador de achadas.
// 2. A média de quem falhou divide pelo número de falhas, BUSCAS - achou.
// 3. Resposta esperada: a saída acima. Na lista, falhar custa sempre 1000.
//    Na skip list, falhar sai mais barato que achar: os códigos acima de
//    1000 passam do último nó andando quase só pelos andares de cima.
//
// Escreva sua resposta abaixo (complete o main):

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
    (void)buscas; // apague esta linha

    return 0;
}
