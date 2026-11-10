// A317 · Padrão comprido, busca mais rápida

#include <stdio.h>
#include <string.h>

#define ALFABETO 256
#define TAM 4000

// força bruta: devolve as comparações de letra
long forca_bruta(const char *t, int n, const char *p, int m) {
    long comp = 0;
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m) {
            comp++;
            if (t[i + j] != p[j]) {
                break;
            }
            j++;
        }
    }
    return comp;
}

// Horspool: devolve as comparações de letra
long horspool(const char *t, int n, const char *p, int m) {
    int salto[ALFABETO];
    for (int c = 0; c < ALFABETO; c++) {
        salto[c] = m;
    }
    for (int j = 0; j < m - 1; j++) {
        salto[(unsigned char) p[j]] = m - 1 - j;
    }
    long comp = 0;
    int i = 0;
    while (i <= n - m) {
        int j = m - 1;
        while (j >= 0) {
            comp++;
            if (t[i + j] != p[j]) {
                break;
            }
            j--;
        }
        i += salto[(unsigned char) t[i + m - 1]];
    }
    return comp;
}

int main(void) {
    // um texto de 2800 letras: a mesma frase de 28 letras, 100 vezes
    char texto[TAM] = "";
    for (int r = 0; r < 100; r++) {
        strcat(texto, "o rato roeu a roupa do rei. ");
    }
    int n = (int) strlen(texto);

    // nenhum destes padrões aparece: as duas buscas varrem o texto todo
    const char *padroes[] = {"rua", "rainha", "rei de roma", "a rainha roeu a ropa"};
    printf("n = %d\n", n);
    for (int k = 0; k < 4; k++) {
        int m = (int) strlen(padroes[k]);
        printf("m = %2d: força bruta %5ld, Horspool %5ld\n", m,
               forca_bruta(texto, n, padroes[k], m), horspool(texto, n, padroes[k], m));
    }
    return 0;
}
// Saída:
// n = 2800
// m =  3: força bruta  3198, Horspool  1200
// m =  6: força bruta  3294, Horspool   598
// m = 11: força bruta  3387, Horspool   546
// m = 20: força bruta  3376, Horspool   498
