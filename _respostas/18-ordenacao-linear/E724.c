// 0121 · Radix sort
// Exercício E724 · ★★☆

#include <stdio.h>

typedef struct {
    int dia, mes, ano;
} Data;

// a "casa" da vez: 0 = dia (1 a 31), 1 = mês (1 a 12), 2 = ano (2020 a 2029)
int chave(Data d, int campo) {
    if (campo == 0) {
        return d.dia;
    }
    if (campo == 1) {
        return d.mes;
    }
    return d.ano - 2020;
}

// counting sort estável pelo campo; 32 contadores servem para os três
void passada(Data v[], Data aux[], int n, int campo) {
    int c[32] = {0};
    for (int i = 0; i < n; i++) {
        c[chave(v[i], campo)]++;
    }
    for (int x = 1; x < 32; x++) {
        c[x] += c[x - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        aux[--c[chave(v[i], campo)]] = v[i];
    }
    for (int i = 0; i < n; i++) {
        v[i] = aux[i];
    }
}

void mostra(const char *rotulo, const Data v[], int n) {
    printf("%s", rotulo);
    for (int i = 0; i < n; i++) {
        printf(" %02d/%02d/%d", v[i].dia, v[i].mes, v[i].ano);
    }
    printf("\n");
}

int main(void) {
    Data boletos[] = {{15, 3, 2025}, {5, 11, 2024}, {15, 1, 2025}, {28, 2, 2024},
                      {5, 3, 2025}, {10, 11, 2024}, {28, 1, 2025}};
    Data aux[7];
    int n = 7;
    const char *rotulos[] = {"dia:   ", "mês:   ", "ano:   "};

    mostra("início:", boletos, n);
    for (int campo = 0; campo < 3; campo++) { // do menos para o mais importante
        passada(boletos, aux, n, campo);
        mostra(rotulos[campo], boletos, n);
    }
    return 0;
}
