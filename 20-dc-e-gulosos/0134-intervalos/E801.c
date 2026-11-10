// 0134 · Seleção de intervalos
// Exercício E801 · ★★☆
//
// Coloque os três critérios do texto para competir no mesmo conjunto de
// pedidos, [ini, fim):
//
//   [0, 10) [1, 4) [4, 7) [7, 10) [3, 5) [6, 8) [10, 12)
//
// Escreva int seleciona(const Pedido p[], int n, int (*criterio)(const void *,
// const void *)), que copia os pedidos (memcpy), ordena a cópia com qsort
// usando o critério recebido (ponteiro para função, assunto 0050) e aceita
// cada pedido que não choca com NENHUM dos já aceitos. Escreva também as
// três comparações: por_inicio, por_duracao e por_fim.
//
//   Saída esperada:
//   Começa primeiro: 2
//   Mais curto:      3
//   Termina primeiro: 4
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ini, fim;
} Pedido;

int main(void) {
    Pedido p[] = {{0, 10}, {1, 4}, {4, 7}, {7, 10}, {3, 5}, {6, 8}, {10, 12}};
    int n = 7;
    (void)p;
    (void)n;

    return 0;
}
