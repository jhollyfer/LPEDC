// 0147 · Trie
// Exercício E882 · ★★★

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

static bool sem_filhos(const NoTrie *n) {
    for (int i = 0; i < TRIE_LETRAS; i++) {
        if (n->filho[i] != NULL) {
            return false;
        }
    }
    return true;
}

// tira a palavra p da subárvore de n; *tirou diz se ela estava lá.
// Devolve true se n ficou inútil (sem fim e sem filhos) e pode ser liberado.
bool remove_palavra(NoTrie *n, const char *p, bool *tirou) {
    if (*p == '\0') {
        *tirou = n->fim;
        n->fim = false;
    } else {
        int i = *p - 'a';
        if (i < 0 || i >= TRIE_LETRAS || n->filho[i] == NULL) {
            *tirou = false;
            return false; // a palavra não existe: nada muda
        }
        if (remove_palavra(n->filho[i], p + 1, tirou)) {
            free(n->filho[i]); // o filho ficou inútil: poda
            n->filho[i] = NULL;
        }
    }
    return !n->fim && sem_filhos(n);
}

void tira(NoTrie *r, const char *p) {
    bool tirou;
    remove_palavra(r, p, &tirou);
    r->fim = false; // a raiz nunca é liberada aqui (e "" não é palavra)
    printf("tira %s: %s | nós: %d | sobram:", p, tirou ? "tirou" : "não estava", trie_nos(r));
    trie_autocompleta(r, "", 10);
    printf("\n");
}

int main(void) {
    const char *palavras[] = {"sol", "sola", "solado", "solteiro", "sal"};
    NoTrie *t = trie_cria();
    for (int i = 0; i < 5; i++) {
        trie_insere(t, palavras[i]);
    }
    printf("início | nós: %d | palavras:", trie_nos(t));
    trie_autocompleta(t, "", 10);
    printf("\n");
    tira(t, "solado");
    tira(t, "so");
    tira(t, "sol");
    tira(t, "solteiro");
    tira(t, "sal");
    tira(t, "sola");
    trie_libera(t);
    return 0;
}
