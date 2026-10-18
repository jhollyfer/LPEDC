// 0011 · scanf
// Exercício E065 · ★★★
//
// Resposta:
//   '7 9'     -> lidos=2 a=7 b=9
//   '7 x'     -> lidos=1 a=7 b=0   (o x não serve para %d: para ali)
//   'x 7'     -> lidos=0 a=0 b=0   (falha logo no primeiro)
//   '7\n\n9'  -> lidos=2 a=7 b=9   (o %d pula quantos Enters houver)
//   ''        -> lidos=-1 a=0 b=0  (fim da entrada: EOF)

#include <stdio.h>

int main(void) {
    int a = 0, b = 0;
    int lidos = scanf("%d %d", &a, &b);
    printf("lidos=%d a=%d b=%d\n", lidos, a, b);
    return 0;
}
