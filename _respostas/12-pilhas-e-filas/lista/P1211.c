// Lista · Módulo 12 · Pilhas e filas
// Exercício P1211 · ★★☆ · Pós-fixa com potência (que associa à direita)

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int prec(char op) {
    if (op == '^') {
        return 3;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    if (op == '+' || op == '-') {
        return 1;
    }
    return 0; // '(' não é operador
}

void para_posfixa(const char *in, char *out) {
    char pilha[100];
    int n = 0, k = 0;
    for (int i = 0; in[i] != '\0'; i++) {
        char c = in[i];
        if (isalpha((unsigned char) c)) {
            out[k++] = c;
        } else if (c == '(') {
            pilha[n++] = c;
        } else if (c == ')') {
            while (n > 0 && pilha[n - 1] != '(') {
                out[k++] = pilha[--n];
            }
            if (n > 0) {
                n--; // descarta o '('
            }
        } else if (prec(c) > 0) {
            bool esquerda = c != '^';
            while (n > 0 && prec(pilha[n - 1]) > 0 &&
                   (prec(pilha[n - 1]) > prec(c) || (prec(pilha[n - 1]) == prec(c) && esquerda))) {
                out[k++] = pilha[--n];
            }
            pilha[n++] = c;
        }
    }
    while (n > 0) {
        out[k++] = pilha[--n];
    }
    out[k] = '\0';
}

int main(void) {
    const char *exprs[6] = {"A+B*C", "(A+B)*C", "A-B-C", "A^B^C", "A*(B+C)^D", "A/B^C-D"};
    for (int i = 0; i < 6; i++) {
        char saida[100];
        para_posfixa(exprs[i], saida);
        printf("%s -> %s\n", exprs[i], saida);
    }
    return 0;
}
