// 0143 · Juntando tudo: um mini-diff
// Exercício E855 · ★★☆
//
// O programa abaixo é o mini-diff do texto, comparando duas versões de um
// programa em C. Estenda-o para mostrar, antes de cada linha, o número dela
// na versão antiga e na nova, como as ferramentas de revisão de código:
// linha igual mostra os dois números; linha removida, só o antigo; linha
// adicionada, só o novo. Use exatamente estes formatos:
//
//   igual:     "%3d %3d   %s\n"
//   removida:  "%3d     - %s\n"
//   adicionada: "    %3d + %s\n"
//
//   Saída esperada:
//     1   1   #include <stdio.h>
//     2     - // versão 1
//         2 + // versão 2
//     3   3   int main(void) {
//     4     -     printf("oi\n");
//         4 +     int x = 2;
//         5 +     printf("%d\n", x);
//     5   6       return 0;
//     6   7   }
//   (4 iguais, 2 removidas, 3 adicionadas)
//
// Dicas:
// 1. Os números saem dos próprios índices: a linha a[i] é a de número
//    i + 1 na versão antiga, e b[j] é a j + 1 na nova.
// 2. Só os três printf da volta mudam; o resto fica igual.
// 3. Rode também com dois arquivos seus: ~/LPEDC/rodar E855.c a.txt b.txt
//    (o rodar compila junto o linhas.c da pasta).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (estenda o programa):

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linhas.h"

// diff linha a linha: LCS dos SUFIXOS, para a volta andar do começo ao fim
void diff(char **a, int m, char **b, int n) {
    // c[i * w + j] = LCS de a[i..m-1] e b[j..n-1]: a matriz (m+1) x (n+1)
    // num bloco só do malloc, linha após linha
    int w = n + 1;
    int *c = malloc((size_t) (m + 1) * w * sizeof *c);
    if (c == NULL) {
        return;
    }
    for (int i = m; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
            if (i == m || j == n) {
                c[i * w + j] = 0;                      // um sufixo vazio
            } else if (strcmp(a[i], b[j]) == 0) {
                c[i * w + j] = c[(i + 1) * w + j + 1] + 1;
            } else {
                int baixo = c[(i + 1) * w + j], dir = c[i * w + j + 1];
                c[i * w + j] = baixo >= dir ? baixo : dir;
            }
        }
    }

    int i = 0, j = 0, iguais = 0, menos = 0, mais = 0;
    while (i < m || j < n) {
        if (i < m && j < n && strcmp(a[i], b[j]) == 0) {
            printf("  %s\n", a[i]);
            i++;
            j++;
            iguais++;
        } else if (j == n || (i < m && c[(i + 1) * w + j] >= c[i * w + j + 1])) {
            printf("- %s\n", a[i]);
            i++;
            menos++;
        } else {
            printf("+ %s\n", b[j]);
            j++;
            mais++;
        }
    }
    printf("(%d iguais, %d removidas, %d adicionadas)\n", iguais, menos, mais);
    free(c);
}

int main(int argc, char *argv[]) {
    const char *antigo = "/tmp/e855-v1.txt";
    const char *novo = "/tmp/e855-v2.txt";
    if (argc == 3) {                                   // rodar mini-diff.c a.txt b.txt
        antigo = argv[1];
        novo = argv[2];
    } else {                                           // sem argumentos: o exemplo
        const char *v1[] = {"#include <stdio.h>", "// versão 1", "int main(void) {",
                            "    printf(\"oi\\n\");", "    return 0;", "}"};
        const char *v2[] = {"#include <stdio.h>", "// versão 2", "int main(void) {",
                            "    int x = 2;", "    printf(\"%d\\n\", x);",
                            "    return 0;", "}"};
        grava_linhas(antigo, v1, 6);
        grava_linhas(novo, v2, 7);
    }

    int m = 0, n = 0;
    char **a = le_linhas(antigo, &m);
    char **b = le_linhas(novo, &n);
    if (a != NULL && b != NULL) {
        diff(a, m, b, n);
    }
    libera_linhas(a, m);
    libera_linhas(b, n);
    return 0;
}
