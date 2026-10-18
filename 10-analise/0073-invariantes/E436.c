// 0073 · Invariantes de laço e corretude
// Exercício E436 · ★★☆
//
// O banco quer saber qual cliente está "menos no vermelho": o maior saldo
// entre contas todas negativas. O programa compila sem aviso, passou em todos
// os testes com saldos positivos, mas aqui mostra 0.
//
// 1. Conserte maximo() sem tratar "todos negativos" como caso especial, e
// escreva em cima dela o contrato certo (o que ela exige de n).
// 2. Escreva bool eh_maximo(v, i, x) (x está em v[0..i-1] e ninguém passa
// dele) e confira o invariante com assert no começo de cada volta.
// 3. Acrescente ao main um teste com um saldo só (-7) e um com saldos
// positivos (10, 3, 25), e rode.
//
//   Saída esperada:
//   Maior saldo: R$ -45
//   Um saldo só: R$ -7
//   Positivos: R$ 25
//
// Dicas:
// 1. Invariante pretendido: maior é um máximo de v[0..i-1]. Com maior = 0,
//    ele já é falso antes da primeira volta: 0 nem está no vetor. Ponha o
//    assert no código quebrado e veja ele disparar.
// 2. Um máximo de um pedaço tem que ser um elemento desse pedaço.
// 3. Resposta esperada: int maior = v[0]; e o laço começa em i = 1.
//    Contrato: "recebe n >= 1 e v; devolve o valor de um elemento máximo de
//    v[0..n-1]".
//
// Escreva sua resposta abaixo (conserte o código):

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

int maximo(const int v[], int n) {
    int maior = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > maior) {
            maior = v[i];
        }
    }
    return maior;
}

int main(void) {
    int saldos[4] = {-120, -45, -300, -80};

    printf("Maior saldo: R$ %d\n", maximo(saldos, 4));
    return 0;
}
