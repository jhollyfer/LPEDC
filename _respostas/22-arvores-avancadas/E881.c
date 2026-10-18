// 0147 · Trie
// Exercício E881 · ★★★

#include <stdio.h>
#include <string.h>
#include "trie.h"

void junta(const NoTrie *n, char buf[], int nivel) {
    if (n->fim) {
        buf[nivel] = '\0'; // fecha a palavra no tamanho dela
        printf(" %s", buf);
    }
    for (int i = 0; i < TRIE_LETRAS; i++) {
        if (n->filho[i] != NULL) {
            buf[nivel] = (char)('a' + i);
            junta(n->filho[i], buf, nivel + 1);
        }
    }
}

void sugere(const NoTrie *r, const char *prefixo) {
    char buf[TRIE_MAX] = {0}; // tudo zerado
    strcpy(buf, prefixo);
    printf("%s:", prefixo);
    const NoTrie *n = trie_prefixo(r, prefixo);
    if (n != NULL) {
        junta(n, buf, (int)strlen(prefixo));
    }
    printf("\n");
}

int main(void) {
    const char *palavras[] = {"bolo", "bola", "bolsa", "boleto", "bom", "bombom"};
    NoTrie *t = trie_cria();
    for (int i = 0; i < 6; i++) {
        trie_insere(t, palavras[i]);
    }
    sugere(t, "bol");
    sugere(t, "bo");
    trie_libera(t);
    return 0;
}
