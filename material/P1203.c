// Lista · Módulo 12 · Pilhas e filas
// Exercício P1203 · ★☆☆ · A pilha de livros da cabeceira
//
// Os livros da cabeceira formam uma pilha: o último que você pôs em cima é
// o primeiro que pega. Escreva uma pilha ENCADEADA de livros (título e
// páginas), com:
//
//   Livro *empilha(Livro *topo, const char *titulo, int paginas)
//   Livro *desempilha(Livro *topo, char *titulo, int *paginas)
//   int total_paginas(const Livro *topo)
//
// (empilha e desempilha devolvem o novo topo; desempilha copia o título e
// as páginas do livro que saiu e libera o nó). Empilhe Dom Casmurro (256),
// Vidas Secas (176) e Capitães da Areia (280), mostre o topo e o total de
// páginas, e desempilhe todos, mostrando cada um.
//
//   Saída esperada:
//   Topo: Capitães da Areia
//   Páginas na pilha: 712
//   Pegou Capitães da Areia (280 páginas)
//   Pegou Vidas Secas (176 páginas)
//   Pegou Dom Casmurro (256 páginas)
//
// Dicas:
// 1. Empilhar é inserir no início da lista; desempilhar é tirar do início.
//    Os dois são O(1), e a pilha não tem limite de tamanho.
// 2. Em desempilha, guarde o prox antes do free: ele é o novo topo.
// 3. Resposta esperada: a saída acima, sem vazamento.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct livro {
    char titulo[32];
    int paginas;
    struct livro *prox;
} Livro;

int main(void) {

    return 0;
}
