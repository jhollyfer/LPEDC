// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2004 · ★☆☆ · O caixa da feira com poucas moedas
//
// A barraca de tapioca tem no caixa só 2 notas de R$ 10, 3 de R$ 5, 4
// moedas de R$ 2 e 5 de R$ 1. O guloso do troco continua valendo (sempre a
// maior que cabe), mas agora ele precisa respeitar o estoque: uma nota só
// sai se ainda há dela. Complete troco(valor), que mostra o que sai, tira
// do estoque e devolve 1 se conseguiu pagar tudo (0 se faltou). Dê, nesta
// ordem, os trocos de R$ 27, R$ 18 e R$ 9.
//
//   Saída esperada:
//   Troco de R$ 27: 10 10 5 2
//   Troco de R$ 18: 5 5 2 2 2 1 1
//   Troco de R$ 9: 1 1 1
//     faltou troco!
//   Sobrou no caixa: 0 de 10, 0 de 5, 0 de 2, 0 de 1
//
// Dicas:
// 1. Para cada valor de nota, do maior para o menor: enquanto a nota cabe
//    no que falta E estoque[i] > 0, entregue uma.
// 2. O estoque é global: o troco de 27 gasta notas que o de 18 não terá.
// 3. Resposta esperada: 27 = 10 + 10 + 5 + 2; 18 = 5 + 5 + 2 + 2 + 2 + 1 +
//    1; o de 9 falha, porque sobram só 3 moedas de R$ 1.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

#define T 4

const int nota[T] = {10, 5, 2, 1};
int estoque[T] = {2, 3, 4, 5};

int troco(int valor) {
    printf("Troco de R$ %d:", valor);
    // COMPLETE AQUI
    printf("\n");
    return 0;
}

int main(void) {
    const int pedidos[3] = {27, 18, 9};
    for (int k = 0; k < 3; k++) {
        if (!troco(pedidos[k])) {
            printf("  faltou troco!\n");
        }
    }
    printf("Sobrou no caixa: %d de 10, %d de 5, %d de 2, %d de 1\n",
           estoque[0], estoque[1], estoque[2], estoque[3]);
    return 0;
}
