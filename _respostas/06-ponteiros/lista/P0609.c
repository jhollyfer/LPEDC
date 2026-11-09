// Lista · Módulo 06 · Ponteiros
// Exercício P0609 · ★☆☆ · Uma função que mostra qualquer coisa

#include <stdio.h>

void mostrar(const char *rotulo, const void *p, char tipo) {
    printf("%-12s ", rotulo);
    switch (tipo) {
    case 'i':
        printf("%d\n", *(const int *) p);
        break;
    case 'd':
        printf("%.2f\n", *(const double *) p);
        break;
    case 'c':
        printf("%c\n", *(const char *) p);
        break;
    case 's':
        printf("%s\n", (const char *) p);
        break;
    default:
        printf("(tipo desconhecido)\n");
    }
}

int main(void) {
    int bomba = 3;
    double litro = 6.29;
    char combustivel = 'G';
    char frentista[] = "Rosinete";

    mostrar("Bomba:", &bomba, 'i');
    mostrar("Litro: R$", &litro, 'd');
    mostrar("Tipo:", &combustivel, 'c');
    mostrar("Frentista:", frentista, 's');
    return 0;
}
