// 0113 · Juntando tudo: a central de entregas
// Exercício E675 · ★★☆
//
// A prefeitura vai construir um pronto-socorro num dos seis lugares do mapa
// do A225 (sem a Ilha). O critério: o lugar onde a PIOR distância até
// qualquer outro é a menor possível. As estradas, em km (mão dupla):
//
//   CD-Centro 4, CD-Feira 2, Feira-Centro 1, Centro-Porto 7, Feira-Morro 3,
//   Morro-Porto 2, Porto-Vila 3, Centro-Vila 12
//
// Para cada lugar, rode Dijkstra a partir dele, ache a maior distância (e
// até onde é) e escolha o melhor.
//
//   Saída esperada:
//   CD     pior caso: 10 km (até Vila)
//   Centro pior caso:  9 km (até Vila)
//   Feira  pior caso:  8 km (até Vila)
//   Porto  pior caso:  7 km (até CD)
//   Morro  pior caso:  5 km (até CD)
//   Vila   pior caso: 10 km (até CD)
//   Melhor lugar para o hospital: Morro (ninguém a mais de 5 km)
//
// Dicas:
// 1. Ponha o Dijkstra numa função void dijkstra(int origem, int dist[]) e
//    chame uma vez por lugar (índices: CD 0, Centro 1, Feira 2, Porto 3,
//    Morro 4, Vila 5).
// 2. A maior distância a partir de um vértice se chama excentricidade; o
//    vértice de menor excentricidade é o CENTRO do grafo.
// 3. Formato: printf("%-6s pior caso: %2d km (até %s)\n", ...).
// 4. Resposta esperada: a saída acima. Em empate de maior distância, fica o
//    primeiro destino encontrado (o Morro está a 5 km do CD e da Vila).
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
