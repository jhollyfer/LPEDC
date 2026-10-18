// 0105 · A ideia e a função hash
// Exercício E626 · ★☆☆

#include <stdio.h>

#define M 5

// soma dos códigos, sem o resto
unsigned soma(const char *s) {
    unsigned total = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        total += (unsigned char)s[i];
    }
    return total;
}

unsigned h(const char *s) {
    return soma(s) % M;
}

int main(void) {
    const char *p[] = {"sol", "los", "Sol", "lua"};
    for (int i = 0; i < 4; i++) {
        printf("%s=%u\n", p[i], h(p[i]));
    }

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (h(p[i]) == h(p[j])) {
                printf("%s e %s colidem (somas %u e %u)\n", p[i], p[j], soma(p[i]), soma(p[j]));
            }
        }
    }
    return 0;
}
