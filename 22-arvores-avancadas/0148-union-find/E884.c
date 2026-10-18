// 0148 · Union-find
// Exercício E884 · ★☆☆
//
// O condomínio tem 12 apartamentos (0 a 11) e um aplicativo de mensagens em
// que cada morador entra por convite de outro. Depois dos convites, escreva
// duas funções que leem os campos do UF (uniao.h):
// - maior_grupo(u): quantos apartamentos tem o maior grupo;
// - sozinhos(u): quantos apartamentos não estão com ninguém.
//
//   Saída esperada:
//   grupos: 5 | maior: 5 apartamentos | sozinhos: 2
//
// Dicas:
// 1. Só a raiz de cada grupo (pai[x] == x) guarda o tamanho certo em tam[x].
//    Nos outros elementos, tam é um valor antigo, de quando eram raiz.
// 2. Percorra x de 0 a u->n - 1 olhando só as raízes. Nenhuma das duas
//    funções precisa chamar uf_acha.
// 3. Resposta esperada: a saída acima. Os grupos são {0, 3, 7, 9, 11},
//    {1, 2, 6}, {4, 5}, {8} e {10}.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "uniao.h"

int main(void) {
    // apartamentos 0 a 11; cada par entrou no grupo de mensagens pelo convite do outro
    int convites[][2] = {{0, 3}, {3, 7}, {1, 2}, {7, 9}, {4, 5}, {2, 6}, {9, 11}, {6, 1}};
    UF *u = uf_cria(12);
    for (int i = 0; i < 8; i++) {
        uf_une(u, convites[i][0], convites[i][1]);
    }

    uf_libera(u);
    return 0;
}
