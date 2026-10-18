// 0114 · Grafos
// Exercício E681 · ★★☆
//
// O bairro tem quatro esquinas, A (0), B (1), C (2) e D (3). A prefeitura
// mandou a lista de ruas como um vetor de struct, uma entrada por SENTIDO
// permitido: {0, 1} quer dizer que dá para ir de A para B. Uma rua de mão
// dupla aparece duas vezes ({0, 1} e {1, 0}).
//
// O esqueleto já traz os dados. Complete o programa: monte a matriz de
// adjacência DIRIGIDA a partir do vetor e, para cada par de esquinas ligadas,
// diga se a rua é de mão dupla ou de mão única (e em que sentido). No fim,
// mostre quantas há de cada tipo.
//
//   Saída esperada:
//   Sentidos cadastrados: 7
//   A-B: mão dupla
//   A-C: mão dupla
//   A-D: mão única (D -> A)
//   B-C: mão única (B -> C)
//   C-D: mão única (C -> D)
//   Mão única: 3, mão dupla: 2
//
// Dicas:
// 1. Para cada struct do vetor, adj[r.de][r.para] = 1 (só nesse sentido).
// 2. Olhe cada par uma vez só: i de 0 a 3 e j de i + 1 a 3. Se
//    adj[i][j] e adj[j][i] valem 1, é mão dupla; se só um vale 1, mão única.
// 3. A letra da esquina i é 'A' + i (char é número, assunto 0045).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

typedef struct {
    int de;
    int para;
} Rua;

int main(void) {
    Rua ruas[] = {{0, 1}, {1, 0}, {1, 2}, {2, 3}, {3, 0}, {0, 2}, {2, 0}};
    int total = (int)(sizeof ruas / sizeof ruas[0]);
    printf("Sentidos cadastrados: %d\n", total);

    return 0;
}
