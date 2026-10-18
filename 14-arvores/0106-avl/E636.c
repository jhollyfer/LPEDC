// 0106 · AVL: balanceamento e rotações
// Exercício E636 · ★★★
//
// Escreva do zero (sem o avl.h) uma AVL que, a cada rotação, conta qual dos
// quatro casos aconteceu e em qual nó. Insira estes pedidos, nesta ordem:
//
//   30 25 15 45 60 35 20
//
//   Saída esperada:
//   Insere 15: esquerda-esquerda no 30
//   Insere 60: direita-direita no 30
//   Insere 35: direita-esquerda no 25
//   Insere 20: esquerda-direita no 25
//   Em ordem: 15 20 25 30 35 45 60
//   Pré-ordem: 30 20 15 25 45 35 60
//
// (Pedidos que não causam rotação não imprimem nada.)
//
// Dicas:
// 1. Struct com chave, altura, esq e dir; funções altura, fator, atualiza,
//    gira_dir e gira_esq como no texto.
// 2. Para imprimir "Insere X", passe a chave que está sendo inserida como
//    parâmetro extra da função recursiva. O caso sai do fator do nó (+2 ou
//    -2) e do fator do filho do lado pesado.
// 3. Resposta esperada: a saída acima. Libere tudo no fim.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
