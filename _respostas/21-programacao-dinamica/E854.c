// 0143 · Juntando tudo: um mini-diff
// Exercício E854 · ★☆☆

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX 20

// 1 se as duas linhas são iguais ignorando maiúsculas/minúsculas e os
// espaços no fim da linha; 0 se não
int iguais(const char *x, const char *y) {
    int nx = strlen(x), ny = strlen(y);
    while (nx > 0 && x[nx - 1] == ' ') {
        nx--;                       // ignora os espaços do fim
    }
    while (ny > 0 && y[ny - 1] == ' ') {
        ny--;
    }
    if (nx != ny) {
        return 0;
    }
    for (int k = 0; k < nx; k++) {
        if (tolower((unsigned char) x[k]) != tolower((unsigned char) y[k])) {
            return 0;
        }
    }
    return 1;
}

void diff(const char *a[], int m, const char *b[], int n) {
    int c[MAX + 1][MAX + 1];
    for (int i = m; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
            if (i == m || j == n) {
                c[i][j] = 0;
            } else if (iguais(a[i], b[j])) {
                c[i][j] = c[i + 1][j + 1] + 1;
            } else {
                c[i][j] = c[i + 1][j] >= c[i][j + 1] ? c[i + 1][j] : c[i][j + 1];
            }
        }
    }
    int i = 0, j = 0;
    while (i < m || j < n) {
        if (i < m && j < n && iguais(a[i], b[j])) {
            printf("  %s\n", a[i]);
            i++;
            j++;
        } else if (j == n || (i < m && c[i + 1][j] >= c[i][j + 1])) {
            printf("- %s\n", a[i++]);
        } else {
            printf("+ %s\n", b[j++]);
        }
    }
}

int main(void) {
    const char *antes[] = {"Nome: Loja do Zé", "Cidade: Fortaleza",
                           "Horario: 8h as 18h", "Pix: sim", "Entrega: nao"};
    const char *depois[] = {"NOME: Loja do Zé   ", "cidade: fortaleza",
                            "Horario: 8h as 20h", "Pix: SIM", "Entrega: sim"};
    diff(antes, 5, depois, 5);
    return 0;
}
