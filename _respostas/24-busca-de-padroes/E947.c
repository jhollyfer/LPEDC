// 0158 · KMP
// Exercício E947 · ★★★

#include <stdio.h>
#include <string.h>

#define MAX 16

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

// a central recebe as teclas uma a uma e desarma quando a senha aparece
void central(const char *senha, const char *teclas) {
    int m = (int) strlen(senha);
    int pi[MAX];
    int k = 0;
    calcula_pi(senha, m, pi);
    for (int i = 0; teclas[i] != '\0'; i++) {
        while (k > 0 && teclas[i] != senha[k]) {   // era um if: recuava uma vez só
            k = pi[k - 1];
        }
        if (teclas[i] == senha[k]) {
            k++;
        }
        if (k == m) {
            printf("%s: desarmou na tecla %d (a senha começou na posição %d)\n",
                   teclas, i + 1, i - m + 1);
            return;
        }
    }
    printf("%s: continua armado\n", teclas);
}

int main(void) {
    central("1112", "1121112");
    central("1112", "112112111");
    return 0;
}
