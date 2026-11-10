// 0045 · Ponteiros
// Exercício E267 · ★★☆

#include <stdio.h>

int main(void) {
    int peso = 0, meta = 78;
    int *peso_ptr = &peso;
    int *meta_ptr = &meta;

    *peso_ptr = 82;

    printf("Peso: %d\n", peso);
    printf("Meta: %d\n", *meta_ptr);
    return 0;
}
