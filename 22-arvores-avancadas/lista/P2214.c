// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2214 · ★★☆ · O menor apelido de cada palavra
//
// O sistema da biblioteca quer abreviar o nome de cada sala pelo MENOR
// PREFIXO que não é prefixo de nenhuma outra. As salas são: acervo,
// acesso, arquivo, auditorio, biblioteca, brinquedoteca. Escreva do zero
// uma trie em que cada nó guarda passam, quantas palavras passam por ele.
// O menor prefixo único de uma palavra termina no primeiro nó do caminho
// com passam == 1.
//
//   Saída esperada:
//   acervo: acer
//   acesso: aces
//   arquivo: ar
//   auditorio: au
//   biblioteca: bi
//   brinquedoteca: br
//
// Dicas:
// 1. Na inserção, some 1 em passam de cada nó do caminho (sem contar a
//    raiz).
// 2. Para cada palavra, desça letra a letra copiando para o buffer e pare
//    depois de copiar a letra do nó com passam == 1. Se nenhum tiver 1 (a
//    palavra é prefixo de outra), o apelido é a palavra inteira.
// 3. Resposta esperada: acer, aces, ar, au, bi, br.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
