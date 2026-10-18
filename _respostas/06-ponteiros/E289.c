// 0049 · Memória e endereços
// Exercício E289 · ★☆☆

#include <stdio.h>

int main(void) {
    int passageiros = 42;
    float tarifa = 4.40f;
    char setor = 'X';

    printf("passageiros = %d, endereço %p, tamanho %zu\n", passageiros, (void *)&passageiros, sizeof passageiros);
    printf("tarifa = %.2f, endereço %p, tamanho %zu\n", tarifa, (void *)&tarifa, sizeof tarifa);
    printf("setor = %c, endereço %p, tamanho %zu\n", setor, (void *)&setor, sizeof setor);
    return 0;
}
