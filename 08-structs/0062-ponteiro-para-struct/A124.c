// A124 · O preço da cópia

#include <stdio.h>

typedef struct {
    char placa[8];
    double leituras[1000]; // velocidades registradas pelo radar
    int n;
} Radar;

// por valor: a função recebe uma CÓPIA dos 8016 bytes
void zerar_copia(Radar r) {
    r.n = 0; // zera a cópia; o original não muda
    printf("  dentro de zerar_copia: sizeof r = %zu\n", sizeof r);
}

// por ponteiro: a função recebe só um endereço (8 bytes)
void zerar(Radar *r) {
    r->n = 0;
    printf("  dentro de zerar: sizeof r = %zu\n", sizeof r);
}

// const: só lê; o compilador barra qualquer tentativa de alterar
double maior(const Radar *r) {
    double m = r->leituras[0];
    for (int i = 1; i < r->n; i++) {
        if (r->leituras[i] > m) {
            m = r->leituras[i];
        }
    }
    return m;
}

int main(void) {
    Radar r = {"ABC1D23", {62.5, 71.0, 58.3}, 3}; // o resto das leituras vira 0

    printf("Maior velocidade: %.1f km/h\n", maior(&r));
    zerar_copia(r);
    printf("Depois de zerar_copia: n = %d\n", r.n);
    zerar(&r);
    printf("Depois de zerar: n = %d\n", r.n);
    return 0;
}
// Saída:
// Maior velocidade: 71.0 km/h
//   dentro de zerar_copia: sizeof r = 8016
// Depois de zerar_copia: n = 3
//   dentro de zerar: sizeof r = 8
// Depois de zerar: n = 0
