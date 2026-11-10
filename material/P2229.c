// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2229 · ★★★ · As três sugestões mais usadas
//
// O teclado do celular aprende com o que você digita: cada palavra fica
// numa trie com um contador de vezes. Ao digitar um prefixo, ele sugere
// as TRÊS palavras mais usadas que começam com ele (empate: ordem
// alfabética). Escreva do zero: monte a trie com as palavras do texto
// abaixo (o main já separa as palavras), depois, para cada prefixo, desça
// até o nó do prefixo, colete todas as palavras da subárvore com seus
// contadores, ordene com qsort e mostre as três primeiras.
//
//   Texto: "bom dia boa tarde bom jogo bola bonita bom dia boa noite
//   bolo de bolo bom bolo tarde tapioca taxi tapioca tarde bom"
//
//   Saída esperada:
//   "bo": bom (5) bolo (3) boa (2)
//   "ta": tarde (3) tapioca (2) taxi (1)
//   "bol": bolo (3) bola (1)
//   "x": nenhuma sugestão
//
// Dicas:
// 1. O nó guarda int vezes (0 se não é fim de palavra). A coleta é a do
//    autocompletar do assunto 0147: um buffer que cresce com a
//    profundidade e, em cada nó com vezes > 0, uma entrada { palavra,
//    vezes } num vetor.
// 2. Na comparação do qsort: vezes maior primeiro; se empatar, strcmp.
// 3. Resposta esperada: para "bo", bom (5), bolo (3) e boa (2).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
