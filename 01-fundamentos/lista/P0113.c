// Lista · Módulo 01 · Fundamentos de C
// Exercício P0113 · ★★☆ · A média ponderada do concurso
//
// No concurso, a prova objetiva tem peso 2 e a discursiva tem peso 3. Com 6.0 e
// 8.0, a média deveria ser (6.0 × 2 + 8.0 × 3) / 5 = 7.2, mas o programa abaixo
// mostra 16.8. O erro é de precedência e está lá de propósito. Conserte só com
// parênteses:
//
//   Saída esperada:
//   Média final: 7.2
//
// Dicas:
// 1. Em C, * e / são feitos antes de +. Quem está sendo dividido por 5 hoje?
// 2. A soma inteira dos pesos tem que acontecer antes da divisão.
// 3. Resposta esperada: Média final: 7.2.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    double objetiva = 6.0;
    double discursiva = 8.0;

    double media = objetiva * 2 + discursiva * 3 / 5;

    printf("Média final: %.1f\n", media);
    return 0;
}
