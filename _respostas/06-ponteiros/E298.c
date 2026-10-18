// 0050 · Ponteiros
// Exercício E298 · ★★☆

#include <stdio.h>

int main(void) {
    int mala_azul = 19, mala_preta = 26;
    int *pesada = NULL;

    if (mala_azul > mala_preta) {
        pesada = &mala_azul;
    } else {
        pesada = &mala_preta;
    }
    printf("Mais pesada: %d kg\n", *pesada);
    *pesada -= 4;

    printf("Depois de tirar 4 kg: azul %d kg, preta %d kg\n", mala_azul, mala_preta);
    return 0;
}
