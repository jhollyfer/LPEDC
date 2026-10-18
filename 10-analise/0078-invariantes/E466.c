// 0078 · Invariantes de laço e corretude
// Exercício E466 · ★★☆
//
// O banco quer saber qual cliente está "menos no vermelho": o maior saldo
// entre contas todas negativas. O programa compila sem aviso, passou em todos
// os testes com saldos positivos, mas aqui mostra 0.
//
//   Saída esperada:
//   Maior saldo: R$ -45
//
// a) Qual dos quatro passos da prova (início, manutenção, término, parada)
// falha? Mostre o momento exato.
// b) Conserte sem tratar "todos negativos" como caso especial.
// c) O que a função deveria exigir de n? Escreva o contrato correto.
//
// Dicas:
// 1. Invariante pretendido: maior é um máximo de v[0..i-1]. Ele vale antes
//    da primeira volta?
// 2. Um máximo de um pedaço tem que ser um elemento desse pedaço.
// 3. Resposta esperada: a) o início: antes da primeira volta (i = 0, pedaço
//    vazio) maior vale 0, e depois de olhar o -120 ele continua 0, que nem
//    está no vetor; o invariante "maior é um elemento máximo" nunca valeu;
//    b) int maior = v[0]; e o laço começa em i = 1; c) "recebe n >= 1 e v;
//    devolve o valor de um elemento máximo de v[0..n-1]".
//
// Escreva sua resposta abaixo (conserte o código):

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
