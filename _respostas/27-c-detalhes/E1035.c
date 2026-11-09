// 0173 · Juntando tudo: o controle de acesso
// Exercício E1035 · ★★☆

#include <stdbool.h>
#include <stdio.h>

#define ENTRAR   (1u << 0) // E
#define REUNIAO  (1u << 1) // R
#define IMPRIMIR (1u << 2) // I
#define GARAGEM  (1u << 3) // G
#define CONFIG   (1u << 4) // C
#define QTD_PERMS 5

unsigned revogar(unsigned p, unsigned m) {
    return p & ~m; // E com o inverso apaga; OU com o inverso acendia o resto
}

bool tem_todas(unsigned p, unsigned m) {
    return (p & m) == m; // sobraram TODOS os bits de m
}

int main(void) {
    unsigned p = ENTRAR | REUNIAO | IMPRIMIR;
    p = revogar(p, IMPRIMIR);
    printf("depois de revogar: %u\n", p);
    printf("tem R e I? %s\n", tem_todas(p, REUNIAO | IMPRIMIR) ? "sim" : "nao");
    printf("tem E e R? %s\n", tem_todas(p, ENTRAR | REUNIAO) ? "sim" : "nao");
    return 0;
}
