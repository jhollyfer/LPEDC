// 0173 · Juntando tudo: o controle de acesso
// Exercício E1033 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

#define ENTRAR   (1u << 0) // E
#define REUNIAO  (1u << 1) // R
#define IMPRIMIR (1u << 2) // I
#define GARAGEM  (1u << 3) // G
#define CONFIG   (1u << 4) // C
#define QTD_PERMS 5

void conceder(unsigned *p, unsigned m) {
    *p |= m;
}

void revogar(unsigned *p, unsigned m) {
    *p &= ~m;
}

bool tem(unsigned p, unsigned m) {
    return (p & m) == m;
}

int main(void) {
    unsigned p = ENTRAR;
    printf("inicio: %u\n", p);
    conceder(&p, REUNIAO | IMPRIMIR);
    printf("conceder R|I: %u\n", p);
    revogar(&p, IMPRIMIR);
    printf("revogar I: %u\n", p);
    printf("tem R? %s\n", tem(p, REUNIAO) ? "sim" : "nao");
    printf("tem R|I? %s\n", tem(p, REUNIAO | IMPRIMIR) ? "sim" : "nao");
    return 0;
}
