// 0054 · Ponteiro para ponteiro
// Exercício E319 · ★☆☆

#include <stdio.h>

int main(void) {
    char turma = 'k';
    char *p = &turma;
    char **pp = &p;

    printf("%c %c %c\n", turma, *p, **pp);
    **pp = 'K';
    printf("Agora: %c\n", turma);
    return 0;
}
