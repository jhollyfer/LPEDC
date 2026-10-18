// 0147 · Trie
// Exercício E880 · ★★☆

#include <stdio.h>
#include <string.h>
#include "trie.h"

// guarda em maior a palavra mais comprida (a primeira em ordem alfabética, se
// houver empate) da subárvore de n; buf tem as letras do caminho até n
void maior_palavra(const NoTrie *n, char buf[], int nivel, char maior[]) {
    if (n->fim && nivel > (int)strlen(maior)) { // > e não >=: o empate fica com a primeira
        buf[nivel] = '\0';
        strcpy(maior, buf);
    }
    for (int i = 0; i < TRIE_LETRAS; i++) {
        if (n->filho[i] != NULL) {
            buf[nivel] = (char)('a' + i);
            maior_palavra(n->filho[i], buf, nivel + 1, maior);
        }
    }
}

// mostra as palavras com exatamente alvo letras
void por_tamanho(const NoTrie *n, char buf[], int nivel, int alvo) {
    if (nivel == alvo) {
        if (n->fim) {
            buf[nivel] = '\0';
            printf(" %s", buf);
        }
        return; // mais fundo, as palavras ficam maiores que alvo
    }
    for (int i = 0; i < TRIE_LETRAS; i++) {
        if (n->filho[i] != NULL) {
            buf[nivel] = (char)('a' + i);
            por_tamanho(n->filho[i], buf, nivel + 1, alvo);
        }
    }
}

int main(void) {
    const char *zoo[] = {"gato", "girafa", "guaxinim", "hipopotamo", "jacare", "onca",
                         "ornitorrinco", "rinoceronte", "tatu", "tamandua", "orangotango"};
    NoTrie *t = trie_cria();
    for (int i = 0; i < 11; i++) {
        trie_insere(t, zoo[i]);
    }
    char buf[TRIE_MAX], maior[TRIE_MAX] = "";
    maior_palavra(t, buf, 0, maior);
    printf("maior: %s (%zu letras)\n", maior, strlen(maior));
    int tamanhos[] = {4, 6, 11};
    for (int k = 0; k < 3; k++) {
        printf("com %d letras:", tamanhos[k]);
        por_tamanho(t, buf, 0, tamanhos[k]);
        printf("\n");
    }
    trie_libera(t);
    return 0;
}
