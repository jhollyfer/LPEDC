// A086 · A lista de chamada em ordem alfabética

#include <stdio.h>
#include <string.h>

#define ALUNOS 6
#define TAM 20

// troca duas linhas da matriz: string não se atribui com =, então strcpy
void trocar(char a[], char b[]) {
    char aux[TAM];
    strcpy(aux, a);
    strcpy(a, b);
    strcpy(b, aux);
}

// ordenação por seleção: põe o menor que sobrou na posição i
void ordenar(char nomes[][TAM], int n) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(nomes[j], nomes[menor]) < 0) {
                menor = j;
            }
        }
        if (menor != i) {
            trocar(nomes[i], nomes[menor]);
        }
    }
}

int main(void) {
    char nomes[ALUNOS][TAM] = {"Rafael", "Ana", "Carlos", "Beatriz", "Ana Clara", "Bruno"};

    ordenar(nomes, ALUNOS);
    for (int i = 0; i < ALUNOS; i++) {
        printf("%d. %s\n", i + 1, nomes[i]);
    }
    return 0;
}
// Saída:
// 1. Ana
// 2. Ana Clara
// 3. Beatriz
// 4. Bruno
// 5. Carlos
// 6. Rafael
