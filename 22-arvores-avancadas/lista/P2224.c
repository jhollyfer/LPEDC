// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2224 · ★★★ · Caça-palavras com trie
//
// No caça-palavras 4 × 4 da revistinha, uma palavra se forma andando por
// casas vizinhas (horizontal, vertical ou diagonal), sem repetir casa. O
// dicionário tem as palavras abaixo. Escreva do zero: guarde o dicionário
// numa trie e faça um backtracking (módulo 19) a partir de cada casa que
// desce na trie junto com o caminho; se a letra não tem filho na trie,
// CORTE o caminho na hora (nenhuma palavra começa assim). Mostre as
// palavras achadas em ordem alfabética, sem repetir, e quantas casas o
// backtracking visitou.
//
//   Grade:  C A S A
//           O R T E
//           L A M O
//           A P E S
//
//   Dicionário: casa, cara, caro, arte, mar, mesa, pe, ame, rato, lago,
//               cola, mel, sapo, tear, ramo
//
//   Saída esperada:
//   Achadas (11): ame arte cara caro casa cola mar mesa pe ramo rato
//   Casas visitadas: 54
//
// Dicas:
// 1. procura(l, c, no): pegue o filho da trie pela letra da casa; se é
//    NULL, volte. Marque a casa, se o nó é fim de palavra anote a palavra
//    (num buffer que cresce com a profundidade), tente os 8 vizinhos e
//    desmarque.
// 2. Para não repetir, desmarque o fim na trie depois de anotar a palavra
//    (ou guarde as achadas e compare).
// 3. Resposta esperada: as palavras da saída. Sem a trie, o backtracking
//    teria que seguir todos os caminhos da grade até um tamanho máximo.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
