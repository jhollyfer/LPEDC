// 0066 · Juntando tudo: o cardápio
// Exercício E393 · ★★☆
//
// Monte um estoque que cresce: typedef struct { Produto *v; int n, cap; }
// Estoque; com as funções
//
//   - bool estoque_adicionar(Estoque *e, const char *nome, int qtd);
//   - bool estoque_remover(Estoque *e, const char *nome): acha pelo nome e
//     puxa os seguintes uma posição para trás (a ordem se mantém);
//   - void estoque_listar(const Estoque *e) e void estoque_liberar(Estoque *e).
//
// Adicione Arroz (12), Feijão (30), Café (8), Açúcar (15) e Leite (24).
// Remova "Feijão" e depois "Macarrão" (que não existe).
//
//   Saída esperada:
//   remover Feijão: ok
//   remover Macarrão: não encontrado
//   4 produtos (capacidade 8):
//     Arroz: 12
//     Café: 8
//     Açúcar: 15
//     Leite: 24
//
// Dicas:
// 1. Comece com {NULL, 0, 0}: realloc(NULL, ...) funciona como malloc.
// 2. Dobre a capacidade quando n == cap (0 vira 2).
// 3. Para remover o índice i: for (int j = i; j < e->n - 1; j++)
//    e->v[j] = e->v[j + 1]; e depois e->n--.
// 4. Resposta esperada: a saída acima, sem vazamento no ASan.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
