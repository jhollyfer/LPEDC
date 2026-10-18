// 0050 · Ponteiro para função
// Exercício E299 · ★★★
//
// Este programa ordena os saldos de uma corretora (em centavos) e tem um
// bug de propósito na função de comparação. Ele compila sem aviso, mas o
// rodar acusa um erro quando roda, e a ordem pode sair errada. Rode, leia a
// mensagem "runtime error" e conserte a função compara. Rode de novo: a
// mensagem tem que sumir e a ordem tem que ficar certa.
//
//   Saída esperada:
//   -2000000000 5 2000000000
//
// Dicas:
// 1. Quanto dá 2000000000 - (-2000000000)? Cabe num int (assunto 0003)?
// 2. A comparação só precisa devolver o SINAL certo, não a diferença.
// 3. Resposta esperada: "-2000000000 5 2000000000", sem runtime error. A
//    subtração estoura o int (signed integer
//    overflow): o resultado "dá a volta" e fica negativo, dizendo que
//    2000000000 vem antes de -2000000000. Conserto:
//    return (x > y) - (x < y);
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

int compara(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return x - y;
}

int main(void) {
    int saldos[3] = {2000000000, -2000000000, 5};

    qsort(saldos, 3, sizeof saldos[0], compara);
    for (int i = 0; i < 3; i++) {
        printf("%d ", saldos[i]);
    }
    printf("\n");
    return 0;
}
