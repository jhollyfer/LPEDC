// A137 · Opções com hífen

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Uma tabuada com opções, no estilo dos programas de terminal:
//   tabuada [-a ate] [-r] <numero>
// -a muda até onde vai (padrão 10) e precisa de um valor logo depois;
// -r mostra de trás para frente. As opções podem vir em qualquer ordem.
//
// Rode assim:  ~/LPEDC/rodar 09-arquivos/0069-argumentos/A137.c -r 7 -a 4

// converte texto em inteiro positivo; devolve 0 se não for
long positivo(const char *texto) {
    char *fim;
    long n = strtol(texto, &fim, 10);
    if (fim == texto || *fim != '\0' || n <= 0) {
        return 0;
    }
    return n;
}

int main(int argc, char *argv[]) {
    long numero = 0;
    long ate = 10;
    bool inverso = false;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-r") == 0) {
            inverso = true;
        } else if (strcmp(argv[i], "-a") == 0) {
            if (i + 1 >= argc) { // -a era o último: falta o valor
                fprintf(stderr, "A opção -a precisa de um valor\n");
                return 1;
            }
            i++; // o valor é consumido aqui; o laço não olha para ele de novo
            ate = positivo(argv[i]);
            if (ate == 0) {
                fprintf(stderr, "Valor inválido para -a: %s\n", argv[i]);
                return 1;
            }
        } else if (argv[i][0] == '-') {
            fprintf(stderr, "Opção desconhecida: %s\n", argv[i]);
            return 1;
        } else {
            numero = positivo(argv[i]);
            if (numero == 0) {
                fprintf(stderr, "Número inválido: %s\n", argv[i]);
                return 1;
            }
        }
    }
    if (numero == 0) {
        fprintf(stderr, "Uso: %s [-a ate] [-r] <numero>\n", argv[0]);
        return 1;
    }

    for (long k = 1; k <= ate; k++) {
        long m = inverso ? ate - k + 1 : k;
        printf("%ld x %ld = %ld\n", numero, m, numero * m);
    }
    return 0;
}
// $ rodar A137.c -r 7 -a 4
// 7 x 4 = 28
// 7 x 3 = 21
// 7 x 2 = 14
// 7 x 1 = 7
//
// $ rodar A137.c 3 -a 2
// 3 x 1 = 3
// 3 x 2 = 6
//
// $ rodar A137.c 7 -a
// A opção -a precisa de um valor
//
// $ rodar A137.c 7 -x
// Opção desconhecida: -x
