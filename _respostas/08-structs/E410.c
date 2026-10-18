// 0069 · Union
// Exercício E410 · ★☆☆

#include <stdint.h>
#include <stdio.h>

typedef union {
    float f;
    uint32_t bits;
} Espiao;

void mostrar(const char *texto, float valor) {
    Espiao e;
    e.f = valor;
    printf("%s -> 0x%08X\n", texto, (unsigned)e.bits);
}

int main(void) {
    mostrar("1.0", 1.0f);
    mostrar("-2.0", -2.0f);
    mostrar("0.5", 0.5f);
    mostrar("0.1", 0.1f);
    return 0;
}
