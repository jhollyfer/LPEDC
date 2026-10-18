// 0087 · Deque
// Exercício E517 · ★☆☆
//
// Os números 1, 2, 3 e 4 chegam nessa ordem, um de cada vez. Para cada um,
// você escolhe se ele entra pela frente (deque_insere_inicio) ou pelo fundo
// (deque_insere_fim). Escreva as quatro inserções, nessa ordem de chegada,
// para que o deque fique 4 2 1 3 da frente para o fundo. O resto do main
// (pronto) tira um do fundo, um da frente e mostra o que sobrou.
//
//   Saída esperada:
//   saiu do fim: 3
//   saiu da frente: 4
//   frente 2, fundo 1, tamanho 2
//
// Dicas:
// 1. insere_inicio põe à esquerda; insere_fim, à direita.
// 2. O 1 entra primeiro e acaba no meio: quem chega depois dele se divide
//    entre os dois lados.
// 3. Resposta esperada: fim 1, início 2, fim 3, início 4, e as três linhas
//    acima.
//
// Escreva sua resposta abaixo (as quatro inserções):

#include <stdio.h>
#include "deque.h"

int main(void) {
    Deque *d = deque_cria();
    if (d == NULL) {
        return 1;
    }
    int x = 0, y = 0;

    // suas quatro inserções aqui (1, depois 2, depois 3, depois 4)

    if (deque_retira_fim(d, &x)) {
        printf("saiu do fim: %d\n", x);
    }
    if (deque_retira_inicio(d, &x)) {
        printf("saiu da frente: %d\n", x);
    }
    if (deque_primeiro(d, &x) && deque_ultimo(d, &y)) {
        printf("frente %d, fundo %d, tamanho %d\n", x, y, deque_tamanho(d));
    }

    deque_libera(d);
    return 0;
}
