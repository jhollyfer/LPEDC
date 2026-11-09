// Lista · Módulo 13 · Busca e ordenação
// Exercício P1315 · ★★☆ · Quem ordena sem bagunçar os empates

#include <stdio.h>

typedef struct {
    char nome[10];
    int turma;
} Aluno;

void mostra(const char *rotulo, const Aluno v[], int n) {
    printf("%s:", rotulo);
    for (int i = 0; i < n; i++) {
        printf(" %s(%d)", v[i].nome, v[i].turma);
    }
    printf("\n");
}

void selection(Aluno v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j].turma < v[menor].turma) {
                menor = j;
            }
        }
        Aluno t = v[i];
        v[i] = v[menor];
        v[menor] = t;
    }
}

void insertion(Aluno v[], int n) {
    for (int j = 1; j < n; j++) {
        Aluno x = v[j];
        int i = j - 1;
        while (i >= 0 && v[i].turma > x.turma) {
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = x;
    }
}

int main(void) {
    // em ordem alfabética
    Aluno lista[] = {{"Ana", 2}, {"Beto", 1}, {"Caio", 2}, {"Duda", 1}, {"Eva", 3}, {"Fabio", 2}};
    int n = 6;
    Aluno a[6], b[6];
    for (int i = 0; i < n; i++) {
        a[i] = b[i] = lista[i];
    }

    selection(a, n);
    insertion(b, n);
    mostra("selection", a, n);
    mostra("insertion", b, n);
    return 0;
}
