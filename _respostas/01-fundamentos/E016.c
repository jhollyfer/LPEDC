// 0003 · Tipos e limites
// Exercício E016 · ★★☆
//
// Resposta: 13! = 6227020800 não cabe num int (máximo 2147483647). Estourar
// um tipo com sinal é comportamento indefinido, e o detector do rodar acusa
// "signed integer overflow". Sem ele, o programa mostraria 1932053504, um
// número errado. Com long long (8 bytes) cabe com folga.

#include <stdio.h>

int main(void) {
    long long fatorial = 479001600; // 12!
    fatorial = fatorial * 13;
    printf("13! = %lld maneiras\n", fatorial);
    return 0;
}
