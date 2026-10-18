// 0052 · Juntando tudo: o ranking da feira
// Exercício E308 · ★☆☆

#include <stdio.h>

void troca(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void estado(const char *rotulo, const int *v, const int *p, const char *s) {
    printf("%-9s %d %d %d %d | p em v[%td] | %s\n", rotulo, v[0], v[1], v[2], v[3], p - v, s);
}

int main(void) {
    int v[4] = {5, 10, 15, 20};
    int *p = v + 3;
    char s[] = "feira";
    char *c = s + 1;

    estado("antes", v, p, s);
    troca(&v[0], p);
    estado("troca", v, p, s);
    *c = 'E';
    estado("*c = 'E'", v, p, s);
    p--;
    estado("p--", v, p, s);
    *p += *(v + 1);
    estado("*p += ...", v, p, s);

    printf("%d %d %d %d | %s | %c\n", v[0], v[1], v[2], v[3], s, *(c + 2));
    return 0;
}
