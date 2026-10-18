// 0009 · Constantes
// Exercício E054 · ★★★
//
// Resposta: "CIDADE: Recife" (dentro das aspas nada é trocado), "DDD 81",
// "8 16 10" (octal, hexa e decimal), "Oi!" (0x69 = 105 = 'i'; 33 = '!'),
// "50% off" e "a\n b" (o \\ vira uma barra; o n fica como letra).

#include <stdio.h>

#define CIDADE "Recife"
#define DDD 81

int main(void) {
    printf("CIDADE: %s\n", CIDADE);
    printf("DDD %d\n", DDD);
    printf("%d %d %d\n", 010, 0x10, 10);
    printf("%c%c%c\n", 'O', 0x69, 33);
    printf("50%% off\n");
    printf("a\\n b\n");
    return 0;
}
