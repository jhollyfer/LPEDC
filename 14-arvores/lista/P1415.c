// Lista · Módulo 14 · Árvores
// Exercício P1415 · ★★☆ · A AVL contando as rotações
//
// Escreva uma AVL do zero (nó com chave, alt, esq e dir; altura em arestas,
// vazia = -1; fator = alt(esq) - alt(dir)) e insira os pedidos 10, 30, 20, 5,
// 4, 40, 50, 45, 8, 9. Depois de cada inserção, mostre a pré-ordem e, se
// houve rotação, qual foi. Guarde o nome numa variável global
// const char *ultima_rotacao, zerada ("") antes de cada inserção:
//
// - fator > 1 e fator(esq) >= 0: "simples à direita (LL)"
// - fator > 1 e fator(esq) < 0: "dupla esquerda-direita (LR)"
// - fator < -1 e fator(dir) <= 0: "simples à esquerda (RR)"
// - fator < -1 e fator(dir) > 0: "dupla direita-esquerda (RL)"
//
//   Saída esperada:
//   +10: 10
//   +30: 10 30
//   +20: 20 10 30   <- rotação dupla direita-esquerda (RL)
//   +5: 20 10 5 30
//   +4: 20 5 4 10 30   <- rotação simples à direita (LL)
//   +40: 20 5 4 10 30 40
//   +50: 20 5 4 10 40 30 50   <- rotação simples à esquerda (RR)
//   +45: 20 5 4 10 40 30 50 45
//   +8: 20 5 4 10 8 40 30 50 45
//   +9: 20 5 4 9 8 10 40 30 50 45   <- rotação dupla esquerda-direita (LR)
//   altura final: 3
//
// Dicas:
// 1. Na rotação, atualize primeiro o nó que DESCEU e depois o que subiu.
// 2. Na volta da recursão: atualiza(r), olha o fator e gira se precisar.
// 3. No +4, quem desequilibra é o 10 (não a raiz): a rotação acontece no
//    nó desbalanceado mais baixo, e os de cima voltam a ficar em ordem.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave, alt;
    struct No *esq, *dir;
} No;

const char *ultima_rotacao = "";

int main(void) {

    return 0;
}
