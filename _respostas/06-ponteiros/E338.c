// 0057 · Juntando tudo: o ranking da feira
// Exercício E338 · ★☆☆
//
// Resposta: 20 10 25 5 | fEira | r
// troca(&v[0], p) deixa v = 20 10 15 5; *c = 'E' muda s[1]; p-- vai para
// v[2]; *p += *(v + 1) faz 15 + 10 = 25; *(c + 2) é s[3] = 'r'.

#include <stdio.h>

void troca(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void) {
    int v[4] = {5, 10, 15, 20};
    int *p = v + 3;
    char s[] = "feira";
    char *c = s + 1;

    troca(&v[0], p);
    *c = 'E';
    p--;
    *p += *(v + 1);

    printf("%d %d %d %d | %s | %c\n", v[0], v[1], v[2], v[3], s, *(c + 2));
    return 0;
}
