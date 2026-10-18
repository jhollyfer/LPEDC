// 0064 · Union
// Exercício E382 · ★★☆

#include <stdio.h>

#define PI 3.14159265358979

typedef enum { CIRCULO, RETANGULO, TRIANGULO } TipoForma;

typedef struct {
    TipoForma tipo;
    union {
        double raio;
        struct { double largura, altura; } ret;
        struct { double base, altura; } tri;
    } medida;
} Forma;

double area(const Forma *f) {
    switch (f->tipo) {
    case CIRCULO:
        return PI * f->medida.raio * f->medida.raio;
    case RETANGULO:
        return f->medida.ret.largura * f->medida.ret.altura;
    case TRIANGULO:
        return f->medida.tri.base * f->medida.tri.altura / 2;
    }
    return 0;
}

int main(void) {
    const char *nomes[] = {"círculo", "retângulo", "triângulo"};
    Forma pecas[] = {
        {CIRCULO, .medida.raio = 2},
        {RETANGULO, .medida.ret = {3, 4}},
        {TRIANGULO, .medida.tri = {6, 5}},
    };
    double total = 0;

    for (int i = 0; i < 3; i++) {
        double a = area(&pecas[i]);
        printf("%s: %.2f m2\n", nomes[pecas[i].tipo], a);
        total += a;
    }
    printf("Total: %.2f m2\n", total);
    return 0;
}
