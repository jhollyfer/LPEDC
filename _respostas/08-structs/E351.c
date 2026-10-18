// 0059 · Struct
// Exercício E351 · ★★☆

#include <stdbool.h>
#include <stdio.h>

struct ponto {
    double x;
    double y;
};

struct retangulo {
    struct ponto inf_esq;
    struct ponto sup_dir;
};

double largura(struct retangulo r) {
    return r.sup_dir.x - r.inf_esq.x;
}

double altura(struct retangulo r) {
    return r.sup_dir.y - r.inf_esq.y;
}

double area(struct retangulo r) {
    return largura(r) * altura(r);
}

double perimetro(struct retangulo r) {
    return 2 * (largura(r) + altura(r));
}

bool dentro(struct retangulo r, struct ponto p) {
    return p.x >= r.inf_esq.x && p.x <= r.sup_dir.x &&
           p.y >= r.inf_esq.y && p.y <= r.sup_dir.y;
}

void mostrar_arvore(struct retangulo r, struct ponto p) {
    printf("Árvore em (%.1f, %.1f): %s\n", p.x, p.y, dentro(r, p) ? "dentro" : "fora");
}

int main(void) {
    struct retangulo terreno = {{2, 1}, {10, 6}};

    printf("Largura: %.1f m, altura: %.1f m\n", largura(terreno), altura(terreno));
    printf("Área: %.1f m2\n", area(terreno));
    printf("Perímetro: %.1f m\n", perimetro(terreno));
    mostrar_arvore(terreno, (struct ponto){4, 3});
    mostrar_arvore(terreno, (struct ponto){11, 2});
    return 0;
}
