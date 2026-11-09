// Lista · Módulo 01 · Fundamentos de C
// Exercício P0106 · ★☆☆ · Ônibus da excursão

#include <stdio.h>

int main(void) {
    int alunos = 158;
    int lugares = 44;

    int lotados = alunos / lugares;
    int sobra = alunos % lugares;
    int onibus = (alunos + lugares - 1) / lugares; // divisão para cima

    printf("Ônibus lotados: %d\n", lotados);
    printf("Alunos no último: %d\n", sobra);
    printf("Ônibus para alugar: %d\n", onibus);
    return 0;
}
