// 0068 · Enum
// Exercício E407 · ★★★

#include <stdio.h>

typedef enum { TRAVADA, LIBERADA } Estado;
typedef enum { BILHETE, EMPURRAO } Evento;

int passaram = 0, barrados = 0, desperdicados = 0;

Estado transicao(Estado e, Evento ev) {
    switch (e) {
    case TRAVADA:
        if (ev == BILHETE) {
            return LIBERADA;
        }
        barrados++;
        return TRAVADA;
    case LIBERADA:
        if (ev == EMPURRAO) {
            passaram++;
            return TRAVADA;
        }
        desperdicados++;
        return LIBERADA;
    }
    return TRAVADA;
}

int main(void) {
    const char *estados[] = {"travada", "liberada"};
    const char *eventos[] = {"bilhete", "empurrão"};
    Evento seq[] = {BILHETE, EMPURRAO, EMPURRAO, BILHETE, BILHETE, EMPURRAO, EMPURRAO};
    int n = sizeof seq / sizeof seq[0];

    Estado e = TRAVADA;
    for (int i = 0; i < n; i++) {
        Estado novo = transicao(e, seq[i]);
        printf("%s + %s -> %s\n", estados[e], eventos[seq[i]], estados[novo]);
        e = novo;
    }
    printf("Passaram: %d | Barrados: %d | Bilhetes desperdiçados: %d\n", passaram, barrados, desperdicados);
    return 0;
}
