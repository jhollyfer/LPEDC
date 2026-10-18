// A194 · A troca que passa por cima

#include <stdio.h>

typedef struct {
    int nota;
    char nome[8];
} Aluno;

void mostra(const Aluno v[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %d-%s", v[i].nota, v[i].nome);
    }
    printf("\n");
}

// selection sort por nota
void selection_sort(Aluno v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j].nota < v[menor].nota) {
                menor = j;
            }
        }
        if (menor != i) {
            Aluno aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;
        }
    }
}

int main(void) {
    // em ordem alfabética: Ana antes de Bia
    Aluno turma[] = {{7, "Ana"}, {7, "Bia"}, {5, "Caio"}};

    printf("antes: ");
    mostra(turma, 3);
    selection_sort(turma, 3);
    printf("depois:");
    mostra(turma, 3);
    printf("Bia passou na frente de Ana: a ordem dos empatados mudou.\n");
    return 0;
}
// Saída:
// antes:  7-Ana 7-Bia 5-Caio
// depois: 5-Caio 7-Bia 7-Ana
// Bia passou na frente de Ana: a ordem dos empatados mudou.
