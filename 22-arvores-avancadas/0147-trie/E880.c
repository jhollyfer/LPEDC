// 0147 · Trie
// Exercício E880 · ★★☆
//
// Os bichos do zoológico estão numa trie (trie.h). Escreva duas funções que
// percorrem a trie montando a palavra num buffer, como a coleta do trie.c:
// - maior_palavra(n, buf, nivel, maior): copia para maior a palavra mais
//  comprida (no empate, a primeira em ordem alfabética);
// - por_tamanho(n, buf, nivel, alvo): mostra as palavras com exatamente alvo
//  letras, sem descer além do nível alvo.
//
//   Saída esperada:
//   maior: ornitorrinco (12 letras)
//   com 4 letras: gato onca tatu
//   com 6 letras: girafa jacare
//   com 11 letras: orangotango rinoceronte
//
// Dicas:
// 1. Em cada nó, nivel é quantas letras já estão em buf. Quando n->fim é
//    verdadeiro, buf[nivel] = '\0' fecha a palavra.
// 2. Em maior_palavra, troque só quando nivel > strlen(maior): com >=, o
//    empate ficaria com a última em ordem alfabética.
// 3. Resposta esperada: a saída acima. Em por_tamanho, quando nivel == alvo,
//    confira o fim e volte (return) sem olhar os filhos.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include "trie.h"

int main(void) {
    const char *zoo[] = {"gato", "girafa", "guaxinim", "hipopotamo", "jacare", "onca",
                         "ornitorrinco", "rinoceronte", "tatu", "tamandua", "orangotango"};
    NoTrie *t = trie_cria();
    for (int i = 0; i < 11; i++) {
        trie_insere(t, zoo[i]);
    }

    trie_libera(t);
    return 0;
}
