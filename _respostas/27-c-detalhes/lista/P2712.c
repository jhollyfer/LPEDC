// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2712 · ★★☆ · A célula da planilha (union com etiqueta)

#include <stdio.h>
#include <string.h>

typedef enum { INTEIRO, REAL, TEXTO } Tipo;

typedef struct {
    Tipo tipo; // a etiqueta diz qual campo da union vale
    union {
        int i;
        double d;
        char s[16];
    } v;
} Celula;

void mostrar(const Celula *c) {
    switch (c->tipo) {
    case INTEIRO:
        printf("inteiro: %d\n", c->v.i);
        break;
    case REAL:
        printf("real: %.2f\n", c->v.d);
        break;
    case TEXTO:
        printf("texto: %s\n", c->v.s);
        break;
    }
}

int main(void) {
    Celula a, b, c;
    a.tipo = INTEIRO;
    a.v.i = 42;
    b.tipo = REAL;
    b.v.d = 3.14;
    c.tipo = TEXTO;
    strcpy(c.v.s, "feira");
    mostrar(&a);
    mostrar(&b);
    mostrar(&c);
    printf("sizeof(Celula) = %zu, sizeof da union = %zu\n", sizeof(Celula), sizeof c.v);
    return 0;
}
