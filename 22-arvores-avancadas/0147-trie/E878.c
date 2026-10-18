// 0147 · Trie
// Exercício E878 · ★☆☆
//
// O terminal completa comandos com a tecla Tab. Com os comandos guardados
// numa trie (trie.h), escreva classifica(r, texto), que devolve uma de três
// mensagens: "comando" (o texto é um comando inteiro), "só começo de comando"
// (algum comando começa assim, mas o texto não é um) ou "não está".
//
//   Saída esperada:
//   cat     comando
//   ch      só começo de comando
//   le      só começo de comando
//   less    comando
//   rm      não está
//   c       só começo de comando
//   mkdirs  não está
//
// Dicas:
// 1. Use trie_prefixo: NULL quer dizer que nenhum comando começa assim.
// 2. Achou o nó? O campo fim decide entre as outras duas mensagens.
// 3. Resposta esperada: a saída acima. Imprima com printf("%-7s %s\n", ...).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "trie.h"

int main(void) {
    const char *comandos[] = {"cd", "cat", "chmod", "chown", "ls", "less", "mkdir", "man"};
    NoTrie *t = trie_cria();
    for (int i = 0; i < 8; i++) {
        trie_insere(t, comandos[i]);
    }
    const char *digitado[] = {"cat", "ch", "le", "less", "rm", "c", "mkdirs"};
    (void)digitado; // apague esta linha

    trie_libera(t);
    return 0;
}
