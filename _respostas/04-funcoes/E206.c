// 0035 · Escopo e tempo de vida
// Exercício E206 · ★☆☆
//
// Sem o static, visitas nasce com 0 em toda chamada e a saída vira
// "Visita nº 1" quatro vezes.

#include <stdio.h>

int registrar_visita(void) {
    static int visitas = 0;
    visitas++;
    return visitas;
}

int main(void) {
    for (int i = 0; i < 4; i++) {
        printf("Visita nº %d\n", registrar_visita());
    }
    return 0;
}
