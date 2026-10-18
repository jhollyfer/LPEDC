// 0027 · Juntando tudo
// Exercício E158 · ★☆☆

#include <stdio.h>

int main(void) {
    int soma;
    int lancamentos = 1;
    int ponto = 0;
    int situacao; // 1 = ganhou, -1 = perdeu, 0 = continua

    printf("Soma: ");
    if (scanf("%d", &soma) != 1) {
        return 1;
    }
    switch (soma) {
    case 7:
    case 11:
        situacao = 1;
        break;
    case 2:
    case 3:
    case 12:
        situacao = -1;
        break;
    default:
        situacao = 0;
        ponto = soma;
    }

    while (situacao == 0) {
        printf("Soma: ");
        if (scanf("%d", &soma) != 1) {
            return 1;
        }
        lancamentos++;
        if (soma == ponto) {
            situacao = 1;
        } else if (soma == 7) {
            situacao = -1;
        }
    }

    printf("%s no %dº lançamento", situacao == 1 ? "Ganhou" : "Perdeu", lancamentos);
    if (ponto != 0) {
        printf(" (ponto %d)", ponto);
    }
    printf(".\n");
    return 0;
}
