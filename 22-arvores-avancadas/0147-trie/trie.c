// trie.c · implementação do TAD trie (árvore de prefixos)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

NoTrie *trie_cria(void) {
    NoTrie *n = calloc(1, sizeof(NoTrie)); // calloc: 26 ponteiros NULL e fim = false
    if (n == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    return n;
}

bool trie_insere(NoTrie *r, const char *palavra) {
    for (const char *p = palavra; *p != '\0'; p++) { // confere antes de mexer
        if (*p < 'a' || *p > 'z') {
            return false;
        }
    }
    for (; *palavra != '\0'; palavra++) {
        int i = *palavra - 'a';
        if (r->filho[i] == NULL) {
            r->filho[i] = trie_cria(); // o caminho ainda não existe: cria
        }
        r = r->filho[i];
    }
    r->fim = true; // marca o fim da palavra
    return true;
}

const NoTrie *trie_prefixo(const NoTrie *r, const char *prefixo) {
    for (; *prefixo != '\0' && r != NULL; prefixo++) {
        if (*prefixo < 'a' || *prefixo > 'z') {
            return NULL;
        }
        r = r->filho[*prefixo - 'a'];
    }
    return r;
}

bool trie_busca(const NoTrie *r, const char *palavra) {
    const NoTrie *n = trie_prefixo(r, palavra);
    return n != NULL && n->fim; // o caminho existe E termina uma palavra
}

// percorre a subárvore em ordem de letra, montando a palavra em buf
static void coleta(const NoTrie *n, char buf[], int nivel, int max, int *achadas) {
    if (*achadas >= max) {
        return;
    }
    if (n->fim) {
        buf[nivel] = '\0';
        printf(" %s", buf);
        (*achadas)++;
    }
    for (int i = 0; i < TRIE_LETRAS && nivel < TRIE_MAX - 1; i++) {
        if (n->filho[i] != NULL) {
            buf[nivel] = (char)('a' + i);
            coleta(n->filho[i], buf, nivel + 1, max, achadas);
        }
    }
}

int trie_autocompleta(const NoTrie *r, const char *prefixo, int max) {
    const NoTrie *n = trie_prefixo(r, prefixo);
    int achadas = 0;
    size_t tam = strlen(prefixo);
    if (n == NULL || tam >= TRIE_MAX) {
        return 0;
    }
    char buf[TRIE_MAX];
    memcpy(buf, prefixo, tam); // a palavra começa pelo prefixo
    coleta(n, buf, (int)tam, max, &achadas);
    return achadas;
}

int trie_nos(const NoTrie *r) {
    if (r == NULL) {
        return 0;
    }
    int total = 1;
    for (int i = 0; i < TRIE_LETRAS; i++) {
        total += trie_nos(r->filho[i]);
    }
    return total;
}

void trie_libera(NoTrie *r) {
    if (r == NULL) {
        return;
    }
    for (int i = 0; i < TRIE_LETRAS; i++) {
        trie_libera(r->filho[i]);
    }
    free(r);
}
