// A137 · Rachar a conta pela linha de comando

#include <stdio.h>
#include <stdlib.h>

// Rode assim:  ~/LPEDC/rodar 09-arquivos/0069-argumentos/A137.c 187.40 4
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <total> <pessoas>\n", argv[0]);
        return 1; // diferente de 0: deu errado
    }

    char *fim;
    double total = strtod(argv[1], &fim); // texto -> double
    if (*fim != '\0' || total <= 0) {
        fprintf(stderr, "Total inválido: %s\n", argv[1]);
        return 1;
    }
    long pessoas = strtol(argv[2], &fim, 10); // texto -> inteiro, base 10
    if (*fim != '\0' || pessoas <= 0) {
        fprintf(stderr, "Número de pessoas inválido: %s\n", argv[2]);
        return 1;
    }

    printf("Conta: R$ %.2f\n", total);
    printf("Pessoas: %ld\n", pessoas);
    printf("Cada um: R$ %.2f\n", total / pessoas);
    return 0;
}
// $ rodar A137.c 187.40 4
// Conta: R$ 187.40
// Pessoas: 4
// Cada um: R$ 46.85
//
// $ rodar A137.c 187.40 quatro
// Número de pessoas inválido: quatro
//
// $ rodar A137.c
// Uso: /tmp/lpedc/A137 <total> <pessoas>
