// 0064 · Struct
// Exercício E384 · ★★★
//
// Resposta: a = 12 (ativo 0, 3 de sobra, id 4, nivel 8, 3 de sobra no fim),
// b = 8 (id 0, ativo 4, nivel 5, 2 de sobra), c = 24 (ativo 0, 7 de sobra,
// saldo 8, nivel 16, 7 de sobra) e d = 16 (saldo 0, id 8, ativo 12, nivel 13,
// 2 de sobra). Do maior campo para o menor desperdiça menos.

#include <stddef.h>
#include <stdio.h>

struct a { char ativo; int id; char nivel; };
struct b { int id; char ativo; char nivel; };
struct c { char ativo; double saldo; char nivel; };
struct d { double saldo; int id; char ativo; char nivel; };

int main(void) {
    printf("sizeof: a = %zu, b = %zu, c = %zu, d = %zu\n",
           sizeof(struct a), sizeof(struct b), sizeof(struct c), sizeof(struct d));
    printf("struct a: ativo em %zu, id em %zu, nivel em %zu\n",
           offsetof(struct a, ativo), offsetof(struct a, id), offsetof(struct a, nivel));
    return 0;
}
