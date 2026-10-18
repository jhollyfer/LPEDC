// 0152 · Kruskal: árvore geradora mínima
// Exercício E907 · ★☆☆
//
// A horta comunitária vai levar água a cinco canteiros com mangueira. Os
// trechos possíveis já vêm em ordem crescente de metros:
//
//   Alface-Couve 2, Tomate-Ervas 3, Alface-Tomate 4, Couve-Tomate 5,
//   Cenoura-Ervas 6, Couve-Cenoura 8, Alface-Ervas 9
//
// Escreva o Kruskal do zero, sem union-find: guarde em grupo[v] o número
// do grupo de cada canteiro (começa com grupo[v] = v). Uma aresta entre
// grupos iguais fecharia ciclo; entre grupos diferentes, aceite e passe
// todo o grupo de b para o grupo de a.
//
//   Saída esperada:
//   Alface-Couve (2 m)
//   Tomate-Ervas (3 m)
//   Alface-Tomate (4 m)
//   Cenoura-Ervas (6 m)
//   Mangueira total: 15 m
//
// Dicas:
// 1. Guarde o grupo velho de b numa variável ANTES do laço que troca:
//    int velho = grupo[b]. Se usar grupo[b] dentro do laço, ele muda no
//    meio do caminho.
// 2. Pare quando tiver V - 1 = 4 trechos aceitos.
// 3. Resposta esperada: a saída acima. Couve-Tomate (5) é descartado:
//    Couve e Tomate já estão ligados por Alface. Juntar grupos assim custa
//    O(V) por aresta, o que o union-find do assunto 0148 resolve.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
