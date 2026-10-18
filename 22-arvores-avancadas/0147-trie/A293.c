// A293 · Quanto custa uma trie

#include <stdio.h>
#include <string.h>
#include "trie.h"

// conta os ponteiros de filho que estão em NULL (vagas sem uso)
int nulos(const NoTrie *r) {
    int total = 0;
    for (int i = 0; i < TRIE_LETRAS; i++) {
        if (r->filho[i] == NULL) {
            total++;
        } else {
            total += nulos(r->filho[i]);
        }
    }
    return total;
}

int main(void) {
    const char *feira[] = {"alface", "alho", "abacate", "abacaxi", "banana", "batata",
                           "beterraba", "cebola", "cenoura", "chuchu", "couve", "laranja",
                           "limao", "mamao", "manga", "maracuja", "melancia", "milho",
                           "tomate", "uva", "Pera", "caqui!"};
    int n = sizeof feira / sizeof feira[0];
    NoTrie *t = trie_cria();
    int aceitas = 0;
    size_t letras = 0;
    for (int i = 0; i < n; i++) {
        if (trie_insere(t, feira[i])) {
            aceitas++;
            letras += strlen(feira[i]);
        } else {
            printf("recusada: %s (só a-z)\n", feira[i]);
        }
    }

    int nos = trie_nos(t);
    printf("%d palavras, %zu letras no total\n", aceitas, letras);
    printf("trie: %d nós x %zu bytes = %zu bytes\n", nos, sizeof(NoTrie), nos * sizeof(NoTrie));
    printf("as mesmas palavras em strings: %zu bytes (letras + um '\\0' cada)\n",
           letras + aceitas);
    printf("ponteiros em NULL: %d de %d (%.1f%%)\n", nulos(t), nos * TRIE_LETRAS,
           100.0 * nulos(t) / (nos * TRIE_LETRAS));

    trie_libera(t);
    return 0;
}
// Saída:
// recusada: Pera (só a-z)
// recusada: caqui! (só a-z)
// 20 palavras, 121 letras no total
// trie: 100 nós x 216 bytes = 21600 bytes
// as mesmas palavras em strings: 141 bytes (letras + um '\0' cada)
// ponteiros em NULL: 2501 de 2600 (96.2%)
