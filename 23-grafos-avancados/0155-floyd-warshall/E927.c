// 0155 · Floyd-Warshall: todos os pares
// Exercício E927 · ★★☆
//
// A prefeitura vai construir um posto de saúde num dos seis bairros (índices 0
// a 5: Vila Rica, Jardim, Centro, Lagoa, Bosque e Porto). O morador que fica
// mais longe do posto deve ficar o mais perto possível. As ruas são de mão
// dupla (km):
//
//   Vila Rica-Jardim 4, Jardim-Centro 3, Centro-Lagoa 5, Lagoa-Bosque 2,
//   Centro-Bosque 6, Bosque-Porto 7, Jardim-Lagoa 9, Vila Rica-Porto 20
//
// Rode o Floyd-Warshall e, para cada bairro, mostre qual bairro fica mais longe
// dele e a que distância (o primeiro com a maior, em ordem de índice). No fim,
// mostre o bairro em que essa pior distância é a menor.
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
// Escreva sua resposta abaixo:

#include <stdio.h>

#define INFINITO 1000000000

int main(void) {

    return 0;
}
