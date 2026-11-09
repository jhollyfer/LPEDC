// Lista · Módulo 16 · Grafos
// Exercício P1611 · ★★☆ · Menos conexões até Porto Alegre
//
// Você sai de Manaus e quer chegar a outra capital com o MENOR número de
// voos. A companhia voa nos dois sentidos nos trechos da matriz do esqueleto
// (não dirigido). Oiapoque está no cadastro, mas a companhia não voa para lá.
//
// Rode uma BFS a partir de Manaus guardando pi[] e escreva, SEM recursão:
//
//   int caminho(const int pi[], int s, int t, int rota[]);
//
// Ela devolve o número de voos de s até t e preenche rota[] com as cidades na
// ordem da viagem, de s até t; se t não foi alcançado, devolve -1. Mostre a
// rota para Porto Alegre, Fortaleza e Oiapoque.
//
//   Saída esperada:
//   Porto Alegre: Manaus -> Brasilia -> Recife -> Rio -> Porto Alegre (4 voos, d = 4)
//   Fortaleza: Manaus -> Belem -> Fortaleza (2 voos, d = 2)
//   Oiapoque: sem rota
//
// Dicas:
// 1. Andar por pi[] a partir de t dá o caminho DE TRÁS PARA FRENTE: guarde
//    t, pi[t], pi[pi[t]], ... até chegar em s, e depois inverta o vetor.
// 2. Se t != s e pi[t] == -1, t não foi descoberto: devolva -1.
// 3. O número de voos é o número de cidades na rota menos 1, e tem de bater
//    com d[t] da BFS.
// 4. Resposta esperada: Porto Alegre em 4 voos (Manaus, Brasilia, Recife,
//    Rio, Porto Alegre), Fortaleza em 2 e Oiapoque sem rota.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define V 10

const char *nomes[V] = {"Manaus", "Belem", "Brasilia", "Fortaleza", "Recife",
                        "Rio", "Sao Paulo", "Curitiba", "Porto Alegre", "Oiapoque"};
int adj[V][V];

int main(void) {
    int trechos[][2] = {{0, 1}, {0, 2}, {1, 3}, {2, 4}, {2, 6}, {3, 4},
                        {4, 5}, {5, 6}, {6, 7}, {7, 8}, {5, 8}};
    for (int k = 0; k < 11; k++) adj[trechos[k][0]][trechos[k][1]] = adj[trechos[k][1]][trechos[k][0]] = 1;

    return 0;
}
