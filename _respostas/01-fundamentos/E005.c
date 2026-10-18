// 0001 · O primeiro programa
// Exercício E005 · ★★★
//
// Rode com: ~/LPEDC/rodar E005.c; echo "código: $?"

#include <stdio.h>

int main(void) {
    printf("Backup falhou: disco cheio\n");
    printf("Código de saída: 2\n");
    return 2; // com return 258, o sistema também recebe 2 (258 - 256)
}
