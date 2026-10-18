// 0110 · BFS: busca em largura
// Exercício E659 · ★★★
//
// A prefeitura quer saber, para cada quarteirão do bairro, a quantos
// quarteirões de distância fica o posto de saúde MAIS PRÓXIMO. No mapa, P é
// posto, # é área sem passagem (rio, linha de trem) e . é quarteirão. Anda-se
// só para cima, baixo, esquerda e direita.
//
//   P...#...
//   .##.#.#.
//   ....#.#P
//   .#......
//   ...#..#.
//
// Mostre o mapa com a distância de cada quarteirão (0 nos postos, # onde não
// passa):
//
//   Saída esperada:
//   0123#432
//   1##4#5#1
//   2345#4#0
//   3#554321
//   456#54#2
//   Pior distância: 6
//
// Dicas:
// 1. Rodar uma BFS por posto e tirar o mínimo funciona, mas dá para fazer
//    uma BFS só: coloque TODOS os postos na fila no começo, com distância 0.
// 2. A fila mistura as ondas dos dois postos, e cada casa é descoberta
//    primeiro pelo posto mais perto. É a BFS de várias origens.
// 3. A distância cabe num dígito aqui: imprima com '0' + dist.
// 4. Resposta esperada: a saída acima. A pior casa é a da linha 4, coluna 2
//    (contando do 0): 6 quarteirões até o posto da esquerda.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define L 5
#define C 8

int main(void) {

    return 0;
}
