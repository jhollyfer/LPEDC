// 0173 · Juntando tudo: o controle de acesso
// Exercício E1034 · ★☆☆

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

unsigned de_texto(const char *s) {
    unsigned p = 0;
    for (int b = 0; b < QTD_PERMS && s[b] != '\0'; b++) {
        if (s[b] != '-') {
            p |= 1u << b;
        }
    }
    return p;
}

int main(void) {
    char s[QTD_PERMS + 1];
    para_texto(ENTRAR | IMPRIMIR | CONFIG, s);
    printf("%s\n", s);
    printf("ER-G- = %u\n", de_texto("ER-G-"));
    return 0;
}
