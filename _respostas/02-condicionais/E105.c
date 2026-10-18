// 0018 · switch, case, break e fall-through
// Exercício E105 · ★★☆
//
// Resposta:
// n = 2: entra no case 2, cai no case 5 e para no break → "dois cinco fim"
// n = 5: entra no case 5 e para no break                → "cinco fim"
// n = 7: entra no case 7, que é o último                → "sete fim"
// n = 9: nenhum case casa, entra no default e cai no 7  → "outro sete fim"
// Abaixo, o switch com os comentários de fall-through (para o gcc não
// avisar), rodando para n = 9.

#include <stdio.h>

int main(void) {
    int n = 9;
    switch (n) {
    case 2:
        printf("dois ");
        // fall through
    case 5:
        printf("cinco ");
        break;
    default:
        printf("outro ");
        // fall through
    case 7:
        printf("sete ");
    }
    printf("fim\n");
    return 0;
}
