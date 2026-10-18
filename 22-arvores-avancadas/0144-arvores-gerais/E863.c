// 0144 · Árvores gerais
// Exercício E863 · ★★★
//
// Ache o bug. A lanchonete tira itens do cardápio com remove_filho(pai,
// nome): a função acha o filho na fila de irmãos, solta esse filho da fila
// e libera a subárvore dele inteira. Este código tem UM erro: rode e veja o
// AddressSanitizer acusar heap-use-after-free. Conserte a função e rode de
// novo até sair limpo.
//
//   Saída esperada:
//   cardapio: 76
//     lanches: 54
//       xburguer: 22
//       xsalada: 20
//       misto: 12
//     bebidas: 14
//       suco: 9
//       cafe: 5
//     sobremesas: 8
//       pudim: 8
//   Tirou bebidas: sim
//   Tirou misto: não (não é filho direto do cardapio)
//   Tirou misto de lanches: sim
//   cardapio: 50
//     lanches: 42
//       xburguer: 22
//       xsalada: 20
//     sobremesas: 8
//       pudim: 8
//
// Dicas:
// 1. Leia o relatório do sanitizer: ele mostra a linha do acesso proibido e
//    a linha do free que devolveu aquela memória.
// 2. Depois de ag_libera(p), o nó p não existe mais. Quais campos de p o
//    código ainda lê depois disso?
// 3. Resposta esperada: o religamento (pai->filho = p->irmao ou
//    ant->irmao = p->irmao) tem que vir ANTES de ag_libera(p). Com a ordem
//    trocada, a saída é a de cima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "arvgen.h"

bool remove_filho(NoG *pai, const char *nome) {
    NoG *ant = NULL;
    NoG *p = pai->filho;
    while (p != NULL && strcmp(p->nome, nome) != 0) {
        ant = p;
        p = p->irmao;
    }
    if (p == NULL) {
        return false; // não é filho direto de pai
    }
    ag_libera(p); // libera o item e tudo o que está embaixo dele
    if (ant == NULL) {
        pai->filho = p->irmao; // era o primeiro filho
    } else {
        ant->irmao = p->irmao; // pula o removido
    }
    return true;
}

int main(void) {
    NoG *cardapio = ag_cria("cardapio", 0);
    NoG *lanches = ag_adiciona(cardapio, "lanches", 0);
    ag_adiciona(lanches, "xburguer", 22);
    ag_adiciona(lanches, "xsalada", 20);
    ag_adiciona(lanches, "misto", 12);
    NoG *bebidas = ag_adiciona(cardapio, "bebidas", 0);
    ag_adiciona(bebidas, "suco", 9);
    ag_adiciona(bebidas, "cafe", 5);
    NoG *sobremesas = ag_adiciona(cardapio, "sobremesas", 0);
    ag_adiciona(sobremesas, "pudim", 8);

    ag_mostra(cardapio);
    printf("Tirou bebidas: %s\n", remove_filho(cardapio, "bebidas") ? "sim" : "não");
    printf("Tirou misto: %s\n", remove_filho(cardapio, "misto") ? "sim"
                                    : "não (não é filho direto do cardapio)");
    printf("Tirou misto de lanches: %s\n", remove_filho(lanches, "misto") ? "sim" : "não");
    ag_mostra(cardapio);

    ag_libera(cardapio);
    return 0;
}
