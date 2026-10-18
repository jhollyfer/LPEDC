// 0120 · Counting sort
// Exercício E718 · ★★☆

#include <stdio.h>
#include <string.h>

// ordena as letras de s com counting sort: um contador por valor de char
void ordena_letras(char s[]) {
    int c[256] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        c[(unsigned char) s[i]]++;   // sem o cast, um char negativo daria c[-n]
    }
    int pos = 0;
    for (int x = 0; x < 256; x++) {
        for (int r = 0; r < c[x]; r++) {
            s[pos++] = (char) x;
        }
    }
}

void testa(const char *a, const char *b) {
    char x[32], y[32];
    strcpy(x, a);
    strcpy(y, b);
    ordena_letras(x);
    ordena_letras(y);
    printf("%s -> %s | %s -> %s: %s\n", a, x, b, y,
           strcmp(x, y) == 0 ? "anagramas" : "não são anagramas");
}

int main(void) {
    testa("alegria", "regalia");
    testa("porta", "tropa");
    testa("mesa", "seta");
    testa("carro", "corra");
    return 0;
}
