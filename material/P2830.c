// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2830 · ★★★ · O painel de voos
//
// O painel do aeroporto guarda os horários (HHMM) 1415, 905, 1830, 640,
// 1120, 1600, 2210, 1000 numa BST com ponteiro para o pai. Escreva teto(r,
// h) (o primeiro voo às h ou depois), piso(r, h) (o último às h ou antes) e
// a remoção do Cormen com transplanta(raiz, u, v), que põe a subárvore v no
// lugar de u acertando o pai (no caso dos dois filhos, o sucessor y sobe
// para o lugar do nó removido). Para as horas 1130 e 1415, mostre o piso e o
// teto; cancele os voos 1415 (a raiz, com dois filhos) e 640 e repita,
// mostrando também a árvore em pré-ordem.
//
//   Saída esperada:
//   pré: 1415 905 640 1120 1000 1830 1600 2210
//     1130: antes 1120, depois 1415
//     1415: antes 1415, depois 1415
//   sem 1415 e 640: pré 1600 905 1120 1000 1830 2210
//     1130: antes 1120, depois 1600
//     1415: antes 1120, depois 1600
//
// Dicas:
// 1. transplanta: se u é a raiz, v vira a raiz; senão, v entra no lado de u
//    no pai; se v != NULL, v->pai = u->pai.
// 2. Dois filhos: y = mínimo(z->dir). Se y não é filho direito de z,
//    transplanta(y, y->dir) e y herda z->dir; depois transplanta(z, y) e y
//    herda z->esq.
// 3. A remoção devolve a nova raiz, que pode mudar.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
