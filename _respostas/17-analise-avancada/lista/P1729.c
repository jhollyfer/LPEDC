// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1729 · ★★★ · A roda do amigo-secreto: simular ou recorrer?

#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa {
    int num;
    struct Pessoa *prox;
} Pessoa;

long passos, chamadas;

int simula(int n) {
    Pessoa *primeiro = NULL, *ultimo = NULL;
    for (int i = 1; i <= n; i++) {
        Pessoa *p = malloc(sizeof *p);
        if (p == NULL) exit(1);
        p->num = i;
        p->prox = NULL;
        if (ultimo) ultimo->prox = p;
        else primeiro = p;
        ultimo = p;
    }
    ultimo->prox = primeiro; // fecha a roda
    Pessoa *atual = primeiro;
    while (atual->prox != atual) {
        Pessoa *alvo = atual->prox; // a vizinha sai
        atual->prox = alvo->prox;
        free(alvo);
        atual = atual->prox; // a vez passa para a seguinte
        passos++;
    }
    int sobra = atual->num;
    free(atual);
    return sobra;
}

int josephus(int n) {
    chamadas++;
    if (n == 1) return 1;
    int j = josephus(n / 2);
    return n % 2 == 0 ? 2 * j - 1 : 2 * j + 1;
}

int fechada(int n) {
    int p = 1;
    while (2 * p <= n) p *= 2; // maior potência de 2 que cabe em n
    return 2 * (n - p) + 1;
}

int main(void) {
    int ns[] = {5, 10, 41, 1000, 100000};
    printf("     n  simulação  passos  recursão  chamadas  fórmula\n");
    for (int k = 0; k < 5; k++) {
        int n = ns[k];
        passos = chamadas = 0;
        int s = simula(n);
        int r = josephus(n);
        printf("%6d %10d %7ld %9d %9ld %8d\n", n, s, passos, r, chamadas, fechada(n));
    }
    return 0;
}
