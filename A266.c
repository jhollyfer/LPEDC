// A266 · Fila do cartório: o mais rápido primeiro

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    const char *nome;
    int minutos; // tempo de atendimento
} Pessoa;

int por_duracao(const void *a, const void *b) {
    const Pessoa *x = a;
    const Pessoa *y = b;
    return (x->minutos > y->minutos) - (x->minutos < y->minutos);
}

// soma o tempo que cada pessoa ESPERA antes de ser atendida
int espera_total(const Pessoa fila[], int n) {
    int relogio = 0, total = 0;
    for (int i = 0; i < n; i++) {
        total += relogio;          // a pessoa i esperou até agora
        relogio += fila[i].minutos;
        printf(" %s", fila[i].nome);
    }
    return total;
}

int main(void) {
    Pessoa fila[] = {{"Ana", 12}, {"Bruno", 3}, {"Carla", 8}, {"Davi", 1}, {"Eva", 5}};
    int n = 5;

    printf("Por chegada:");
    int chegada = espera_total(fila, n);
    printf("\n  espera total %d min, média %.1f min\n", chegada, chegada / (double)n);

    // guloso: atender sempre o serviço mais curto que está na fila.
    // Quem é atendido primeiro faz TODOS os outros esperarem; por isso o
    // primeiro deve ser o mais curto.
    qsort(fila, n, sizeof fila[0], por_duracao);
    printf("Mais curto primeiro:");
    int curto = espera_total(fila, n);
    printf("\n  espera total %d min, média %.1f min\n", curto, curto / (double)n);
    return 0;
}
// Saída:
// Por chegada: Ana Bruno Carla Davi Eva
//   espera total 74 min, média 14.8 min
// Mais curto primeiro: Davi Bruno Eva Carla Ana
//   espera total 31 min, média 6.2 min
