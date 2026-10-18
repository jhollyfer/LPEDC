// 0063 · Enum
// Exercício E376 · ★★☆
//
// Resposta: faltava o case COPAS. O default capturava COPAS e devolvia
// "???", e o gcc não avisou porque, com default, ele entende que você tratou
// "todo o resto". Sem default, o -Wall avisa quando um nome do enum fica sem
// case; o "???" vai para depois do switch, só para valores inválidos.

#include <stdio.h>

typedef enum { OUROS, ESPADAS, COPAS, PAUS } Naipe;

const char *nome_naipe(Naipe n) {
    switch (n) {
    case OUROS:
        return "ouros";
    case ESPADAS:
        return "espadas";
    case COPAS:
        return "copas";
    case PAUS:
        return "paus";
    }
    return "???";
}

int main(void) {
    for (Naipe n = OUROS; n <= PAUS; n++) {
        printf("7 de %s\n", nome_naipe(n));
    }
    return 0;
}
