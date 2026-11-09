// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2826 · ★★★ · Relatório por intervalo
//
// O sistema da farmácia guarda os códigos dos remédios 412, 157, 890, 233,
// 501, 678, 120, 345, 999, 460 numa BST com pai. Escreva teto(raiz, a) (o
// primeiro nó com chave >= a, descendo da raiz) e sucessor(x), e com eles
// relatorio(raiz, a, b), que mostra em ordem as chaves de a até b e conta
// quantas chamadas de sucessor foram feitas. Teste [200, 500], [0, 150],
// [900, 2000] e [600, 650].
//
//   Saída esperada:
//   [200, 500]: 233 345 412 460 (4 sucessores)
//   [0, 150]: 120 (1 sucessores)
//   [900, 2000]: 999 (1 sucessores)
//   [600, 650]: (0 sucessores)
//
// Dicas:
// 1. No teto, quando x->chave >= a, x vira candidato e você desce à
//    esquerda; senão, à direita.
// 2. O laço: for (x = teto(raiz, a); x != NULL && x->chave <= b; x =
//    sucessor(x)).
// 3. Num intervalo vazio, o teto já passa de b e nenhum sucessor é chamado.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
