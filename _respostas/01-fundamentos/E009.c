// 0002 · Variáveis
// Exercício E009 · ★★☆

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

    printf("total: %zu bytes\n",
           sizeof idade + sizeof teorica + sizeof pratica + sizeof categoria + sizeof aulas);
    printf("com float nas notas: %zu bytes\n",
           sizeof idade + sizeof(float) + sizeof(float) + sizeof categoria + sizeof aulas);
    return 0;
}
