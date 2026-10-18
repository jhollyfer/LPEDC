// 0031 · A pilha de chamadas
// Exercício E185 · ★★★
//
// Resposta:
// a) dividir (o quadro #0 é o topo).
// b) relatorio chamou media; main chamou relatorio.
// c) media voltaria a rodar primeiro; main seria a última a terminar.
// d) Antes de dividir: media recebeu quantidade 0 e passou adiante sem
//    conferir. dividir só fez a conta que pediram.
// e) Abaixo.

#include <stdio.h>

double dividir(double a, double b) {
    return a / b;
}

double media(double soma, int quantidade) {
    if (quantidade == 0) {
        return 0;
    }
    return dividir(soma, quantidade);
}

void relatorio(int turma, double soma, int quantidade) {
    printf("Turma %d: média %.1f\n", turma, media(soma, quantidade));
}

int main(void) {
    relatorio(3, 27, 3);
    relatorio(3, 27, 0);
    return 0;
}
