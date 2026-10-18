// 0063 · Enum
// Exercício E374 · ★☆☆

#include <stdio.h>

typedef enum { VERDE, AMARELO, VERMELHO } Cor;

Cor proxima(Cor c) {
    switch (c) {
    case VERDE:
        return AMARELO;
    case AMARELO:
        return VERMELHO;
    case VERMELHO:
        return VERDE;
    }
    return VERMELHO; // valor inválido: na dúvida, pare
}

const char *nome(Cor c) {
    switch (c) {
    case VERDE:
        return "verde";
    case AMARELO:
        return "amarelo";
    case VERMELHO:
        return "vermelho";
    }
    return "?";
}

int main(void) {
    Cor c = VERDE;
    for (int i = 0; i < 6; i++) {
        Cor depois = proxima(c);
        printf("%s -> %s\n", nome(c), nome(depois));
        c = depois;
    }
    return 0;
}
