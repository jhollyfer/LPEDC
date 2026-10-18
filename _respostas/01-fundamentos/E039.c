// 0007 · Variáveis
// Exercício E039 · ★★☆
//
// Resposta: juntas, as cinco variáveis guardam 4 + 8 + 8 + 1 + 4 = 25 bytes
// de dados. Com float nas notas seriam 4 + 4 + 4 + 1 + 4 = 17 bytes: 8 a
// menos.

#include <stdio.h>

int main(void) {
    int idade = 19;
    double teorica = 8.5;
    double pratica = 9.0;
    char categoria = 'B';
    int aulas = 20;

    printf("idade: %d (%zu bytes)\n", idade, sizeof idade);
    printf("teorica: %.1f (%zu bytes)\n", teorica, sizeof teorica);
    printf("pratica: %.1f (%zu bytes)\n", pratica, sizeof pratica);
    printf("categoria: %c (%zu byte)\n", categoria, sizeof categoria);
    printf("aulas: %d (%zu bytes)\n", aulas, sizeof aulas);
    return 0;
}
