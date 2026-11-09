// Lista · Módulo 08 · Tipos compostos
// Exercício P0830 · ★★★ · A fila da triagem

#include <stdio.h>
#include <stdbool.h>

typedef enum { VERDE, AMARELO, LARANJA, VERMELHO } Cor;

typedef struct {
    char nome[16];
    Cor cor;
    int chegada;
} Paciente;

const char *nome_cor[4] = {"verde", "amarelo", "laranja", "vermelho"};

bool antes(const Paciente *a, const Paciente *b) {
    if (a->cor != b->cor) {
        return a->cor > b->cor; // mais grave primeiro
    }
    return a->chegada < b->chegada;
}

bool entrar(Paciente *fila, int *n, int cap, Paciente p) {
    if (*n == cap) {
        return false;
    }
    int i = *n - 1;
    while (i >= 0 && antes(&p, &fila[i])) {
        fila[i + 1] = fila[i]; // copia a struct inteira
        i--;
    }
    fila[i + 1] = p;
    (*n)++;
    return true;
}

Paciente atender(Paciente *fila, int *n) {
    Paciente primeiro = fila[0];
    for (int i = 1; i < *n; i++) {
        fila[i - 1] = fila[i];
    }
    (*n)--;
    return primeiro;
}

void mostrar(const Paciente *fila, int n) {
    printf("  fila:");
    for (int i = 0; i < n; i++) {
        printf(" %s(%s)", fila[i].nome, nome_cor[fila[i].cor]);
    }
    printf("%s\n", n == 0 ? " vazia" : "");
}

int main(void) {
    Paciente fila[10];
    int n = 0;
    Paciente chegadas[5] = {{"Josué", VERDE, 0}, {"Ana", AMARELO, 2}, {"Rui", VERDE, 3},
                            {"Lia", VERMELHO, 7}, {"Téo", AMARELO, 8}};
    // 'c' = chega o próximo da lista; 'a' = atende
    const char *eventos = "cccaccaa";
    int prox = 0;

    for (const char *e = eventos; *e != '\0'; e++) {
        if (*e == 'c') {
            Paciente p = chegadas[prox++];
            entrar(fila, &n, 10, p);
            printf("Chega %s (%s, min %d)\n", p.nome, nome_cor[p.cor], p.chegada);
        } else {
            Paciente p = atender(fila, &n);
            printf("Atende %s\n", p.nome);
        }
        mostrar(fila, n);
    }
    return 0;
}
