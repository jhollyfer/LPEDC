// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2609 · ★☆☆ · Dobrou n, multiplicou por oito
//
// A função trios_de_cores testa toda combinação (i, j, k) de n tintas, com
// três laços de 0 a n - 1. Acrescente um contador de passos, rode com
// n = 10, 20, 40 e 80 e mostre a razão entre cada contagem e a anterior:
//
//   Saída esperada:
//   n = 10:   1000 passos
//   n = 20:   8000 passos, razão 8.0
//   n = 40:  64000 passos, razão 8.0
//   n = 80: 512000 passos, razão 8.0
//
// Dicas:
// 1. São n³ passos. Dobrar n multiplica por 2³ = 8: a assinatura de Θ(n³).
// 2. Na primeira linha não há razão anterior; mostre só a contagem.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (mude o programa):

#include <stdio.h>

void trios_de_cores(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                // testa a mistura das tintas i, j e k
            }
        }
    }
}

int main(void) {
    trios_de_cores(10);
    printf("misturas testadas\n");
    return 0;
}
