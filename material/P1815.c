// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1815 · ★★☆ · Bucket sort fora de [0, 1): as temperaturas de Manaus
//
// O bucket sort do Cormen supõe valores em [0, 1). As máximas diárias de
// Manaus num mês vão de uns 23 °C a uns 38 °C. Para usar baldes, NORMALIZE:
// com mín e máx do vetor, o valor x vai para o balde
//
//   b = (int)((x - mín) / (máx - mín) * n)
//
// e o máximo (que daria b = n) vai para o balde n - 1. Ordene as 12
// temperaturas do esqueleto com n baldes (listas encadeadas em ordem, com
// malloc), mostre os baldes não vazios e o vetor ordenado.
//
//   Saída esperada:
//   balde  0: 22.9
//   balde  3: 27.3
//   balde  5: 29.5
//   balde  6: 30.7 31.2
//   balde  7: 32.4
//   balde  8: 33.8 34.1
//   balde  9: 35.0
//   balde 10: 36.4
//   balde 11: 37.6 38.1
//   ordenado: 22.9 27.3 29.5 30.7 31.2 32.4 33.8 34.1 35.0 36.4 37.6 38.1
//
// Dicas:
// 1. Ache mín e máx numa passada (Θ(n)) antes de distribuir.
// 2. Sem o ajuste do máximo, ele cairia no balde n, fora do vetor: o
//    AddressSanitizer acusa na hora.
// 3. Se todos os valores forem iguais, máx - mín = 0: trate esse caso (todo
//    mundo no balde 0) antes de dividir.
// 4. Resposta esperada: 12 baldes, o 0 com 22.9 e o 11 com 37.6 e 38.1; o
//    vetor ordenado vai de 22.9 a 38.1.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

#define N 12

typedef struct No {
    double x;
    struct No *prox;
} No;

int main(void) {
    double temp[N] = {31.2, 33.8, 29.5, 36.4, 22.9, 34.1, 38.1, 30.7, 27.3, 35.0, 37.6, 32.4};

    for (int i = 0; i < N; i++) printf("%.1f ", temp[i]);
    printf("\n");
    return 0;
}
