// 0133 · Algoritmos gulosos
// Exercício E797 · ★★★

#include <stdio.h>

// moedas em ordem decrescente, a última é 1
int guloso(const int m[], int k, int valor) {
    int q = 0;
    for (int i = 0; i < k; i++) {
        q += valor / m[i];
        valor %= m[i];
    }
    return q;
}

// mínimo de moedas usando m[i..k-1]: testa todas as quantidades da moeda i
int otimo(const int m[], int k, int i, int valor) {
    if (i == k - 1) {
        return valor;                 // a última moeda é 1: resolve sozinha
    }
    int melhor = valor;               // pior caso: tudo em moedas de 1
    for (int c = 0; c * m[i] <= valor; c++) {
        int q = c + otimo(m, k, i + 1, valor - c * m[i]);
        if (q < melhor) {
            melhor = q;
        }
    }
    return melhor;
}

void testa(const char *nome, const int m[], int k, int limite) {
    for (int v = 1; v <= limite; v++) {
        int g = guloso(m, k, v);
        int o = otimo(m, k, 0, v);
        if (g != o) {
            printf("%s: falha em %d (guloso %d, ótimo %d)\n", nome, v, g, o);
            return;
        }
    }
    printf("%s: o guloso acertou de 1 a %d\n", nome, limite);
}

int main(void) {
    int real[] = {25, 10, 5, 1};
    int fichas[] = {4, 3, 1};
    int selos[] = {10, 7, 1};
    int bonus[] = {12, 5, 1};
    testa("{25, 10, 5, 1}", real, 4, 100);
    testa("{4, 3, 1}", fichas, 3, 100);
    testa("{10, 7, 1}", selos, 3, 100);
    testa("{12, 5, 1}", bonus, 3, 100);
    return 0;
}
