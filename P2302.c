// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2302 · ★☆☆ · O cano que fecha o circuito
//
// Na vila, os canos de água (mão dupla) ligam o Poço e cinco casas
// (índices 0 a 5: Poço, Ana, Beto, Cida, Davi, Elza):
//
//   Poço-Ana, Ana-Beto, Beto-Cida, Cida-Davi, Ana-Davi, Davi-Elza
//
// Num grafo NÃO dirigido não precisa de três cores: basta lembrar o pai de
// cada vértice na DFS. Um vizinho já visitado que não é o pai fecha um
// circuito. Escreva o programa do zero: mostre o cano que fecha o circuito
// e o circuito inteiro, subindo de pai em pai. Depois a vila tira o cano
// Ana-Davi; analise de novo. Examine os vizinhos em ordem de índice.
//
//   Saída esperada:
//   Rede atual: o cano Davi-Ana fecha o circuito Ana - Beto - Cida - Davi - Ana
//   Rede nova: sem circuito
//
// Dicas:
// 1. dfs(u) marca u e, para cada vizinho v: se não foi visto, pai[v] = u e
//    desce; se foi visto e v != pai[u], achou (guarde ini = v e fim = u).
// 2. Para mostrar o circuito, suba de fim até ini por pai[] guardando num
//    vetor e mostre ao contrário, terminando de novo em ini.
// 3. Resposta esperada: o cano Davi-Ana fecha Ana - Beto - Cida - Davi -
//    Ana; sem o cano Ana-Davi, a rede vira árvore e não tem circuito.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
