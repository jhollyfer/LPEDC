// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2724 · ★★★ · Figuras lidas de um arquivo

#include <math.h>
#include <stdio.h>

typedef enum { CIRCULO, RETANGULO, TRIANGULO } Forma;

typedef struct {
    Forma forma;
    union {
        struct { double r; } c;
        struct { double l, a; } r;
        struct { double a, b, c; } t;
    } m;
} Figura;

double area(const Figura *f) {
    switch (f->forma) {
    case CIRCULO:
        return acos(-1.0) * f->m.c.r * f->m.c.r;
    case RETANGULO:
        return f->m.r.l * f->m.r.a;
    case TRIANGULO: {
        double a = f->m.t.a, b = f->m.t.b, c = f->m.t.c;
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    }
    return 0;
}

int main(void) {
    FILE *f = fopen("p2724_figuras.txt", "w");
    if (f == NULL) {
        printf("não consegui criar o arquivo\n");
        return 1;
    }
    fprintf(f, "C 2\nR 3 4\nT 3 4 5\n");
    fclose(f);

    f = fopen("p2724_figuras.txt", "r");
    if (f == NULL) {
        printf("não consegui abrir o arquivo\n");
        return 1;
    }
    char letra;
    double total = 0;
    while (fscanf(f, " %c", &letra) == 1) {
        Figura fig;
        int ok = 0;
        switch (letra) {
        case 'C':
            fig.forma = CIRCULO;
            ok = fscanf(f, "%lf", &fig.m.c.r) == 1;
            break;
        case 'R':
            fig.forma = RETANGULO;
            ok = fscanf(f, "%lf %lf", &fig.m.r.l, &fig.m.r.a) == 2;
            break;
        case 'T':
            fig.forma = TRIANGULO;
            ok = fscanf(f, "%lf %lf %lf", &fig.m.t.a, &fig.m.t.b, &fig.m.t.c) == 3;
            break;
        }
        if (!ok) {
            break;
        }
        double a = area(&fig);
        total += a;
        switch (fig.forma) {
        case CIRCULO:
            printf("círculo de raio %.1f: %.2f\n", fig.m.c.r, a);
            break;
        case RETANGULO:
            printf("retângulo %.1f x %.1f: %.2f\n", fig.m.r.l, fig.m.r.a, a);
            break;
        case TRIANGULO:
            printf("triângulo %.1f, %.1f, %.1f: %.2f\n", fig.m.t.a, fig.m.t.b, fig.m.t.c, a);
            break;
        }
    }
    fclose(f);
    remove("p2724_figuras.txt");
    printf("área total: %.2f\n", total);
    return 0;
}
