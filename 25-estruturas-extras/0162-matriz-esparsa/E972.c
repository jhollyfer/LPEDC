// 0162 · Matriz esparsa
// Exercício E972 · ★★★
//
// A matriz voos (6 x 6) tem 1 em [i][j] quando existe voo direto da cidade i
// para a cidade j. Elevar ao quadrado responde outra pergunta: voos²[i][j]
// é o número de rotas de i para j com EXATAMENTE uma escala (soma, para cada
// cidade k, de voos[i][k] x voos[k][j]). Escreva multiplica(a, b), que
// devolve a × b como uma nova Esparsa, visitando só as células que existem.
// Depois mostre a matriz e, para cada cidade, quantas rotas com uma escala
// saem dela.
//
//   Saída esperada:
//     0  0  2  1  1  0
//     0  0  1  0  2  0
//     0  0  0  1  0  1
//     0  0  0  1  1  1
//     0  0  1  0  2  0
//     0  0  0  1  0  1
//   Manaus: 4 rotas com uma escala
//   Belém: 3 rotas com uma escala
//   Recife: 2 rotas com uma escala
//   Brasília: 3 rotas com uma escala
//   São Paulo: 3 rotas com uma escala
//   Porto Alegre: 2 rotas com uma escala
//
// Dicas:
// 1. Para a linha i do resultado: para cada célula (k, x) da linha i de a,
//    percorra a linha k de b; cada célula (j, y) soma x * y em acum[j], um
//    vetor de inteiros (com b->colunas posições) zerado a cada linha i.
// 2. Depois de processar a linha i, grave em c as posições de acum que não
//    são zero, com esp_define(c, i, j, acum[j]) em ordem de j (cada célula
//    entra no fim da linha). O total de rotas de i é a soma de acum.
// 3. Resposta esperada: a saída acima. Em Manaus, as 2 rotas para Recife
//    são Manaus-Belém-Recife e Manaus-Brasília-Recife. Ida e volta também
//    conta: o 2 na diagonal de São Paulo vem de São Paulo-Brasília-São
//    Paulo e São Paulo-Porto Alegre-São Paulo.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include "esparsa.h"

int main(void) {
    const char *cidade[] = {"Manaus", "Belém", "Recife", "Brasília", "São Paulo", "Porto Alegre"};
    int voo[][2] = {{0, 1}, {0, 3}, {1, 2}, {1, 3}, {2, 4}, {3, 2},
                    {3, 4}, {4, 3}, {4, 5}, {5, 4}};
    Esparsa *voos = esp_cria(6, 6);
    for (int k = 0; k < 10; k++) {
        esp_define(voos, voo[k][0], voo[k][1], 1);
    }
    (void)cidade; // apague esta linha

    esp_libera(voos);
    return 0;
}
