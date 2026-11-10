// 0110 · BFS: busca em largura
// Exercício E655 · ★☆☆
//
// O mapa liga seis bairros por linhas de ônibus diretas (grafo não dirigido):
// Centro (0), Lapa (1), Moema (2), Penha (3), Saude (4) e Tatuape (5). As
// linhas são Centro-Lapa, Centro-Moema, Lapa-Penha, Moema-Penha, Moema-Saude,
// Penha-Tatuape e Saude-Tatuape. Escreva uma BFS a partir da Penha que mostra,
// numa linha, a ordem da visita com a distância de cada bairro e, depois, uma
// linha por bairro (em ordem de índice) dizendo quem o descobriu (vetor pai[]).
//
//   Saída esperada:
//   Penha(0) Lapa(1) Moema(1) Tatuape(1) Centro(2) Saude(2)
//   Centro: descoberto por Lapa
//   Lapa: descoberto por Penha
//   Moema: descoberto por Penha
//   Penha: origem
//   Saude: descoberto por Moema
//   Tatuape: descoberto por Penha
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define V 6

int main(void) {

    return 0;
}
