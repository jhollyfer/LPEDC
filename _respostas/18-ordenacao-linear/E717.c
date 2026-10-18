// 0120 · Counting sort
// Exercício E717 · ★★☆

#include <stdio.h>
#include <string.h>

#define CORES 5

typedef struct {
    char nome[12];
    char cor[10];
} Paciente;

const char *ordem_cores[CORES] = {"vermelho", "laranja", "amarelo", "verde", "azul"};

// a chave é a posição da cor na lista de gravidade
int chave(const Paciente *p) {
    for (int x = 0; x < CORES; x++) {
        if (strcmp(p->cor, ordem_cores[x]) == 0) {
            return x;
        }
    }
    return CORES - 1; // cor desconhecida vai para o fim
}

void ordena_triagem(const Paciente v[], Paciente saida[], int n) {
    int c[CORES] = {0};
    for (int i = 0; i < n; i++) {
        c[chave(&v[i])]++;
    }
    for (int x = 1; x < CORES; x++) {
        c[x] += c[x - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        int x = chave(&v[i]);
        c[x]--;
        saida[c[x]] = v[i];
    }
}

int main(void) {
    Paciente chegada[] = {
        {"Joana", "amarelo"}, {"Pedro", "verde"}, {"Rita", "vermelho"}, {"Caio", "amarelo"},
        {"Lia", "azul"}, {"Davi", "laranja"}, {"Nina", "verde"}, {"Otto", "vermelho"},
        {"Sara", "amarelo"}, {"Ivo", "laranja"},
    };
    Paciente fila[10];
    int n = 10;

    ordena_triagem(chegada, fila, n);
    for (int i = 0; i < n; i++) {
        printf("%2d. %-5s (%s)\n", i + 1, fila[i].nome, fila[i].cor);
    }
    return 0;
}
