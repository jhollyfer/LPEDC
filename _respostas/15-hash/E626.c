// 0105 · A ideia e a função hash
// Exercício E626 · ★☆☆
//
// Resposta: sol=4, los=4, Sol=2, lua=2.
// "sol" e "los" colidem porque são anagramas: a soma (115 + 111 + 108 = 334)
// não depende da ordem das letras. "Sol" (83 + 111 + 108 = 302) e "lua"
// (108 + 117 + 97 = 322) colidem por acaso: 302 % 5 = 322 % 5 = 2.

#include <stdio.h>

#define M 5

unsigned h(const char *s) {
    unsigned soma = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        soma += (unsigned char)s[i];
    }
    return soma % M;
}

int main(void) {
    const char *p[] = {"sol", "los", "Sol", "lua"};
    for (int i = 0; i < 4; i++) {
        printf("%s=%u\n", p[i], h(p[i]));
    }
    return 0;
}
