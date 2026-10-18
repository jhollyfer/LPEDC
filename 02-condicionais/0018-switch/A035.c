// A035 · Faixas de nota com a divisão inteira

#include <stdio.h>

// O switch só compara com valores exatos. Para usar faixas, transforme a
// faixa num número: 87 / 10 dá 8 na divisão inteira.
int main(void) {
    int nota = 87; // de 0 a 100
    char conceito;

    switch (nota / 10) {
    case 10: // 100 também é A
    case 9:
        conceito = 'A';
        break;
    case 8:
        conceito = 'B';
        break;
    case 7:
        conceito = 'C';
        break;
    default: // de 0 a 69
        conceito = 'D';
    }
    printf("Nota %d: conceito %c\n", nota, conceito);

    // char também é número: dá para fazer switch numa letra
    switch (conceito) {
    case 'A':
    case 'B':
        printf("Parabéns!\n");
        break;
    case 'C':
        printf("Passou raspando.\n");
        break;
    default:
        printf("Vai para a recuperação.\n");
    }
    return 0;
}
// Saída:
// Nota 87: conceito B
// Parabéns!
