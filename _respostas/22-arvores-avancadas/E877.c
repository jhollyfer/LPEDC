// 0147 · Trie
// Exercício E877 · ★☆☆

#include <stdio.h>
#include "trie.h"

// quantas palavras terminam no nó n ou abaixo dele
int conta_palavras(const NoTrie *n) {
    if (n == NULL) {
        return 0;
    }
    int total = n->fim ? 1 : 0;
    for (int i = 0; i < TRIE_LETRAS; i++) {
        total += conta_palavras(n->filho[i]);
    }
    return total;
}

int conta_com_prefixo(const NoTrie *r, const char *prefixo) {
    return conta_palavras(trie_prefixo(r, prefixo));
}

int main(void) {
    const char *nomes[] = {"ana", "analu", "anabel", "andre", "antonio", "bruno", "bruna", "beatriz"};
    NoTrie *t = trie_cria();
    for (int i = 0; i < 8; i++) {
        trie_insere(t, nomes[i]);
    }
    const char *prefixos[] = {"an", "ana", "br", "c", ""};
    for (int i = 0; i < 5; i++) {
        printf("começam com \"%s\": %d\n", prefixos[i], conta_com_prefixo(t, prefixos[i]));
    }
    trie_libera(t);
    return 0;
}
