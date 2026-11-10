// 0189 · Juntando tudo
// Exercício E1133 · ★★★
//
// Monte o planejador de entregas do fluxograma: a função
// void planeja(const char *nome, const int px[], const int py[], int n)
// calcula as distâncias em quarteirões e decide sozinha:
//
//   - até 12 pontos: Held-Karp, mostra o custo exato;
//   - mais que isso: árvore mínima (Prim a partir do ponto 0) + pré-ordem,
//     depois 2-opt (A378) até nenhuma troca melhorar; mostra o peso da
//     árvore, o custo da rota antes e depois do 2-opt.
//
// Teste com a manhã (os 8 pontos do texto) e a tarde: 30 pontos gerados
// assim, com semente = 7 (unsigned), para i de 0 a 29:
//
//   semente = semente * 1103515245u + 12345u;  x[i] = (int)(semente >> 16) % 25;
//   semente = semente * 1103515245u + 12345u;  y[i] = (int)(semente >> 16) % 25;
//
//   Saída esperada:
//   Manhã (8 pontos): exato, 28 quarteirões
//   Tarde (30 pontos): aproximado, árvore 111, rota 172, com 2-opt 148
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
