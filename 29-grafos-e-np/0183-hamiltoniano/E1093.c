// 0183 · Hamiltoniano
// Exercício E1093 · ★☆☆
//
// Achar um ciclo hamiltoniano é difícil; conferir um é fácil. Escreva a
// função bool eh_ciclo_hamiltoniano(const int rota[], int n), que recebe
// uma rota (sem repetir o primeiro no fim) do mapa das agências do texto e
// responde se ela é um ciclo hamiltoniano: tem os V vértices, nenhum
// repetido, e cada vizinho da rota (inclusive o último com o primeiro) tem
// via. Teste com as quatro rotas do main.
//
//   Saída esperada:
//   Rota 1: válida
//   Rota 2: inválida
//   Rota 3: válida
//   Rota 4: inválida
//
// Dicas:
// 1. Use um vetor bool visto[V] para pegar vértice repetido.
// 2. A volta é o par (rota[n - 1], rota[0]); com (i + 1) % n o laço trata
//    todos os pares de uma vez.
// 3. Resposta esperada: a saída acima. A rota 2 falha na volta (Shopping
//    para Base); a 4 repete o Centro.
//
// Escreva sua resposta abaixo (complete a função):

#include <stdbool.h>
#include <stdio.h>

#define V 6

int via[V][V];

bool eh_ciclo_hamiltoniano(const int rota[], int n) {
    (void)rota, (void)n; // apague esta linha ao escrever a função
    return false;
}

int main(void) {
    int vias[][2] = {{0, 1}, {0, 2}, {0, 4}, {1, 2}, {1, 3}, {2, 3}, {3, 4}, {3, 5}, {4, 5}};
    for (int k = 0; k < 9; k++) via[vias[k][0]][vias[k][1]] = via[vias[k][1]][vias[k][0]] = 1;

    int r1[] = {0, 1, 2, 3, 5, 4};
    int r2[] = {0, 1, 2, 3, 4, 5};
    int r3[] = {0, 2, 1, 3, 5, 4};
    int r4[] = {0, 1, 3, 5, 4, 1};
    printf("Rota 1: %s\n", eh_ciclo_hamiltoniano(r1, 6) ? "válida" : "inválida");
    printf("Rota 2: %s\n", eh_ciclo_hamiltoniano(r2, 6) ? "válida" : "inválida");
    printf("Rota 3: %s\n", eh_ciclo_hamiltoniano(r3, 6) ? "válida" : "inválida");
    printf("Rota 4: %s\n", eh_ciclo_hamiltoniano(r4, 6) ? "válida" : "inválida");
    return 0;
}
