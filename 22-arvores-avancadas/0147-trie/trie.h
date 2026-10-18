// trie.h · interface do TAD trie (árvore de prefixos) de letras minúsculas
#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>

#define TRIE_LETRAS 26  // de 'a' a 'z'
#define TRIE_MAX 64     // tamanho máximo de uma palavra (com o '\0')

typedef struct NoTrie {
    struct NoTrie *filho[TRIE_LETRAS]; // filho['c' - 'a'] segue a letra c
    bool fim;                          // uma palavra termina aqui?
} NoTrie;

NoTrie *trie_cria(void);

// insere a palavra; devolve false (e não insere) se ela tiver algo fora de a-z
bool trie_insere(NoTrie *r, const char *palavra);

bool trie_busca(const NoTrie *r, const char *palavra);

// o nó onde o prefixo termina, ou NULL se nenhuma palavra começa assim
const NoTrie *trie_prefixo(const NoTrie *r, const char *prefixo);

// mostra (" palavra") até max palavras que começam com o prefixo, em ordem
// alfabética, e devolve quantas mostrou
int trie_autocompleta(const NoTrie *r, const char *prefixo, int max);

int trie_nos(const NoTrie *r);  // quantos nós existem (a raiz conta)

void trie_libera(NoTrie *r);

#endif
