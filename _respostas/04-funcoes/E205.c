// 0035 · Escopo e tempo de vida
// Exercício E205 · ★☆☆
//
// Resposta: 10, 25, 40, 25, 10. mostrar só enxerga a global (10). No main, o
// volume local (25) esconde a global; dentro do bloco, o 40 esconde o 25 até o
// "}".

#include <stdio.h>

int volume = 10;

void mostrar(void) {
    printf("%d\n", volume);
}

int main(void) {
    mostrar();
    int volume = 25;
    printf("%d\n", volume);
    {
        int volume = 40;
        printf("%d\n", volume);
    }
    printf("%d\n", volume);
    mostrar();
    return 0;
}
