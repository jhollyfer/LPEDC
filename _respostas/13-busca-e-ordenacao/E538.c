// 0090 · Busca binária
// Exercício E538 · ★★☆

#include <stdio.h>
#include <string.h>

int busca_nome(const char *v[], int n, const char *nome, int *voltas) {
    int ini = 0, fim = n - 1;
    *voltas = 0;
    while (ini <= fim) {
        int meio = ini + (fim - ini) / 2;
        (*voltas)++;
        int c = strcmp(v[meio], nome);  // chama uma vez e guarda
        if (c == 0) {
            return meio;
        }
        if (c < 0) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main(void) {
    const char *capitais[] = {"Aracaju", "Belém", "Boa Vista", "Cuiabá",
                              "Curitiba", "Florianópolis", "Fortaleza", "Goiânia",
                              "Maceió", "Manaus", "Natal", "Recife",
                              "Salvador", "São Paulo", "Teresina", "Vitória"};
    int n = 16;
    const char *procuradas[] = {"Natal", "Palmas"};
    int voltas;

    for (int k = 0; k < 2; k++) {
        int pos = busca_nome(capitais, n, procuradas[k], &voltas);
        printf("%s: posição %d (%d voltas)\n", procuradas[k], pos, voltas);
    }
    return 0;
}
