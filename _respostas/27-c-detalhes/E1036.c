// 0173 · Juntando tudo: o controle de acesso
// Exercício E1036 · ★★☆

#include <stdio.h>

#define ENTRAR   (1u << 0) // E
#define REUNIAO  (1u << 1) // R
#define IMPRIMIR (1u << 2) // I
#define GARAGEM  (1u << 3) // G
#define CONFIG   (1u << 4) // C
#define QTD_PERMS 5

void para_texto(unsigned p, char s[QTD_PERMS + 1]) {
    const char letras[] = "ERIGC";
    for (int b = 0; b < QTD_PERMS; b++) {
        s[b] = (p & (1u << b)) ? letras[b] : '-';
    }
    s[QTD_PERMS] = '\0';
}

unsigned usado(int n, int d, unsigned uso[n][d], int i) {
    unsigned m = 0;
    for (int j = 0; j < d; j++) {
        m |= uso[i][j];
    }
    return m;
}

const char *nomes[] = {"Ana", "Bruno", "Carla"};
unsigned efetivas[] = {
    ENTRAR | REUNIAO | IMPRIMIR | GARAGEM | CONFIG,
    ENTRAR | REUNIAO | IMPRIMIR | GARAGEM,
    ENTRAR | REUNIAO,
};
unsigned uso[3][4] = {
    {ENTRAR, ENTRAR | REUNIAO, ENTRAR | CONFIG, ENTRAR},
    {ENTRAR | GARAGEM, ENTRAR | GARAGEM | IMPRIMIR, ENTRAR | GARAGEM, ENTRAR | REUNIAO},
    {ENTRAR, ENTRAR, ENTRAR, ENTRAR},
};
int main(void) {
    for (int i = 0; i < 3; i++) {
        unsigned u = usado(3, 4, uso, i);
        char s_usou[QTD_PERMS + 1], s_nunca[QTD_PERMS + 1];
        para_texto(u, s_usou);
        para_texto(efetivas[i] & ~u, s_nunca);
        printf("%s: usou %s, nunca usou %s\n", nomes[i], s_usou, s_nunca);
    }
    return 0;
}
