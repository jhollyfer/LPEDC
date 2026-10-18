// 0066 · Vetor de structs
// Exercício E393 · ★★☆

#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[40];
    double altura;
    int idade;
} Atleta;

#define N 3

int main(void) {
    Atleta v[N];

    for (int i = 0; i < N; i++) {
        printf("Nome: ");
        if (fgets(v[i].nome, sizeof v[i].nome, stdin) == NULL) {
            return 1;
        }
        v[i].nome[strcspn(v[i].nome, "\n")] = '\0';

        printf("Altura e idade: ");
        if (scanf("%lf %d", &v[i].altura, &v[i].idade) != 2) {
            printf("Entrada inválida\n");
            return 1;
        }
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
            // descarta o resto da linha
        }
    }
    printf("\n");

    int alto = 0, velho = 0;
    for (int i = 1; i < N; i++) {
        if (v[i].altura > v[alto].altura) alto = i;
        if (v[i].idade > v[velho].idade) velho = i;
    }
    printf("Mais alto: %s (%.2f m)\n", v[alto].nome, v[alto].altura);
    printf("Mais velho: %s (%d anos)\n", v[velho].nome, v[velho].idade);
    return 0;
}
