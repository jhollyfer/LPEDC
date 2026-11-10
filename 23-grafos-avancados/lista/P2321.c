// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2321 · ★★★ · A segunda melhor rede
//
// Cinco aldeias vão ser ligadas por rádio-internet (custo em R$ mil, mão
// dupla). A árvore mínima é a primeira escolha, mas o órgão de controle
// exige um plano B: a SEGUNDA MELHOR árvore geradora, a mais barata que
// seja diferente da mínima. As ligações possíveis:
//
//   Aldeia Nova-Boa Esperança 4, Aldeia Nova-Cajual 6,
//   Boa Esperança-Cajual 5, Boa Esperança-Daracuí 3, Cajual-Daracuí 7,
//   Cajual-Extrema 8, Daracuí-Extrema 9
//
// Para grafo pequeno há um jeito direto: a segunda melhor árvore difere
// da mínima em UMA aresta. Então, para cada aresta da árvore mínima, rode
// o Kruskal de novo proibindo só ela e fique com o menor total. Escreva o
// programa do zero: mostre a árvore mínima, o total de cada tentativa e a
// troca que dá a segunda melhor (a primeira tentativa com o menor total).
//
//   Saída esperada:
//   Árvore mínima: 20
//     Boa Esperança-Daracuí (3)
//     Aldeia Nova-Boa Esperança (4)
//     Boa Esperança-Cajual (5)
//     Cajual-Extrema (8)
//   sem Boa Esperança-Daracuí (3): 24
//   sem Aldeia Nova-Boa Esperança (4): 22
//   sem Boa Esperança-Cajual (5): 21
//   sem Cajual-Extrema (8): 21
//   Segunda melhor: 21, trocando Boa Esperança-Cajual (5) por Aldeia Nova-Cajual (6)
//
// Dicas:
// 1. Ordene a lista uma vez só. Escreva kruskal(proibida, usada[]), que
//    pula o índice proibido e marca em usada[] as arestas escolhidas.
// 2. A aresta que entrou é a que está na árvore nova e não estava na
//    mínima. Se uma tentativa não ligar todo mundo, devolva -1 e ignore.
// 3. Resposta esperada: mínima 20; segunda melhor 21, trocando
//    Boa Esperança-Cajual (5) por Aldeia Nova-Cajual (6). Tirar
//    Cajual-Extrema também dá 21: o plano B nem sempre é único.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
