// 0003 · Tipos e limites
// Exercício E016 · ★★☆

#include <stdio.h>

int main(void) {
    long long fatorial = 479001600; // 12!
    fatorial = fatorial * 13;
    printf("13! = %lld maneiras\n", fatorial);
    return 0;
}
