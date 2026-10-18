// 0069 · Union
// Exercício E409 · ★☆☆
//
// Resposta: union Caixa = 8 (o double); struct Ficha = 16 (c em 0, 3 de
// sobra, i em 4, d em 8); union Nome = 12 (10 bytes arredondados para
// múltiplo de 4, por causa do int).

#include <stdio.h>

union Caixa { char c; int i; double d; };
struct Ficha { char c; int i; double d; };
union Nome { char texto[10]; int codigo; };

int main(void) {
    printf("union Caixa: %zu\n", sizeof(union Caixa));
    printf("struct Ficha: %zu\n", sizeof(struct Ficha));
    printf("union Nome: %zu\n", sizeof(union Nome));
    return 0;
}
