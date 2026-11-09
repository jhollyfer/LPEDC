// Lista · Módulo 15 · Tabelas hash
// Exercício P1530 · ★★★ · O carro que passou duas vezes mais rápido

#include <stdio.h>
#include <string.h>

#define M 17

typedef struct {
    char placa[8]; // "" = livre
    int ultima;    // posição da última passagem
} Registro;

unsigned long long djb2(const char *s) {
    unsigned long long h = 5381;
    for (; *s != '\0'; s++) {
        h = h * 33 + (unsigned char)*s;
    }
    return h;
}

// devolve o registro da placa, criando se não existir
Registro *registro(Registro t[], const char *placa, int *nova) {
    int pos = (int)(djb2(placa) % M);
    while (t[pos].placa[0] != '\0' && strcmp(t[pos].placa, placa) != 0) {
        pos = (pos + 1) % M;
    }
    *nova = t[pos].placa[0] == '\0';
    if (*nova) {
        snprintf(t[pos].placa, sizeof t[pos].placa, "%s", placa);
    }
    return &t[pos];
}

int main(void) {
    const char *radar[] = {"ABC1D23", "QWE4R56", "ZXC7V89", "ABC1D23", "JKL0M12",
                           "QWE4R56", "POI3U45", "ZXC7V89", "JKL0M12", "QWE4R56"};
    int n = 10;
    Registro t[M] = {{"", 0}};
    int melhor = n + 1;
    const char *placa_melhor = NULL;
    int de = -1, ate = -1;

    for (int i = 0; i < n; i++) {
        int nova;
        Registro *r = registro(t, radar[i], &nova);
        if (!nova) {
            int dist = i - r->ultima;
            printf("%s voltou (distância %d)\n", radar[i], dist);
            if (dist < melhor) {
                melhor = dist;
                placa_melhor = radar[i];
                de = r->ultima;
                ate = i;
            }
        }
        r->ultima = i;
    }
    if (placa_melhor != NULL) {
        printf("menor intervalo: %s, passagens %d e %d (distância %d)\n", placa_melhor, de + 1, ate + 1, melhor);
    }
    return 0;
}
