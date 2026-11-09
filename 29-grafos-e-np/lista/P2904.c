// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2904 · ★☆☆ · Diagnóstico de Euler por lista de arestas
//
// Três prefeituras mandaram o mapa das ruas como lista de arestas (pode
// haver duas ruas entre as mesmas esquinas). Para cada mapa, diga se o
// caminhão da varrição consegue passar por toda rua uma vez e voltar
// (circuito), passar por toda rua sem voltar (trajeto, dizendo de onde a
// onde) ou nenhum dos dois:
//
//   Mapa 1 (5 esquinas): 0-1, 1-2, 2-0, 2-3, 3-4, 4-2
//   Mapa 2 (5 esquinas): 0-1, 1-2, 2-3, 3-0, 0-2, 1-3, 1-4, 4-3
//   Mapa 3 (6 esquinas): 0-1, 1-2, 2-0, 3-4, 4-5, 5-3
//
// Escreva void diagnostico(int nv, int ne, int a[][2]) e use-a nos três.
//
//   Saída esperada:
//   Mapa 1: circuito
//   Mapa 2: trajeto de 0 a 2
//   Mapa 3: nenhum (desconexo)
//
// Dicas:
// 1. Conte o grau percorrendo a lista: cada aresta soma 1 nas duas pontas.
//    Para a conexidade, uma DFS em matriz montada a partir da lista basta
//    (ignore esquinas de grau 0).
// 2. Conexo e 0 ímpares: circuito. Conexo e 2 ímpares: trajeto entre eles.
//    Desconexo ou outro número de ímpares: nenhum.
// 3. Resposta esperada: a saída acima. O mapa 3 tem todos os graus pares e
//    mesmo assim não tem circuito.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
