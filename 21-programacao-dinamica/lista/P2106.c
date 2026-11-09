// Lista · Módulo 21 · Programação dinâmica
// Exercício P2106 · ★☆☆ · A maior fila em ordem de altura
//
// Na foto da turma, 10 crianças estão na ordem da chamada, com estas
// alturas em cm:
//
//   121 135 118 140 127 132 145 124 150 138
//
// Sem trocar ninguém de lugar, a professora quer tirar crianças da foto
// para que as que ficam estejam em altura crescente, deixando o MAIOR
// número possível. Isso é a SUBSEQUÊNCIA CRESCENTE MÁXIMA. Escreva do zero
// a PD O(n²): lis[i] é o tamanho da maior subsequência crescente que
// TERMINA na criança i; lis[i] = 1 + o maior lis[j] com j < i e altura[j] <
// altura[i]. Mostre lis[] e a resposta.
//
//   Saída esperada:
//   lis: 1 2 1 3 2 3 4 2 5 4
//   Maior fila crescente: 5 crianças
//
// Dicas:
// 1. Todo lis[i] começa em 1 (a criança sozinha).
// 2. A resposta é o MAIOR dos lis[i], não o último: a melhor fila pode
//    terminar em qualquer criança.
// 3. Resposta esperada: 6 crianças (por exemplo, 121 135 140 145 150, mais
//    uma... confira: 121 127 132 145 150 também tem 5; a de 6 é 121 127
//    132 140... não: veja a saída).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
