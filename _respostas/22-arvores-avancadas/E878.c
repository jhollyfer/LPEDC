// 0147 · Trie
// Exercício E878 · ★☆☆

#include <stdio.h>
#include "trie.h"

const char *classifica(const NoTrie *r, const char *texto) {
    const NoTrie *n = trie_prefixo(r, texto);
    if (n == NULL) {
        return "não está";
    }
    return n->fim ? "comando" : "só começo de comando";
}

int main(void) {
    const char *comandos[] = {"cd", "cat", "chmod", "chown", "ls", "less", "mkdir", "man"};
    NoTrie *t = trie_cria();
    for (int i = 0; i < 8; i++) {
        trie_insere(t, comandos[i]);
    }
    const char *digitado[] = {"cat", "ch", "le", "less", "rm", "c", "mkdirs"};
    for (int i = 0; i < 7; i++) {
        printf("%-7s %s\n", digitado[i], classifica(t, digitado[i]));
    }
    trie_libera(t);
    return 0;
}
