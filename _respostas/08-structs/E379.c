// 0064 · Union
// Exercício E379 · ★☆☆

#include <stddef.h>
#include <stdio.h>

union Caixa { char c; int i; double d; };
struct Ficha { char c; int i; double d; };
union Nome { char texto[10]; int codigo; };

int main(void) {
    printf("union Caixa: %zu bytes, campos em %zu, %zu e %zu\n", sizeof(union Caixa),
           offsetof(union Caixa, c), offsetof(union Caixa, i), offsetof(union Caixa, d));
    printf("struct Ficha: %zu bytes, campos em %zu, %zu e %zu\n", sizeof(struct Ficha),
           offsetof(struct Ficha, c), offsetof(struct Ficha, i), offsetof(struct Ficha, d));
    // 10 bytes de texto, arredondados para múltiplo de 4 por causa do int
    printf("union Nome: %zu bytes\n", sizeof(union Nome));
    return 0;
}
