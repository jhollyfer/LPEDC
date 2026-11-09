// 0166 · O, Ω e Θ de verdade
// Exercício E994 · ★★☆

#include <stdio.h>
#include <math.h>

#define LIMITE 200000

int main(void) {
    // n log n = O(n)? Para cada c, o último n em que n log n <= c n.
    // Depois dele, a desigualdade quebra e não volta mais.
    int cs[] = {2, 4, 8, 16};
    for (int i = 0; i < 4; i++) {
        long ultimo_ok = 0;
        for (long n = 1; n <= LIMITE; n++) {
            if (n * log2((double)n) <= (double)cs[i] * n) {
                ultimo_ok = n;
            }
        }
        printf("c = %2d: falha de n = %ld em diante\n", cs[i], ultimo_ok + 1);
    }
    return 0;
}
