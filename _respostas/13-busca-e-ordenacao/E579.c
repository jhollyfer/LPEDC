// 0097 · Selection sort
// Exercício E579 · ★★☆

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *alunos[] = {"Rafael", "Ana", "Lucas", "Beatriz", "Diego", "Carla"};
    int n = 6, trocas = 0;

    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(alunos[j], alunos[menor]) < 0) {
                menor = j;
            }
        }
        if (menor != i) {
            const char *aux = alunos[i];   // troca só os ponteiros
            alunos[i] = alunos[menor];
            alunos[menor] = aux;
            trocas++;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, alunos[i]);
    }
    printf("%d trocas de ponteiro\n", trocas);
    return 0;
}
