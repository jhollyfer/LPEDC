// 0147 · Trie
// Exercício E882 · ★★★
//
// O TAD não sabe tirar palavras. Escreva remove_palavra(n, p, &tirou) com
// poda: desmarque o fim da palavra e libere os nós que ficarem inúteis (sem
// fim e sem filhos), de baixo para cima. Os nós que outra palavra ainda usa
// ficam. O main tira palavras uma a uma e mostra o tamanho da trie.
//
//   Saída esperada:
//   início | nós: 14 | palavras: sal sol sola solado solteiro
//   tira solado: tirou | nós: 12 | sobram: sal sol sola solteiro
//   tira so: não estava | nós: 12 | sobram: sal sol sola solteiro
//   tira sol: tirou | nós: 12 | sobram: sal sola solteiro
//   tira solteiro: tirou | nós: 7 | sobram: sal sola
//   tira sal: tirou | nós: 5 | sobram: sola
//   tira sola: tirou | nós: 1 | sobram:
//
// Escreva sua resposta abaixo (escreva remove_palavra):

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

// tira a palavra p da subárvore de n; em *tirou, diz se ela estava lá.
// Devolve true se n ficou inútil (sem fim e sem filhos) e pode ser liberado.
bool remove_palavra(NoTrie *n, const char *p, bool *tirou) {
    (void)n; // apague estas três linhas
    (void)p;
    *tirou = false;
    return false;
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
