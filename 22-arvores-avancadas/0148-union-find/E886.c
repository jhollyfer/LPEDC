// 0148 · Union-find
// Exercício E886 · ★★☆
//
// Na pelada de quinta, quem já jogou junto fica no mesmo time, e "jogou com
// quem jogou com" também conta. Com o TAD (uniao.h), una as duplas e liste
// cada time com seus jogadores. Os times saem na ordem do seu primeiro
// jogador (o de menor número), e os jogadores de cada time, em ordem de
// número. Mostre também o tamanho de cada time.
//
//   Saída esperada:
//   Time 1 (3): Alex Eli Ivo
//   Time 2 (2): Bia Fabi
//   Time 3 (3): Cadu Davi Hana
//   Time 4 (1): Gabo
//
// Dicas:
// 1. Percorra x de 0 a n - 1. x abre um time novo quando nenhum y < x tem o
//    mesmo representante (uf_acha) que ele.
// 2. Para listar o time de x, percorra y de x até n - 1 e mostre quem tem o
//    mesmo representante. O tamanho vem de uf_tamanho.
// 3. Resposta esperada: a saída acima. O representante do time 3 é o Cadu?
//    Não importa: a ordem de saída é pelos números, não pelas raízes.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include "uniao.h"

int main(void) {
    const char *jogador[] = {"Alex", "Bia", "Cadu", "Davi", "Eli", "Fabi", "Gabo", "Hana", "Ivo"};
    int n = 9;
    // cada par já jogou junto na pelada de quinta
    int duplas[][2] = {{0, 4}, {2, 7}, {4, 8}, {1, 5}, {7, 3}, {8, 0}};
    UF *u = uf_cria(n);
    for (int i = 0; i < 6; i++) {
        uf_une(u, duplas[i][0], duplas[i][1]);
    }
    (void)jogador; // apague esta linha

    uf_libera(u);
    return 0;
}
