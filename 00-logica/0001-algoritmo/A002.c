// A002 · O miojo de 3 minutos (as três peças juntas)

#include <stdio.h>

int main(void) {
    int minutos = 3;

    // sequência: um passo depois do outro
    printf("1. Ferva 500 ml de água\n");
    printf("2. Coloque o macarrão\n");

    // repetição: o mesmo passo, uma vez por minuto
    for (int m = 1; m <= minutos; m++) {
        printf("   ... minuto %d\n", m);
    }

    // decisão: o tempero só entra se a pessoa quiser
    int quer_tempero = 1; // 1 = sim, 0 = não
    if (quer_tempero) {
        printf("3. Misture o tempero\n");
    }
    printf("Pronto!\n");
    return 0;
}
// Saída:
// 1. Ferva 500 ml de água
// 2. Coloque o macarrão
//    ... minuto 1
//    ... minuto 2
//    ... minuto 3
// 3. Misture o tempero
// Pronto!
