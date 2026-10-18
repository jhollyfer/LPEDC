// 0155 · Floyd-Warshall: todos os pares
// Exercício E927 · ★★☆
//
// A prefeitura vai construir um posto de saúde num dos seis bairros. O
// critério: o morador que fica mais longe do posto deve ficar o mais perto
// possível. As ruas são de mão dupla (km):
//
//   Vila Rica-Jardim 4, Jardim-Centro 3, Centro-Lagoa 5, Lagoa-Bosque 2,
//   Centro-Bosque 6, Bosque-Porto 7, Jardim-Lagoa 9, Vila Rica-Porto 20
//
// Escreva o programa: rode o Floyd-Warshall e, para cada bairro, mostre
// qual bairro fica mais longe dele e a que distância (a primeira maior, em
// ordem de índice). No fim, mostre o bairro em que essa pior distância é a
// menor.
//
//   Saída esperada:
//   Vila Rica: o mais longe é Porto, a 20 km
//   Jardim: o mais longe é Porto, a 16 km
//   Centro: o mais longe é Porto, a 13 km
//   Lagoa: o mais longe é Vila Rica, a 12 km
//   Bosque: o mais longe é Vila Rica, a 13 km
//   Porto: o mais longe é Vila Rica, a 20 km
//   Melhor bairro para o posto: Lagoa (ninguém fica a mais de 12 km)
//
// Dicas:
// 1. Mão dupla: grave d[a][b] e d[b][a]. Depois do Floyd-Warshall, a linha
//    i da matriz tem a distância de i a todos.
// 2. O máximo da linha i é a "excentricidade" de i. O bairro com a menor
//    excentricidade é o CENTRO do grafo (que aqui nem é o bairro Centro).
// 3. Resposta esperada: a saída acima. De Lagoa: Vila Rica a 12 (Lagoa,
//    Centro, Jardim, Vila Rica) e Porto a 9 (Lagoa, Bosque, Porto).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define V 6
#define INFINITO 1000000000

int main(void) {
    const char *bairros[V] = {"Vila Rica", "Jardim", "Centro", "Lagoa", "Bosque", "Porto"};
    int ruas[][3] = {{0, 1, 4}, {1, 2, 3}, {2, 3, 5}, {3, 4, 2},
                     {2, 4, 6}, {4, 5, 7}, {1, 3, 9}, {0, 5, 20}};
    (void)bairros; // apague estas duas linhas
    (void)ruas;

    return 0;
}
