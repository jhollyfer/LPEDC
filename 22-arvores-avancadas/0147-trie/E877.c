// 0147 · Trie
// Exercício E877 · ★☆☆
//
// O cartório quer saber quantos nomes da lista de registros começam com um
// prefixo. Escreva conta_com_prefixo(r, prefixo) usando a trie do TAD
// (trie.h): ache o nó do prefixo com trie_prefixo e conte quantas palavras
// terminam nele ou abaixo dele.
//
//   Saída esperada:
//   começam com "an": 5
//   começam com "ana": 3
//   começam com "br": 2
//   começam com "c": 0
//   começam com "": 8
//
// Dicas:
// 1. Escreva antes conta_palavras(n): NULL dá 0; senão, (n->fim ? 1 : 0)
//    mais a contagem de cada um dos 26 filhos.
// 2. trie_prefixo devolve NULL quando nenhum nome começa com o prefixo, e
//    a raiz quando o prefixo é "".
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "trie.h"

int main(void) {
    const char *nomes[] = {"ana", "analu", "anabel", "andre", "antonio", "bruno", "bruna", "beatriz"};
    NoTrie *t = trie_cria();
    for (int i = 0; i < 8; i++) {
        trie_insere(t, nomes[i]);
    }

    trie_libera(t);
    return 0;
}
