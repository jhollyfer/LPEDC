// A316 · O refrão que se repete

#include <stdio.h>
#include <string.h>

#define MAX 32

void calcula_pi(const char *p, int m, int pi[]) {
    int k = 0;
    pi[0] = 0;
    for (int j = 1; j < m; j++) {
        while (k > 0 && p[j] != p[k]) {
            k = pi[k - 1];
        }
        if (p[j] == p[k]) {
            k++;
        }
        pi[j] = k;
    }
}

// a string é um pedaço repetido? Se a maior borda tem b letras, a string
// "anda" de m - b em m - b: esse é o menor período. Se ele divide m, a
// string inteira é o pedaço do começo repetido m / período vezes.
void analisa(const char *s) {
    int m = (int) strlen(s);
    int pi[MAX];
    calcula_pi(s, m, pi);
    int periodo = m - pi[m - 1];

    if (periodo < m && m % periodo == 0) {
        printf("%-12s = \"%.*s\" x %d\n", s, periodo, s, m / periodo);
    } else {
        printf("%-12s não é repetição (período %d)\n", s, periodo);
    }
}

int main(void) {
    analisa("chachacha");
    analisa("bombom");
    analisa("lelele");
    analisa("tictac");
    analisa("arara");      // "ar" de novo e de novo, mas sobra um "a"
    analisa("xxxxxxxx");
    return 0;
}
// Saída:
// chachacha    = "cha" x 3
// bombom       = "bom" x 2
// lelele       = "le" x 3
// tictac       não é repetição (período 6)
// arara        não é repetição (período 2)
// xxxxxxxx     = "x" x 8
