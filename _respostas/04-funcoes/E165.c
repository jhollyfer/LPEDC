// 0028 · Funções
// Exercício E165 · ★★☆

#include <stdbool.h>
#include <stdio.h>

bool eh_bissexto(int ano);

int main(void) {
    int quantos = 0;

    for (int ano = 2000; ano <= 2030; ano++) {
        if (eh_bissexto(ano)) {
            printf(quantos == 0 ? "%d" : " %d", ano);
            quantos++;
        }
    }
    printf("\nBissextos: %d\n", quantos);
    return 0;
}

bool eh_bissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0;
}
