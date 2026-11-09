// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1926 · ★★★ · O roteiro turístico de Manaus
//
// Um guia quer um roteiro a pé que passe por 6 pontos de Manaus, cada um
// UMA vez, saindo do Teatro Amazonas. Só há ligação direta entre alguns
// pares (a matriz liga[][] do programa). Um caminho que visita todos os
// vértices uma vez só é um CAMINHO HAMILTONIANO, e não se conhece jeito
// rápido de achá-lo: backtracking é o caminho. Escreva roteiro(v, k), que
// já está em v depois de visitar k pontos, e liste todos os roteiros, o
// total e quantos terminam num ponto ligado ao Teatro (dá para voltar a pé:
// um CICLO hamiltoniano).
//
//   Saída esperada:
//   Teatro > Mercado > Palácio > MUSA > Ponta Negra > Encontro
//   Teatro > Mercado > Palácio > MUSA > Encontro > Ponta Negra
//   Teatro > Mercado > Palácio > Ponta Negra > MUSA > Encontro
//   Teatro > Mercado > Palácio > Ponta Negra > Encontro > MUSA (fecha)
//   Teatro > Mercado > Encontro > MUSA > Palácio > Ponta Negra
//   Teatro > Mercado > Encontro > MUSA > Ponta Negra > Palácio (fecha)
//   Teatro > Mercado > Encontro > Ponta Negra > Palácio > MUSA (fecha)
//   Teatro > Mercado > Encontro > Ponta Negra > MUSA > Palácio (fecha)
//   Teatro > Palácio > Mercado > Encontro > MUSA > Ponta Negra
//   Teatro > Palácio > Mercado > Encontro > Ponta Negra > MUSA (fecha)
//   Teatro > Palácio > MUSA > Ponta Negra > Encontro > Mercado (fecha)
//   Teatro > Palácio > Ponta Negra > MUSA > Encontro > Mercado (fecha)
//   Teatro > MUSA > Palácio > Mercado > Encontro > Ponta Negra
//   Teatro > MUSA > Palácio > Ponta Negra > Encontro > Mercado (fecha)
//   Teatro > MUSA > Ponta Negra > Palácio > Mercado > Encontro
//   Teatro > MUSA > Ponta Negra > Encontro > Mercado > Palácio (fecha)
//   Teatro > MUSA > Encontro > Mercado > Palácio > Ponta Negra
//   Teatro > MUSA > Encontro > Ponta Negra > Palácio > Mercado (fecha)
//   Roteiros: 18, ciclos: 10
//
// Dicas:
// 1. Guarde o roteiro em rota[] e marque os visitados. Com k == N, mostre;
//    se liga[v][0], conte como ciclo.
// 2. Para cada w com liga[v][w] e não visitado: marque, rota[k] = w, chame
//    roteiro(w, k + 1), desmarque.
// 3. Resposta esperada: 18 roteiros, 10 deles fecham um ciclo.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdbool.h>
#include <stdio.h>

#define N 6

const char *ponto[N] = {"Teatro", "Mercado", "Palácio", "MUSA", "Ponta Negra", "Encontro"};
const int liga[N][N] = {
    // Te Me Pa MU PN En
    {0, 1, 1, 1, 0, 0}, // Teatro
    {1, 0, 1, 0, 0, 1}, // Mercado
    {1, 1, 0, 1, 1, 0}, // Palácio
    {1, 0, 1, 0, 1, 1}, // MUSA
    {0, 0, 1, 1, 0, 1}, // Ponta Negra
    {0, 1, 0, 1, 1, 0}, // Encontro
};
bool visitado[N];
int rota[N];
int roteiros = 0, ciclos = 0;

void roteiro(int v, int k) {
    (void)v;
    (void)k;
    // COMPLETE AQUI
}

int main(void) {
    visitado[0] = true;
    rota[0] = 0;
    roteiro(0, 1);
    printf("Roteiros: %d, ciclos: %d\n", roteiros, ciclos);
    return 0;
}
