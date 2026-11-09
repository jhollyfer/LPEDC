// 0184 · Pontes e articulações
// Exercício E1102 · ★★☆
//
// A distribuidora de energia tem oito subestações: Usina, Norte, Sul,
// Leste, Oeste, Porto, Vila e Serra (0 a 7). As linhas:
//
//   Usina-Norte, Usina-Sul, Norte-Sul, Norte-Leste, Norte-Oeste,
//   Leste-Oeste, Sul-Porto, Porto-Vila, Porto-Serra
//
// Não basta saber quais subestações são articulações: a distribuidora quer
// saber em QUANTOS pedaços a rede parte sem cada uma. Escreva a DFS com tin
// e low (raiz na Usina) que conta isso e mostre só as que partem a rede.
//
//   Saída esperada:
//   Sem Norte, a rede parte em 2 pedaços
//   Sem Sul, a rede parte em 2 pedaços
//   Sem Porto, a rede parte em 3 pedaços
//
// Dicas:
// 1. Num vértice que não é a raiz, cada filho v com low[v] >= tin[u] vira
//    um pedaço; some 1 pelo pedaço de cima, onde está o pai.
// 2. Na raiz, cada filho da árvore é um pedaço (não há pedaço de cima).
// 3. Resposta esperada: a saída acima. A Usina tem um filho só na DFS, e
//    a rede sem ela continua inteira.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
