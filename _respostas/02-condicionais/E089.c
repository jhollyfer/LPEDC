// 0015 · if/else e o = no lugar do ==
// Exercício E089 · ★★★
//
// Resposta: com "b = 2", b recebe 2 e o if testa 2 (verdade); a == 2 é
// falso, então mostra "Y 3 2". Com "b == 2", 0 == 2 é falso, cai no else
// de fora e mostra "Z 3 0". Abaixo, a versão com ==.

#include <stdio.h>

int main(void) {
    int a = 3, b = 0;
    if (b == 2) {
        if (a == 2) {
            printf("X ");
        } else {
            printf("Y ");
        }
    } else {
        printf("Z ");
    }
    printf("%d %d\n", a, b);
    return 0;
}
