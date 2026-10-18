// 0131 · Divisão e conquista
// Exercício E782 · ★☆☆
//
// Quanto rendem R$ 1000 aplicados a 1% ao mês durante 30 anos (360 meses)?
// A conta é 1000 · 1,01^360. O programa está pronto, menos o corpo da função
// potencia_d, marcado com "COMPLETE AQUI". Complete com a potência rápida do
// texto, agora para double, somando em mult as multiplicações feitas (1
// quando o expoente é par, 2 quando é ímpar).
//
//   Saída esperada:
//   Depois de 360 meses: R$ 35949.64
//   Multiplicações: 13
//
// Dicas:
// 1. O caso base devolve 1.0. Depois, guarde potencia_d(x, n / 2) numa
//    variável e use duas vezes.
// 2. Os expoentes visitados são 360, 180, 90, 45, 22, 11, 5, 2, 1 e 0.
//    Quatro deles são ímpares.
// 3. Resposta esperada: a saída acima. Um laço simples faria 360
//    multiplicações (e acumularia mais erro de arredondamento do double).
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

static int mult = 0;

// x elevado a n (n >= 0), cortando o expoente ao meio
double potencia_d(double x, int n) {
    // COMPLETE AQUI
    (void)x;
    (void)n;
    return 1.0;
}

int main(void) {
    double inicial = 1000.0; // R$ aplicados
    double taxa = 0.01;      // 1% ao mês
    int meses = 360;         // 30 anos

    double final = inicial * potencia_d(1.0 + taxa, meses);
    printf("Depois de %d meses: R$ %.2f\n", meses, final);
    printf("Multiplicações: %d\n", mult);
    return 0;
}
