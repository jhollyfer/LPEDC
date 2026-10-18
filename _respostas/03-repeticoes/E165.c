// 0028 · Break e continue
// Exercício E165 · ★★☆

#include <stdio.h>

int main(void) {
    const int limite = 600;
    int total = 0;
    int entraram = 0;
    int peso;

    for (int pessoa = 1; pessoa <= 8; pessoa++) {
        printf("Peso da pessoa %d: ", pessoa);
        if (scanf("%d", &peso) != 1) {
            break;
        }
        if (total + peso > limite) {
            printf("A pessoa %d (%d kg) espera o próximo.\n", pessoa, peso);
            break;
        }
        total = total + peso;
        entraram++;
    }
    printf("Entraram %d pessoas, %d kg.\n", entraram, total);
    return 0;
}
