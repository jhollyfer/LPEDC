// 0059 · Struct
// Exercício E354 · ★★★

#include <stddef.h>
#include <stdio.h>

struct a { char ativo; int id; char nivel; };
struct b { int id; char ativo; char nivel; };
struct c { char ativo; double saldo; char nivel; };
struct d { double saldo; int id; char ativo; char nivel; };

// do maior para o menor: id em 0, ativo em 4, nivel em 5, 2 de sobra
struct a_enxuta { int id; char ativo; char nivel; };

int main(void) {
    printf("sizeof: a = %zu, b = %zu, c = %zu, d = %zu\n",
           sizeof(struct a), sizeof(struct b), sizeof(struct c), sizeof(struct d));
    printf("struct a: ativo em %zu, id em %zu, nivel em %zu\n",
           offsetof(struct a, ativo), offsetof(struct a, id), offsetof(struct a, nivel));
    printf("struct a_enxuta: %zu bytes\n", sizeof(struct a_enxuta));
    return 0;
}
