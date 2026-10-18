// 0144 · Árvores gerais
// Exercício E859 · ★☆☆
//
// A lista de compras do churrasco está numa árvore geral (arvgen.h). Complete
// folhas(r), que conta os nós sem filhos (os itens que vão para o carrinho),
// e grupos(r), que conta os nós com pelo menos um filho (a raiz entra).
//
//   Saída esperada:
//   Itens (folhas): 6
//   Grupos (nós com filhos): 3
//   Total: R$ 297
//
// Dicas:
// 1. Um nó é folha quando r->filho == NULL. Não olhe para r->irmao: o irmão
//    não diz nada sobre r ter ou não filhos.
// 2. Siga o molde de ag_conta no arvgen.c: some a resposta de cada filho com
//    o laço for (p = r->filho; p != NULL; p = p->irmao).
// 3. Resposta esperada: a saída acima (picanha, linguica, frango, refri,
//    cerveja e carvao são as folhas; churrasco, carnes e bebidas, os grupos).
//
// Escreva sua resposta abaixo (complete folhas e grupos):

#include <stdio.h>
#include "arvgen.h"

int folhas(const NoG *r) {
    (void)r; // apague esta linha
    return 0;
}

int grupos(const NoG *r) {
    (void)r; // apague esta linha
    return 0;
}

int main(void) {
    NoG *churrasco = ag_cria("churrasco", 0);
    NoG *carnes = ag_adiciona(churrasco, "carnes", 0);
    ag_adiciona(carnes, "picanha", 120);
    ag_adiciona(carnes, "linguica", 35);
    ag_adiciona(carnes, "frango", 28);
    NoG *bebidas = ag_adiciona(churrasco, "bebidas", 0);
    ag_adiciona(bebidas, "refri", 24);
    ag_adiciona(bebidas, "cerveja", 60);
    ag_adiciona(churrasco, "carvao", 30);

    printf("Itens (folhas): %d\n", folhas(churrasco));
    printf("Grupos (nós com filhos): %d\n", grupos(churrasco));
    printf("Total: R$ %d\n", ag_total(churrasco));

    ag_libera(churrasco);
    return 0;
}
