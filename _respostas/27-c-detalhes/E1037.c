// 0173 · Juntando tudo: o controle de acesso
// Exercício E1037 · ★★★

#include <stdio.h>

typedef enum { VISITANTE, MEMBRO, ADMIN, QTD_PAPEIS } Papel;

#define ENTRAR   (1u << 0) // E
#define REUNIAO  (1u << 1) // R
#define IMPRIMIR (1u << 2) // I
#define GARAGEM  (1u << 3) // G
#define CONFIG   (1u << 4) // C
#define QTD_PERMS 5

const unsigned base[QTD_PAPEIS] = {
    ENTRAR,
    ENTRAR | REUNIAO | IMPRIMIR,
    ENTRAR | REUNIAO | IMPRIMIR | GARAGEM | CONFIG,
};

void para_texto(unsigned p, char s[QTD_PERMS + 1]) {
    const char letras[] = "ERIGC";
    for (int b = 0; b < QTD_PERMS; b++) {
        s[b] = (p & (1u << b)) ? letras[b] : '-';
    }
    s[QTD_PERMS] = '\0';
}

int menor_papel(unsigned pedido) {
    for (int p = 0; p < QTD_PAPEIS; p++) {
        if ((base[p] & pedido) == pedido) {
            return p;
        }
    }
    return -1;
}

int main(void) {
    const char *papeis[QTD_PAPEIS] = {"visitante", "membro", "admin"};
    unsigned pedidos[] = {ENTRAR, REUNIAO | IMPRIMIR, GARAGEM, 1u << 5};
    for (int i = 0; i < 4; i++) {
        char s_pedido[QTD_PERMS + 1], s_falta[QTD_PERMS + 1];
        para_texto(pedidos[i], s_pedido);
        para_texto(pedidos[i] & ~base[VISITANTE], s_falta);
        int p = menor_papel(pedidos[i]);
        printf("pedido %s: %s (falta ao visitante: %s)\n", s_pedido, p >= 0 ? papeis[p] : "nenhum", s_falta);
    }
    return 0;
}
