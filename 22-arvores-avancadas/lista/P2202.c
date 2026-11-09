// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2202 · ★☆☆ · Quem tem mais filhos
//
// A árvore genealógica da família Saraiva está em filho-esquerdo/irmão-
// direito. Escreva do zero o struct, a montagem (a mesma do main da
// resposta, com as funções novo e filho) e a função mais_filhos(r, &max),
// que percorre a árvore toda e devolve o nó com mais filhos (no empate, o
// primeiro encontrado na pré-ordem). Mostre também quantos filhos cada
// pessoa tem, em pré-ordem, com recuo de 2 espaços por nível.
//
//   Raimundo: filhos Joana, Pedro, Rita
//   Joana: filhos Ana, Bruno
//   Pedro: filhos Caio, Davi, Elis, Fábio
//   Rita: filha Gabi
//   Elis: filha Helena
//
//   Saída esperada:
//   Raimundo (3)
//     Joana (2)
//       Ana (0)
//       Bruno (0)
//     Pedro (4)
//       Caio (0)
//       Davi (0)
//       Elis (1)
//         Helena (0)
//       Fábio (0)
//     Rita (1)
//       Gabi (0)
//   Mais filhos: Pedro, com 4
//
// Dicas:
// 1. O número de filhos de r é o tamanho da lista r->filho, r->filho->irmao...
// 2. Na pré-ordem com recuo, chame mostra(r->filho, nivel + 1) para os
//    filhos e mostra(r->irmao, nivel) para os irmãos.
// 3. Resposta esperada: Pedro, com 4 filhos.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
