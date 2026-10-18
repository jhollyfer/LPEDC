// 0030 · Escopo e tempo de vida
// Exercício E176 · ★☆☆

#include <stdio.h>

int registrar_visita(void) {
    static int visitas = 0; // criada uma vez, guarda o valor
    visitas++;
    return visitas;
}

int registrar_sem_static(void) {
    int visitas = 0; // nasce com 0 em toda chamada
    visitas++;
    return visitas;
}

int main(void) {
    for (int i = 0; i < 4; i++) {
        printf("Visita nº %d\n", registrar_visita());
    }
    printf("Sem static:");
    for (int i = 0; i < 4; i++) {
        printf(" %d", registrar_sem_static());
    }
    printf("\n");
    return 0;
}
