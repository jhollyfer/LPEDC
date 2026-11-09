// A345 · Auditoria: quem fugiu do pacote do papel

#include <stdio.h>

typedef enum { VISITANTE, MEMBRO, ADMIN, QTD_PAPEIS } Papel;

#define ENTRAR   (1u << 0)
#define REUNIAO  (1u << 1)
#define IMPRIMIR (1u << 2)
#define GARAGEM  (1u << 3)
#define CONFIG   (1u << 4)
#define QTD_PERMS 5

typedef struct {
    char nome[16];
    Papel papel;
    unsigned extra;
    unsigned bloqueio;
} Usuario;

const unsigned base[QTD_PAPEIS] = {
    ENTRAR,
    ENTRAR | REUNIAO | IMPRIMIR,
    ENTRAR | REUNIAO | IMPRIMIR | GARAGEM | CONFIG,
};

unsigned efetivas(const Usuario *u) {
    return (base[u->papel] | u->extra) & ~u->bloqueio;
}

// escreve as letras dos bits ligados, ou "nada"
void letras(unsigned m, char saida[QTD_PERMS + 1]) {
    const char nomes[] = "ERIGC";
    int k = 0;
    for (int b = 0; b < QTD_PERMS; b++) {
        if (m & (1u << b)) {
            saida[k++] = nomes[b];
        }
    }
    saida[k] = '\0';
}

int contar_bits(unsigned m) {
    int n = 0;
    while (m != 0) {
        m &= m - 1; // apaga o bit 1 mais baixo
        n++;
    }
    return n;
}

int main(void) {
    Usuario equipe[] = {
        {"Ana", ADMIN, 0, 0},
        {"Bruno", MEMBRO, GARAGEM, 0},
        {"Carla", MEMBRO, 0, IMPRIMIR},
        {"Davi", VISITANTE, REUNIAO, ENTRAR | CONFIG}, // bloqueio de algo que nem tinha
    };
    for (int i = 0; i < 4; i++) {
        unsigned b = base[equipe[i].papel];
        unsigned e = efetivas(&equipe[i]);
        unsigned diferentes = b ^ e;     // XOR: 1 onde o papel e o real discordam
        unsigned ganhou = e & ~b;        // tem, mas o papel não dava
        unsigned perdeu = b & ~e;        // o papel dava, mas não tem
        char g[QTD_PERMS + 1], p[QTD_PERMS + 1];
        letras(ganhou, g);
        letras(perdeu, p);
        printf("%-6s %d diferença(s)  ganhou: %-3s perdeu: %s\n", equipe[i].nome,
               contar_bits(diferentes), g[0] ? g : "-", p[0] ? p : "-");
    }
    return 0;
}
// Saída:
// Ana    0 diferença(s)  ganhou: -   perdeu: -
// Bruno  1 diferença(s)  ganhou: G   perdeu: -
// Carla  1 diferença(s)  ganhou: -   perdeu: I
// Davi   2 diferença(s)  ganhou: R   perdeu: E
