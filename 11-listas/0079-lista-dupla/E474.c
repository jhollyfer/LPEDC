// 0079 · Lista dupla
// Exercício E474 · ★★★
//
// Todo editor de texto tem um cursor que anda para os dois lados, e uma
// lista dupla de letras é um jeito clássico de fazer isso: inserir e apagar
// na posição do cursor custa O(1). Simule o teclado com a string de teclas
//
//   "progamr#<<r>>a"
//
// onde letra insere na posição do cursor, '<' anda uma letra para a
// esquerda, '>' anda para a direita e '#' apaga a letra à esquerda do
// cursor (o backspace). Nas pontas, '<', '>' e '#' não fazem nada. No fim,
// mostre o texto com uma '|' onde está o cursor.
//
//   Saída esperada:
//   texto: programa|
//
// Escreva tudo neste arquivo, com uma struct sua (por exemplo
// struct letra { char c; struct letra *ant, *prox; }).
//
// Dicas:
// 1. Use um nó-cabeça (uma letra de mentira no começo). O cursor é um
//    ponteiro para a letra que está À ESQUERDA dele; no começo do texto, ele
//    aponta para a cabeça. Assim nunca existe "cursor NULL".
// 2. Inserir: o novo entra depois do cursor (as quatro setas do E472) e o
//    cursor passa para o novo. Apagar: se o cursor não é a cabeça, tire o nó
//    do cursor e volte o cursor para o ant dele.
// 3. Faça um teste de mesa: depois de "progamr#" o texto é "progam|";
//    "<<" deixa "prog|am"; o "r" faz "progr|am"; ">>" e "a" terminam.
// 4. Resposta esperada: texto: programa|
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
