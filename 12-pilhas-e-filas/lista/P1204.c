// Lista · Módulo 12 · Pilhas e filas
// Exercício P1204 · ★☆☆ · Quão fundo vão os parênteses?
//
// A planilha aceita fórmulas com (), [] e {}. Escreva
//
//   int profundidade(const char *s)
//
// que confere se os delimitadores estão bem casados (com uma pilha de char
// sobre vetor) e devolve a PROFUNDIDADE máxima de aninhamento, ou -1 se a
// fórmula estiver mal formada. Os outros caracteres são ignorados.
//
//   Saída esperada:
//   (a+b): 1
//   {[(x)]}: 3
//   (a)[b]{c}: 1
//   ((1+2)*[3-(4/5)]): 3
//   ([)]: -1
//   ((: -1
//
// Dicas:
// 1. A profundidade num instante é o tamanho da pilha. Depois de cada
//    empilha, compare o tamanho com o maior visto até ali.
// 2. No fechamento, a pilha não pode estar vazia e o topo tem que ser o
//    abre do mesmo tipo. No fim da string, a pilha tem que estar vazia.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
