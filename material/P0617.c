// Lista · Módulo 06 · Ponteiros
// Exercício P0617 · ★★☆ · Conserte o reajuste dos preços
//
// A cantina vai subir R$ 1 em todos os preços. O programa abaixo tem DOIS
// erros de propósito na parte dos ponteiros. O gcc avisa de um (leia o
// warning); o outro, o AddressSanitizer acusa quando roda. Conserte os dois.
// O programa deve mostrar:
//
//   Saída esperada:
//   5 8 4 11 7
//   Total: R$ 35
//
// Dicas:
// 1. *p++ é *(p++): lê o valor e anda o ponteiro. Para somar no valor
//    apontado, use (*p)++ ou *p += 1.
// 2. fim = precos + n aponta para a casa DEPOIS da última: ela pode ser
//    comparada, mas não lida. O laço precisa de p < fim.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

void reajustar(int *precos, int n) {
    int *fim = precos + n;
    for (int *p = precos; p < fim; p++) {
        *p++;
    }
}

int total(const int *precos, int n) {
    int soma = 0;
    const int *fim = precos + n;
    for (const int *p = precos; p <= fim; p++) {
        soma += *p;
    }
    return soma;
}

int main(void) {
    int precos[5] = {4, 7, 3, 10, 6}; // coxinha, suco, café, prato, bolo

    reajustar(precos, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d%s", precos[i], i < 4 ? " " : "\n");
    }
    printf("Total: R$ %d\n", total(precos, 5));
    return 0;
}
