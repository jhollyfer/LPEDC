// 0031 · A pilha de chamadas
// Exercício E185 · ★★★

#include <stdio.h>

double dividir(int a, int b) {
    static int divisoes = 0;
    divisoes++;
    printf("  [divisão %d, pilha: main -> relatorio -> media -> dividir]\n", divisoes);
    return (double)a / b;
}

double media(int soma, int quantidade) {
    if (quantidade == 0) {
        return 0; // a proteção fica aqui, antes de passar o zero adiante
    }
    return dividir(soma, quantidade);
}

void relatorio(int turma, int soma, int quantidade) {
    printf("Turma %d: média %.1f\n", turma, media(soma, quantidade));
}

int main(void) {
    relatorio(3, 27, 3);
    relatorio(3, 27, 0);
    return 0;
}
