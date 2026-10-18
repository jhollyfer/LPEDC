// 0144 · Árvores gerais
// Exercício E861 · ★★☆
//
// No orçamento da reforma (a árvore do texto), escreva caminho(r, nome): ela
// mostra a trilha da raiz até o item, separada por " > ", e a profundidade
// do item. Se o item não existir, avisa.
//
//   Saída esperada:
//   vaso: reforma > banheiro > loucas > vaso (profundidade 3)
//   pia: reforma > cozinha > pia (profundidade 2)
//   reforma: reforma (profundidade 0)
//   janela: não encontrado
//
// Dicas:
// 1. Use um vetor de ponteiros como pilha: const NoG *trilha[32]. Uma função
//    recursiva acha(r, nome, trilha, nivel) põe r em trilha[nivel]; se r é o
//    item, devolve nivel; senão tenta cada filho com nivel + 1.
// 2. Se nenhum filho achou, devolva -1. O que ficou em trilha[0..nivel] na
//    volta é exatamente o caminho (as posições de quem falhou são
//    sobrescritas pelos próximos irmãos).
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (escreva caminho):

#include <stdio.h>
#include <string.h>
#include "arvgen.h"

int main(void) {
    NoG *reforma = ag_cria("reforma", 0);
    NoG *cozinha = ag_adiciona(reforma, "cozinha", 0);
    ag_adiciona(cozinha, "piso", 1800);
    ag_adiciona(cozinha, "pia", 650);
    NoG *banheiro = ag_adiciona(reforma, "banheiro", 0);
    ag_adiciona(banheiro, "box", 900);
    NoG *loucas = ag_adiciona(banheiro, "loucas", 0);
    ag_adiciona(loucas, "vaso", 420);
    ag_adiciona(loucas, "cuba", 280);
    ag_adiciona(reforma, "pintura", 1200);

    // caminho(reforma, "vaso"); caminho(reforma, "pia"); ...

    ag_libera(reforma);
    return 0;
}
