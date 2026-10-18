// 0013 · Conversão e cast
// Exercício E078 · ★★★
//
// Resposta: "A 65" ('a' é 97; 97 - 32 = 65); 25 (122 - 97); 4 (260 dá a
// volta: 260 - 256); 4.0 (5 / 2 é 2, e 2 * 2.0 = 4.0); 5.0 (2.0 * 5 = 10.0,
// e 10.0 / 2 = 5.0); 7 (3.7 + 3.7 = 7.4, cortado); 6 (3 + 3).

#include <stdio.h>

int main(void) {
    char c = 'a';
    printf("%c %d\n", c - 32, c - 32);
    printf("%d\n", 'z' - 'a');
    unsigned char u = 250;
    u = u + 10;
    printf("%d\n", u);
    printf("%.1f\n", 5 / 2 * 2.0);
    printf("%.1f\n", 2.0 * 5 / 2);
    int i = 3.7 + 3.7;
    printf("%d\n", i);
    printf("%d\n", (int) 3.7 + (int) 3.7);
    return 0;
}
