// A205 · Empate na chegada: o heapsort não é estável

#include <stdio.h>

typedef struct {
    const char *nome;
    int tempo; // minutos
} Corredor;

void troca(Corredor *a, Corredor *b) {
    Corredor t = *a;
    *a = *b;
    *b = t;
}

// o mesmo desce do texto, comparando só o campo tempo
void desce(Corredor v[], int n, int i) {
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && v[f + 1].tempo > v[f].tempo) {
            f++;
        }
        if (v[i].tempo >= v[f].tempo) {
            break;
        }
        troca(&v[i], &v[f]);
        i = f;
    }
}

void heapsort(Corredor v[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        desce(v, n, i);
    }
    for (int fim = n - 1; fim > 0; fim--) {
        troca(&v[0], &v[fim]);
        desce(v, fim, 0);
    }
}

void mostra(const char *rotulo, const Corredor v[], int n) {
    printf("%s", rotulo);
    for (int i = 0; i < n; i++) {
        printf(" %s %d", v[i].nome, v[i].tempo);
        printf(i < n - 1 ? "," : "\n");
    }
}

int main(void) {
    // na ordem de chegada: Ana chegou antes de Caio, Bia antes de Duda
    Corredor v[] = {{"Ana", 40}, {"Bia", 25}, {"Caio", 40}, {"Duda", 25}, {"Edu", 30}};
    int n = 5;

    mostra("Chegada:", v, n);
    heapsort(v, n);
    mostra("Ordem:  ", v, n);
    // os tempos estão em ordem, mas os empatados trocaram de lugar:
    // Duda passou na frente de Bia e Caio na frente de Ana
    return 0;
}
// Saída:
// Chegada: Ana 40, Bia 25, Caio 40, Duda 25, Edu 30
// Ordem:   Duda 25, Bia 25, Edu 30, Caio 40, Ana 40
