// 0119 · Shell sort
// Exercício E711 · ★★☆

#include <stdio.h>
#include <string.h>

static int comparacoes = 0;

// shell sort de strings: só os ponteiros mudam de lugar
void shell_nomes(const char *v[], int n) {
    int h = 1;
    while (h < n / 3) {
        h = 3 * h + 1;
    }
    for (; h >= 1; h /= 3) {
        for (int i = h; i < n; i++) {
            const char *x = v[i];
            int j = i;
            while (j >= h) {
                comparacoes++;
                if (strcmp(v[j - h], x) <= 0) {
                    break;
                }
                v[j] = v[j - h];
                j -= h;
            }
            v[j] = x;
        }
    }
}

int main(void) {
    const char *convidados[] = {"Rafael", "Bianca", "Tiago", "Larissa", "Diego", "Amanda",
                                "Paulo", "Helena", "Caio", "Sofia", "Murilo", "Elisa"};
    int n = 12;

    shell_nomes(convidados, n);
    for (int i = 0; i < n; i++) {
        printf("%s%s", convidados[i], i < n - 1 ? ", " : "\n");
    }
    printf("%d comparações\n", comparacoes);
    return 0;
}
