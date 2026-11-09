// A346 · O que a equipe inteira tem

#include <stdio.h>

#define ENTRAR   (1u << 0)
#define REUNIAO  (1u << 1)
#define IMPRIMIR (1u << 2)
#define GARAGEM  (1u << 3)
#define CONFIG   (1u << 4)
#define QTD_PERMS 5

void mostrar(const char *titulo, unsigned m) {
    const char nomes[] = "ERIGC";
    for (int b = 0; b < QTD_PERMS; b++) {
        printf("%c", (m & (1u << b)) ? nomes[b] : '-');
    }
    printf("  %s\n", titulo);
}

int main(void) {
    // as permissões efetivas de uma equipe de tamanho variável
    unsigned todas[] = {
        ENTRAR | REUNIAO | IMPRIMIR | GARAGEM,
        ENTRAR | REUNIAO | GARAGEM,
        ENTRAR | REUNIAO,
        ENTRAR | REUNIAO,
        ENTRAR | IMPRIMIR,
    };
    int n = 5;
    unsigned equipe[n]; // VLA: só a equipe deste turno
    for (int i = 0; i < n; i++) {
        equipe[i] = todas[i];
    }

    unsigned alguem = 0;     // começa sem nada: o OU vai acendendo
    unsigned todo_mundo = ~0u; // começa com tudo: o E vai apagando
    for (int i = 0; i < n; i++) {
        alguem |= equipe[i];
        todo_mundo &= equipe[i];
    }
    mostrar("alguém tem", alguem);
    mostrar("todo mundo tem", todo_mundo);
    mostrar("ninguém tem (dos 5 bits)", ~alguem & ((1u << QTD_PERMS) - 1)); // só 5 bits

    // contagem por permissão numa matriz VLA permissão x pessoa
    int perms = QTD_PERMS;
    int tem[perms][n];
    for (int b = 0; b < perms; b++) {
        for (int i = 0; i < n; i++) {
            tem[b][i] = (equipe[i] >> b) & 1u;
        }
    }
    printf("quantos têm cada uma:");
    for (int b = 0; b < perms; b++) {
        int soma = 0;
        for (int i = 0; i < n; i++) {
            soma += tem[b][i];
        }
        printf(" %c=%d", "ERIGC"[b], soma);
    }
    printf("\n");
    return 0;
}
// Saída:
// ERIG-  alguém tem
// E----  todo mundo tem
// ----C  ninguém tem (dos 5 bits)
// quantos têm cada uma: E=5 R=4 I=2 G=2 C=0
