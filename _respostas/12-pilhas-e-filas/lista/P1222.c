// Lista · Módulo 12 · Pilhas e filas
// Exercício P1222 · ★★★ · Calcular a infixa direto, com duas pilhas

#include <ctype.h>
#include <stdio.h>

#define CAP 100

typedef struct {
    int valores[CAP];
    int nv;
    char ops[CAP];
    int no;
} Pilhas;

int prec(char op) {
    if (op == '*' || op == '/') {
        return 2;
    }
    if (op == '+' || op == '-') {
        return 1;
    }
    return 0; // '('
}

// aplica o operador do topo; devolve 0 se faltou operando ou dividiu por zero
int aplica(Pilhas *p) {
    if (p->no == 0 || p->nv < 2) {
        return 0;
    }
    char op = p->ops[--p->no];
    int b = p->valores[--p->nv]; // o da direita sai primeiro
    int a = p->valores[--p->nv];
    int r;
    if (op == '+') {
        r = a + b;
    } else if (op == '-') {
        r = a - b;
    } else if (op == '*') {
        r = a * b;
    } else if (op == '/' && b != 0) {
        r = a / b;
    } else {
        return 0;
    }
    p->valores[p->nv++] = r;
    return 1;
}

int avalia(const char *s, int *resultado) {
    Pilhas p = {.nv = 0, .no = 0};
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (isdigit((unsigned char) c)) {
            p.valores[p.nv++] = c - '0';
        } else if (c == '(') {
            p.ops[p.no++] = c;
        } else if (c == ')') {
            while (p.no > 0 && p.ops[p.no - 1] != '(') {
                if (!aplica(&p)) {
                    return 0;
                }
            }
            if (p.no == 0) {
                return 0; // ')' sem '('
            }
            p.no--; // descarta o '('
        } else if (prec(c) > 0) {
            while (p.no > 0 && prec(p.ops[p.no - 1]) >= prec(c)) {
                if (!aplica(&p)) {
                    return 0;
                }
            }
            p.ops[p.no++] = c;
        }
    }
    while (p.no > 0) {
        if (!aplica(&p)) {
            return 0;
        }
    }
    if (p.nv != 1) {
        return 0;
    }
    *resultado = p.valores[0];
    return 1;
}

int main(void) {
    const char *exprs[6] = {"2+3*4", "(2+3)*4", "8-3-2", "9/3/3", "2*(3+4)-5", "7/(2-2)"};
    for (int i = 0; i < 6; i++) {
        int r;
        if (avalia(exprs[i], &r)) {
            printf("%s = %d\n", exprs[i], r);
        } else {
            printf("%s: erro\n", exprs[i]);
        }
    }
    return 0;
}
