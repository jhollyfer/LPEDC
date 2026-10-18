// 0001 · O primeiro programa
// Exercício E002 · ★☆☆
//
// Resposta: a saída tem 5 linhas (a 4ª é vazia):
//
//   Bom dia!
//   Café
//   Pão
//
//   Manteiga
//
// Os três primeiros printf montam uma linha só, porque só o último tem \n.
// O "Boa tarde" está comentado e não roda. Os dois \n seguidos depois de
// "Pão" deixam uma linha em branco.

#include <stdio.h>

int main(void) {
    printf("Bom ");
    printf("dia");
    printf("!\n");
    // printf("Boa tarde\n");
    printf("Café\nPão\n\nManteiga\n");
    return 0;
}
