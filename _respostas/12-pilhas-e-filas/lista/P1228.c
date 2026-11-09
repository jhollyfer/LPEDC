// Lista · Módulo 12 · Pilhas e filas
// Exercício P1228 · ★★★ · A calculadora da HP (RPN com comandos)

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAP 50

typedef struct {
    double v[CAP];
    int n;
} Pilha;

int eh_numero(const char *s) {
    if (isdigit((unsigned char) s[0])) {
        return 1;
    }
    return (s[0] == '-' || s[0] == '.') && isdigit((unsigned char) s[1]);
}

int executa(const char *programa, double *resultado, char *erro) {
    Pilha p = {.n = 0};
    int i = 0;
    while (programa[i] != '\0') {
        if (programa[i] == ' ') {
            i++;
            continue;
        }
        char item[32];
        int k = 0;
        while (programa[i] != '\0' && programa[i] != ' ' && k < 31) {
            item[k++] = programa[i++];
        }
        item[k] = '\0';

        if (eh_numero(item)) {
            if (p.n == CAP) {
                strcpy(erro, "pilha cheia");
                return 0;
            }
            p.v[p.n++] = atof(item);
        } else if (strcmp(item, "dup") == 0) {
            if (p.n < 1) {
                strcpy(erro, "faltam operandos");
                return 0;
            }
            if (p.n == CAP) {
                strcpy(erro, "pilha cheia");
                return 0;
            }
            p.v[p.n] = p.v[p.n - 1];
            p.n++;
        } else if (strcmp(item, "drop") == 0) {
            if (p.n < 1) {
                strcpy(erro, "faltam operandos");
                return 0;
            }
            p.n--;
        } else {
            if (p.n < 2) {
                strcpy(erro, "faltam operandos");
                return 0;
            }
            double b = p.v[--p.n], a = p.v[--p.n];
            if (strcmp(item, "swap") == 0) {
                p.v[p.n++] = b;
                p.v[p.n++] = a;
            } else if (strcmp(item, "+") == 0) {
                p.v[p.n++] = a + b;
            } else if (strcmp(item, "-") == 0) {
                p.v[p.n++] = a - b;
            } else if (strcmp(item, "*") == 0) {
                p.v[p.n++] = a * b;
            } else if (strcmp(item, "/") == 0) {
                if (b == 0) {
                    strcpy(erro, "divisão por zero");
                    return 0;
                }
                p.v[p.n++] = a / b;
            } else {
                sprintf(erro, "comando desconhecido: %s", item);
                return 0;
            }
        }
    }
    if (p.n != 1) {
        sprintf(erro, "sobraram %d números", p.n);
        return 0;
    }
    *resultado = p.v[0];
    return 1;
}

int main(void) {
    const char *programas[8] = {
        "3 4 + 2 *", "5 dup *", "10 2 swap -", "1 2 3 drop +",
        "1.5 2.5 + 2 /", "4 0 /", "2 +", "7 8",
    };
    for (int i = 0; i < 8; i++) {
        double r;
        char erro[64];
        if (executa(programas[i], &r, erro)) {
            printf("%s => %g\n", programas[i], r);
        } else {
            printf("%s => erro: %s\n", programas[i], erro);
        }
    }
    return 0;
}
