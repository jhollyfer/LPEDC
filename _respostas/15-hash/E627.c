// 0105 · A ideia e a função hash
// Exercício E627 · ★★☆

#include <stdio.h>

#define M 13

unsigned hash_pol(const char *s) {
    unsigned h = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        h = h * 31 + (unsigned char)s[i];
    }
    return h % M;
}

int main(void) {
    const char *meios[] = {"pix", "ted", "doc", "boleto"};
    for (int i = 0; i < 4; i++) {
        printf("%-6s -> %u\n", meios[i], hash_pol(meios[i]));
    }
    return 0;
}
