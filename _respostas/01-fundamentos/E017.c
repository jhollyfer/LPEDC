// 0003 · Tipos e limites
// Exercício E017 · ★★★

#include <stdio.h>
#include <stdint.h>

int main(void) {
    long long segundos_ano = 365 * 24 * 60 * 60; // 31536000 cabe num int

    printf("int32_t vai até %d\n", INT32_MAX);
    printf("68 anos: %lld segundos\n", 68 * segundos_ano); // feita em long long
    printf("69 anos: %lld segundos\n", 69 * segundos_ano); // passa do INT32_MAX
    printf("int64_t vai até %lld\n", (long long)INT64_MAX);
    return 0;
}
