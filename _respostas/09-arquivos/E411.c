// 0069 · Argumentos da linha de comando
// Exercício E411 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    int quantidade = 0;
    double soma = 0.0, maior = 0.0, menor = 0.0;

    for (int i = 1; i < argc; i++) {
        char *fim;
        double nota = strtod(argv[i], &fim);
        bool valida = fim != argv[i] && *fim == '\0' && nota >= 0 && nota <= 10;
        if (!valida) {
            fprintf(stderr, "Ignorando \"%s\"\n", argv[i]);
            continue;
        }
        if (quantidade == 0 || nota > maior) {
            maior = nota;
        }
        if (quantidade == 0 || nota < menor) {
            menor = nota;
        }
        soma += nota;
        quantidade++;
    }

    if (quantidade == 0) {
        printf("Nenhuma nota válida\n");
        return 1;
    }
    printf("Notas: %d\n", quantidade);
    printf("Média: %.2f\n", soma / quantidade);
    printf("Maior: %.2f\n", maior);
    printf("Menor: %.2f\n", menor);
    return 0;
}
