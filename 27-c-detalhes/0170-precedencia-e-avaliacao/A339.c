// A339 · O lado direito que nem roda

#include <stdbool.h>
#include <stdio.h>

int consultas = 0; // quantas vezes o "banco" foi consultado

bool tem_saldo(int saldo, int valor) {
    consultas++;
    printf("  (consultou o saldo)\n");
    return saldo >= valor;
}

int main(void) {
    // && e ||: o lado esquerdo vai primeiro, e o direito só roda se precisar
    bool conta_ativa = false;
    printf("Pix de R$ 80 numa conta bloqueada:\n");
    if (conta_ativa && tem_saldo(200, 80)) {
        printf("  enviado\n");
    } else {
        printf("  recusado\n");
    }

    conta_ativa = true;
    printf("Pix de R$ 80 numa conta ativa:\n");
    if (conta_ativa && tem_saldo(200, 80)) {
        printf("  enviado\n");
    }
    printf("consultas ao saldo: %d\n", consultas);

    // ?: encadeado agrupa da direita: a ? x : (b ? y : z)
    int distancias[] = {3, 12, 40};
    for (int i = 0; i < 3; i++) {
        int km = distancias[i];
        int frete = km <= 5 ? 8 : km <= 15 ? 14 : 25;
        printf("%2d km -> frete R$ %d\n", km, frete);
    }

    // a vírgula: avalia a esquerda, descarta, e o valor é o da direita
    int fila[] = {1, 2, 3, 4, 5};
    for (int i = 0, j = 4; i < j; i++, j--) { // duas variáveis andando juntas
        int t = fila[i];
        fila[i] = fila[j];
        fila[j] = t;
    }
    printf("fila invertida:");
    for (int i = 0; i < 5; i++) {
        printf(" %d", fila[i]);
    }
    printf("\n");
    return 0;
}
// Saída:
// Pix de R$ 80 numa conta bloqueada:
//   recusado
// Pix de R$ 80 numa conta ativa:
//   (consultou o saldo)
//   enviado
// consultas ao saldo: 1
//  3 km -> frete R$ 8
// 12 km -> frete R$ 14
// 40 km -> frete R$ 25
// fila invertida: 5 4 3 2 1
