// A053 · Uma rodada de craps

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    srand(21); // semente fixa: a rodada abaixo se repete (glibc)

    int d1 = 1 + rand() % 6;
    int d2 = 1 + rand() % 6;
    int soma = d1 + d2;
    int lancamentos = 1;
    int ponto = 0;
    int situacao; // 1 = ganhou, -1 = perdeu, 0 = continua

    printf("Lançamento %d: %d + %d = %d\n", lancamentos, d1, d2, soma);
    switch (soma) {
    case 7:
    case 11:
        situacao = 1;          // natural: ganha de cara
        break;
    case 2:
    case 3:
    case 12:
        situacao = -1;         // craps: perde de cara
        break;
    default:
        situacao = 0;          // virou o ponto
        ponto = soma;
        printf("Ponto: %d. Agora precisa repetir o %d antes de um 7.\n", ponto, ponto);
    }

    while (situacao == 0) {
        d1 = 1 + rand() % 6;
        d2 = 1 + rand() % 6;
        soma = d1 + d2;
        lancamentos++;
        printf("Lançamento %d: %d + %d = %d\n", lancamentos, d1, d2, soma);
        if (soma == ponto) {
            situacao = 1;
        } else if (soma == 7) {
            situacao = -1;
        }
    }

    printf("%s em %d lançamentos.\n", situacao == 1 ? "Ganhou" : "Perdeu", lancamentos);
    return 0;
}
// Saída (glibc, Linux):
// Lançamento 1: 3 + 6 = 9
// Ponto: 9. Agora precisa repetir o 9 antes de um 7.
// Lançamento 2: 3 + 5 = 8
// Lançamento 3: 1 + 4 = 5
// Lançamento 4: 4 + 5 = 9
// Ganhou em 4 lançamentos.
