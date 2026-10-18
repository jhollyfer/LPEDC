// 0008 · Tipos e limites
// Exercício E046 · ★★☆
//
// De quantas maneiras 13 corredores podem cruzar a linha de chegada? É
// 13! (13 fatorial = 1 * 2 * ... * 13). O programa abaixo parte de 12! e
// multiplica por 13. Ele compila sem aviso, mas está errado: rode e leia a
// mensagem "runtime error" que aparece. Explique o problema e conserte.
//
//   Saída esperada (depois de consertar):
//   13! = 6227020800 maneiras
//
// Dicas:
// 1. Quanto vale INT_MAX? E 6227020800?
// 2. O detector de comportamento indefinido do rodar pegou um estouro de
//    int, que é um tipo com sinal.
// 3. Resposta esperada: 13! não cabe em int (máximo 2147483647): "signed
//    integer overflow". Sem o detector, o programa mostraria um número
//    errado (1932053504). Conserto: long long fatorial e %lld (ou int64_t).
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int fatorial = 479001600; // 12!
    fatorial = fatorial * 13;
    printf("13! = %d maneiras\n", fatorial);
    return 0;
}
