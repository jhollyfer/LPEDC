// 0060 · Typedef
// Exercício E357 · ★★☆

#include <stdio.h>

typedef struct {
    int num;
    int den;
} Fracao;

int mdc(int a, int b) {
    return b == 0 ? a : mdc(b, a % b);
}

Fracao simplificar(Fracao f) {
    int d = mdc(f.num, f.den);
    f.num /= d;
    f.den /= d;
    return f;
}

Fracao somar(Fracao a, Fracao b) {
    Fracao r = {a.num * b.den + b.num * a.den, a.den * b.den};
    return simplificar(r);
}

Fracao multiplicar(Fracao a, Fracao b) {
    Fracao r = {a.num * b.num, a.den * b.den};
    return simplificar(r);
}

void mostrar(Fracao a, char op, Fracao b, Fracao r) {
    printf("%d/%d %c %d/%d = %d/%d\n", a.num, a.den, op, b.num, b.den, r.num, r.den);
}

int main(void) {
    Fracao um_quarto = {1, 4};
    Fracao um_sexto = {1, 6};
    Fracao dois_tercos = {2, 3};
    Fracao nove_quartos = {9, 4};
    Fracao tres_quartos = {3, 4};

    mostrar(um_quarto, '+', um_sexto, somar(um_quarto, um_sexto));
    mostrar(dois_tercos, '*', nove_quartos, multiplicar(dois_tercos, nove_quartos));
    mostrar(tres_quartos, '+', um_quarto, somar(tres_quartos, um_quarto));
    return 0;
}
