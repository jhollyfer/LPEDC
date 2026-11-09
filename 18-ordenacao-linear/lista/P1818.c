// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1818 · ★★☆ · Onde pôr o depósito: a mediana ponderada
//
// Uma rede tem 7 lojas ao longo da Av. Torquato Tapajós, cada uma num km
// (de 0 a 30) e com um número de entregas por dia (o peso). O depósito vai
// num km p, e o custo diário é a soma de peso · |km - p|. O melhor p é a
// MEDIANA PONDERADA (problema 9-2 do Cormen): ordene as lojas pelo km e ande
// somando os pesos; o primeiro km em que a soma chega à metade do peso total
// é a resposta.
//
// Ordene as lojas pelo km com counting sort (os km são inteiros pequenos),
// ache a mediana ponderada e mostre o custo em quatro candidatos: a mediana
// ponderada, a mediana simples dos km (sem pesos), a média ponderada
// arredondada e o melhor km por força bruta (testando de 0 a 30).
//
//   Saída esperada:
//   km  2 Cidade Nova          peso  5, acumulado  5 de 23
//   km  5 Novo Israel          peso  1, acumulado  6 de 23
//   km  7 Lago Azul            peso  2, acumulado  8 de 23
//   km 12 Monte das Oliveiras  peso  1, acumulado  9 de 23
//   km 18 Santa Etelvina       peso  1, acumulado 10 de 23
//   km 21 Colonia              peso  2, acumulado 12 de 23
//   Mediana ponderada: km 21, custo 206
//   Força bruta:       km 21, custo 206
//   Mediana simples:   km 12, custo 245
//   Média ponderada:   km 17, custo 220
//
// Dicas:
// 1. Para comparar com a metade sem usar double, compare 2 · acumulado com o
//    peso total.
// 2. Por que funciona? Andando um km para a direita a partir de p, o custo
//    aumenta (peso à esquerda) e diminui (peso à direita). Enquanto houver
//    mais peso à direita, vale a pena andar.
// 3. A média ponderada minimiza a soma dos QUADRADOS das distâncias, não a
//    soma das distâncias: aqui ela perde.
// 4. Resposta esperada: mediana ponderada no km 21, com custo 206; a força
//    bruta concorda; a mediana simples (km 12) custa 245 e a média (km 17),
//    220.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

#define N 7
#define KM 31

typedef struct {
    const char *nome;
    int km, entregas;
} Loja;

int main(void) {
    Loja v[N] = {{"Taruma", 26, 11}, {"Lago Azul", 7, 2}, {"Santa Etelvina", 18, 1},
                 {"Cidade Nova", 2, 5}, {"Colonia", 21, 2}, {"Monte das Oliveiras", 12, 1},
                 {"Novo Israel", 5, 1}};

    for (int i = 0; i < N; i++) printf("%s km %d\n", v[i].nome, v[i].km);
    return 0;
}
