// 0117 · Dijkstra: caminho mínimo
// Exercício E697 · ★☆☆
//
// Um centro de distribuição (CD) entrega em quatro bairros, A, B, C e D. As
// ruas são de mão dupla e os pesos são km:
//
//   CD-A 7, CD-B 2, B-A 3, B-C 8, A-C 1, A-D 6, C-D 2
//
// Sem escrever código, faça o teste de mesa do Dijkstra a partir do CD numa
// tabela como a do texto: uma linha por vértice fixado, mostrando o vetor
// dist depois de relaxar os vizinhos. Diga a distância final de cada bairro e
// o caminho até D.
//
// Dicas:
// 1. Comece com CD = 0 e o resto ∞. Fixar o CD deixa A = 7 e B = 2.
// 2. O próximo a fixar é sempre o de menor dist entre os não fixos: o B.
//    Passando por B, A cai de 7 para 5.
// 3. Resposta esperada: ordem de fixação CD (0), B (2), A (5), C (6), D (8).
//    Finais: A = 5, B = 2, C = 6, D = 8. Caminho até D: CD -> B -> A -> C -> D
//    (2 + 3 + 1 + 2 = 8 km).
//
// Escreva sua resposta abaixo (a tabela, como comentário):

#include <stdio.h>

int main(void) {

    return 0;
}
