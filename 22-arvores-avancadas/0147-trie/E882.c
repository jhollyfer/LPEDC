// 0147 · Trie
// Exercício E882 · ★★★
//
// O TAD (trie.h) não sabe tirar palavras. Escreva bool remove_palavra(NoTrie
// *n, const char *p, bool *tirou), que desmarca o fim da palavra e libera, de
// baixo para cima, os nós que ficarem inúteis (sem fim e sem filhos); os nós
// que outra palavra ainda usa ficam. Em *tirou, diz se a palavra estava lá.
// Devolve true se n ficou inútil.
//
// Insira sol, sola, solado, solteiro e sal. Mostre o início e, depois de tirar
// cada palavra de solado, so, sol, solteiro, sal e sola, o tamanho da trie
// (trie_nos) e as palavras que sobram (trie_autocompleta com prefixo "").
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
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

int main(void) {

    return 0;
}
