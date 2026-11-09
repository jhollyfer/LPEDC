// Lista · Módulo 03 · Laços
// Exercício P0320 · ★★☆ · A média da turma que dá errado

#include <stdio.h>

int main(void) {
    int soma = 0; // zera uma vez só, antes do laço

    for (int i = 1; i <= 5; i++) {
        int nota = (i == 1) ? 7 : (i == 2) ? 9 : (i == 3) ? 6 : (i == 4) ? 8 : 10;
        soma += nota;
    }
    double media = soma / 5.0; // divisão real

    printf("Soma: %d\n", soma);
    printf("Média: %.1f\n", media);
    return 0;
}
