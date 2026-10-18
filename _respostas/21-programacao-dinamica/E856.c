// 0143 · Juntando tudo: um mini-diff
// Exercício E856 · ★★☆

#include <stdio.h>
#include <string.h>

#define MAX 20

// aplica o patch ao original; grava a versão nova em novo e devolve quantas
// linhas ela tem, ou -(k) se a linha k do original não bate com o patch
int aplica(const char *orig[], int m, const char *patch[], int p,
           const char *novo[]) {
    int i = 0, n = 0;
    for (int k = 0; k < p; k++) {
        char tipo = patch[k][0];
        const char *texto = patch[k] + 2;      // pula o "  ", "- " ou "+ "
        if (tipo == '+') {
            novo[n++] = texto;                 // linha nova: entra
        } else {
            // "  " e "- " falam de uma linha do original: ela precisa bater
            if (i >= m || strcmp(orig[i], texto) != 0) {
                return -(i + 1);
            }
            if (tipo == ' ') {
                novo[n++] = orig[i];           // igual: continua
            }
            i++;                               // "- ": some
        }
    }
    return n;
}

void testa(const char *nome, const char *orig[], int m, const char *patch[], int p) {
    const char *novo[MAX];
    int n = aplica(orig, m, patch, p, novo);
    printf("%s: ", nome);
    if (n < 0) {
        printf("o patch não se aplica (linha %d)\n", -n);
        return;
    }
    for (int k = 0; k < n; k++) {
        printf("%s%s", novo[k], k < n - 1 ? ", " : "\n");
    }
}

int main(void) {
    const char *patch[] = {"  arroz", "  feijão", "+ açúcar", "  café",
                           "- leite", "+ leite sem lactose", "  pão",
                           "  banana", "- sabão"};
    const char *v1[] = {"arroz", "feijão", "café", "leite", "pão", "banana",
                        "sabão"};
    const char *outra[] = {"arroz", "feijão", "chá", "leite", "pão", "banana",
                           "sabão"};

    testa("v1", v1, 7, patch, 9);
    testa("outra lista", outra, 7, patch, 9);
    return 0;
}
