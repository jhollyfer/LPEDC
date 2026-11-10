// 0173 · Juntando tudo: o controle de acesso
// Exercício E1036 · ★★☆
//
// O coworking quer descobrir permissões que ninguém usa. A matriz uso guarda,
// para cada pessoa (linha) e cada dia (coluna), a máscara dos recursos que
// ela usou. Escreva, com a matriz como parâmetro VLA:
//
//   unsigned usado(int n, int d, unsigned uso[n][d], int i)
//
// que junta (com |) tudo o que a pessoa i usou nos d dias. Depois mostre,
// para cada pessoa, o que usou e o que tem mas nunca usou (as efetivas
// estão no vetor efetivas), no formato E R I G C com '-'.
//
//   Saída esperada:
//   Ana: usou ER--C, nunca usou --IG-
//   Bruno: usou ERIG-, nunca usou -----
//   Carla: usou E----, nunca usou -R---
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

#define ENTRAR   (1u << 0) // E
#define REUNIAO  (1u << 1) // R
#define IMPRIMIR (1u << 2) // I
#define GARAGEM  (1u << 3) // G
#define CONFIG   (1u << 4) // C
#define QTD_PERMS 5

int main(void) {
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
    (void)nomes; (void)efetivas; (void)uso; // apague esta linha
    return 0;
}
