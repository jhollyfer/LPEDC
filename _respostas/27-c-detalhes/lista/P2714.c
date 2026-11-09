// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2714 · ★★☆ · Um processador de brinquedo

#include <stdio.h>

typedef enum { LOAD, ADD, SUB, JMP } Operacao;

int main(void) {
    unsigned char programa[] = {0x05, 0x47, 0x83, 0xC0};
    int acc = 0;
    for (int i = 0; i < 4; i++) {
        unsigned b = programa[i];
        Operacao op = (Operacao)((b >> 6) & 3u);
        int operando = (int)(b & 0x3Fu);
        printf("0x%02X: ", b);
        switch (op) {
        case LOAD:
            acc = operando;
            printf("LOAD %d -> acc = %d\n", operando, acc);
            break;
        case ADD:
            acc += operando;
            printf("ADD %d -> acc = %d\n", operando, acc);
            break;
        case SUB:
            acc -= operando;
            printf("SUB %d -> acc = %d\n", operando, acc);
            break;
        case JMP:
            printf("JMP %d (fim do programa)\n", operando);
            break;
        }
    }
    return 0;
}
