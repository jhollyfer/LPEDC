// Lista · Módulo 02 · Decisões
// Exercício P0227 · ★★★ · O ano em algarismos romanos

#include <stdio.h>

int main(void) {
    int ano;

    printf("Ano (1 a 3999): ");
    if (scanf("%d", &ano) != 1 || ano < 1 || ano > 3999) {
        printf("Fora da faixa.\n");
        return 1;
    }

    switch (ano / 1000) {
        case 3: printf("MMM"); break;
        case 2: printf("MM"); break;
        case 1: printf("M"); break;
        default: break;
    }
    switch (ano / 100 % 10) {
        case 1: printf("C"); break;
        case 2: printf("CC"); break;
        case 3: printf("CCC"); break;
        case 4: printf("CD"); break;
        case 5: printf("D"); break;
        case 6: printf("DC"); break;
        case 7: printf("DCC"); break;
        case 8: printf("DCCC"); break;
        case 9: printf("CM"); break;
        default: break;
    }
    switch (ano / 10 % 10) {
        case 1: printf("X"); break;
        case 2: printf("XX"); break;
        case 3: printf("XXX"); break;
        case 4: printf("XL"); break;
        case 5: printf("L"); break;
        case 6: printf("LX"); break;
        case 7: printf("LXX"); break;
        case 8: printf("LXXX"); break;
        case 9: printf("XC"); break;
        default: break;
    }
    switch (ano % 10) {
        case 1: printf("I"); break;
        case 2: printf("II"); break;
        case 3: printf("III"); break;
        case 4: printf("IV"); break;
        case 5: printf("V"); break;
        case 6: printf("VI"); break;
        case 7: printf("VII"); break;
        case 8: printf("VIII"); break;
        case 9: printf("IX"); break;
        default: break;
    }
    printf("\n");
    return 0;
}
