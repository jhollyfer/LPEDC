// 0027 · Juntando tudo
// Exercício E158 · ★☆☆
//
// Um juiz de craps sem dados: em vez de sortear, o programa lê a soma de cada
// lançamento do teclado. O começo (o primeiro lançamento e o switch, igual ao
// do texto, com scanf no lugar do sorteio) já está pronto no arquivo. Complete o while dos relançamentos: ele lê a próxima soma,
// conta o lançamento e decide (o ponto ganha, o 7 perde, o resto não faz
// nada). Depois teste com as seis sequências:
//
//   printf '5\n8\n4\n6\n5\n' | ~/LPEDC/rodar 03-repeticoes/0027-juntando-tudo/E158.c
//
//   a) 5, 8, 4, 6, 5
//   b) 6, 9, 7
//   c) 12
//   d) 11
//   e) 4, 4
//   f) 10, 2, 3, 12, 7
//
//   Saída esperada para a sequência a:
//   Soma: Soma: Soma: Soma: Soma: Ganhou no 5º lançamento (ponto 5).
//
// Dicas:
// 1. O while repete enquanto situacao == 0. Dentro: printf("Soma: "), scanf
//    (se falhar, return 1), lancamentos++ e um if/else if.
// 2. Do segundo lançamento em diante, só duas somas importam: o ponto
//    (situacao = 1) e o 7 (situacao = -1). 2, 3 e 12 não fazem mais nada.
// 3. Resposta esperada: a) ganha no 5º (ponto 5); b) perde no 3º (ponto 6);
//    c) perde no 1º; d) ganha no 1º; e) ganha no 2º (ponto 4); f) perde no
//    5º (ponto 10; o 2, o 3 e o 12 depois do ponto não contam).
//
// Escreva sua resposta abaixo (complete o código):

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

    // escreva aqui o while dos relançamentos

    printf("%s no %dº lançamento", situacao == 1 ? "Ganhou" : "Perdeu", lancamentos);
    if (ponto != 0) {
        printf(" (ponto %d)", ponto);
    }
    printf(".\n");
    return 0;
}
