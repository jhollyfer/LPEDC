// Lista · Módulo 21 · Programação dinâmica
// Exercício P2116 · ★★☆ · Corte de haste com custo de corte
//
// A serralheria vende barras de alumínio por comprimento, e cada CORTE
// custa R$ 3 de mão de obra (o Cormen propõe essa variação no exercício
// 15.1-3). Os preços:
//
//   m     1   2   3   4   5   6   7   8
//   R$    2   6   9  12  15  18  20  22
//
// O programa abaixo é o corte de haste sem custo de corte, para uma barra
// de 8 m. Estenda-o: some o custo de R$ 3 a cada corte (vender a barra
// inteira não tem corte) e mostre, para as duas versões, o valor máximo e
// os pedaços.
//
//   Saída esperada:
//   Custo por corte R$ 0: R$ 24, pedaços: 2 6
//   Custo por corte R$ 3: R$ 22, pedaços: 8
//
// Dicas:
// 1. melhor[j] = max(preco[j], max sobre i < j de preco[i] + melhor[j - i]
//    - CUSTO). O pedaço inteiro entra sem custo; cada vez que você separa
//    uma primeira fatia i < j, há um corte.
// 2. Guarde corte[j] = j quando vender inteiro é o melhor.
// 3. Resposta esperada: sem custo, R$ 24 com pedaços de 2 m e 6 m (quatro
//    de 2 m empatam); com R$ 3 por corte, o melhor é vender a barra inteira
//    por R$ 22.
//
// Escreva sua resposta abaixo (estenda o código):

#include <stdio.h>

#define TAM 8

const int preco[TAM + 1] = {0, 2, 6, 9, 12, 15, 18, 20, 22};

void resolve(void) {
    int melhor[TAM + 1], corte[TAM + 1];
    melhor[0] = 0;
    for (int j = 1; j <= TAM; j++) {
        melhor[j] = 0;
        for (int i = 1; i <= j; i++) {
            if (preco[i] + melhor[j - i] > melhor[j]) {
                melhor[j] = preco[i] + melhor[j - i];
                corte[j] = i;
            }
        }
    }
    printf("Sem custo de corte: R$ %d, pedaços:", melhor[TAM]);
    for (int j = TAM; j > 0; j -= corte[j]) {
        printf(" %d", corte[j]);
    }
    printf("\n");
}

int main(void) {
    resolve();
    return 0;
}
