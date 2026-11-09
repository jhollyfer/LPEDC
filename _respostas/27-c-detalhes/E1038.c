// 0173 · Juntando tudo: o controle de acesso
// Exercício E1038 · ★★★

#include <stdio.h>

#define ENTRAR   (1u << 0) // E
#define REUNIAO  (1u << 1) // R
#define IMPRIMIR (1u << 2) // I
#define GARAGEM  (1u << 3) // G
#define CONFIG   (1u << 4) // C
#define QTD_PERMS 5

typedef struct {
    char nome[16];
    unsigned concede;
    unsigned nega;
} Grupo;

void para_texto(unsigned p, char s[QTD_PERMS + 1]) {
    const char letras[] = "ERIGC";
    for (int b = 0; b < QTD_PERMS; b++) {
        s[b] = (p & (1u << b)) ? letras[b] : '-';
    }
    s[QTD_PERMS] = '\0';
}

unsigned calcular(int k, const int ids[k], const Grupo grupos[]) {
    unsigned concede = 0, nega = 0;
    for (int i = 0; i < k; i++) {
        concede |= grupos[ids[i]].concede;
        nega |= grupos[ids[i]].nega;
    }
    return concede & ~nega; // a negação vence, qualquer que seja a ordem
}

int main(void) {
    Grupo grupos[] = {
        {"equipe", ENTRAR | REUNIAO, 0},
        {"financeiro", IMPRIMIR, 0},
        {"estagio", 0, GARAGEM | CONFIG},
        {"motorista", GARAGEM, 0},
    };
    int k = 3;
    int ids_lia[k];
    ids_lia[0] = 0; // equipe
    ids_lia[1] = 1; // financeiro
    ids_lia[2] = 3; // motorista
    int ids_teo[k];
    ids_teo[0] = 0; // equipe
    ids_teo[1] = 3; // motorista
    ids_teo[2] = 2; // estagio

    char s[QTD_PERMS + 1];
    para_texto(calcular(k, ids_lia, grupos), s);
    printf("Lia: %s\n", s);
    para_texto(calcular(k, ids_teo, grupos), s);
    printf("Teo: %s\n", s);
    return 0;
}
