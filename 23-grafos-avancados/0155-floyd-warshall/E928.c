// 0155 · Floyd-Warshall: todos os pares
// Exercício E928 · ★★☆
//
// Uma casa de câmbio cobra uma taxa fixa (em centavos) por conversão entre
// Real, Dólar, Euro e Cripto. Numa semana de promoção, a conversão Cripto ->
// Dólar dá um bônus maior (taxa -40 em vez de -10). A função analisa já
// monta a matriz de uma semana. Complete-a: rode o Floyd-Warshall e,
// olhando a diagonal, diga se existe um ciclo negativo (trocar em roda e
// sair ganhando) e por quais moedas ele passa.
//
//   Saída esperada:
//   Semana 1: sem ciclo negativo
//   Semana 2: ciclo negativo passando por Dólar Euro Cripto
//
// Escreva sua resposta abaixo (complete analisa):

#include <stdio.h>

#define V 4
#define INFINITO 1000000000

const char *moedas[V] = {"Real", "Dólar", "Euro", "Cripto"};

void analisa(const char *semana, int custo[][3], int n) {
    int d[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) d[i][j] = (i == j) ? 0 : INFINITO;
    for (int e = 0; e < n; e++) d[custo[e][0]][custo[e][1]] = custo[e][2];

    (void)d; // apague esta linha
    printf("%s: ?\n", semana); // troque por: Floyd-Warshall + análise da diagonal
}

int main(void) {
    int semana1[][3] = {{0, 1, 30}, {1, 2, 20}, {2, 0, 25}, {0, 3, 50},
                        {3, 1, -10}, {1, 0, 35}, {2, 3, 15}};
    int semana2[][3] = {{0, 1, 30}, {1, 2, 20}, {2, 0, 25}, {0, 3, 50},
                        {3, 1, -40}, {1, 0, 35}, {2, 3, 15}};
    analisa("Semana 1", semana1, 7);
    analisa("Semana 2", semana2, 7);
    return 0;
}
