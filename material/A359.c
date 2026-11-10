// A359 · A tabela do campeonato com qsort

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[16];
    int pontos, vitorias, saldo, gols_pro;
} Time;

// chave composta: pontos, vitórias, saldo e gols pró (do maior para o
// menor) e, se empatar em tudo, o nome em ordem alfabética
int compara(const void *a, const void *b) {
    const Time *x = a;
    const Time *y = b;
    if (x->pontos != y->pontos) {
        return y->pontos - x->pontos; // maior primeiro: y - x
    }
    if (x->vitorias != y->vitorias) {
        return y->vitorias - x->vitorias;
    }
    if (x->saldo != y->saldo) {
        return y->saldo - x->saldo;
    }
    if (x->gols_pro != y->gols_pro) {
        return y->gols_pro - x->gols_pro;
    }
    return strcmp(x->nome, y->nome); // o desempate final deixa a ordem total
}

int main(void) {
    Time t[] = {
        {"Ipiranga", 20, 6, 8, 19},  {"Aleixo", 23, 7, 10, 22}, {"Coroado", 20, 6, 8, 21},
        {"Flores", 20, 5, 12, 25},   {"Japiim", 23, 7, 10, 22}, {"Educandos", 17, 5, 1, 15},
    };
    int n = 6;
    qsort(t, (size_t)n, sizeof(Time), compara);
    printf("   %-10s %3s %3s %4s %3s\n", "time", "P", "V", "SG", "GP");
    for (int i = 0; i < n; i++) {
        printf("%d. %-10s %3d %3d %4d %3d\n", i + 1, t[i].nome, t[i].pontos, t[i].vitorias,
               t[i].saldo, t[i].gols_pro);
    }
    return 0;
}
// Saída:
//    time         P   V   SG  GP
// 1. Aleixo      23   7   10  22
// 2. Japiim      23   7   10  22
// 3. Coroado     20   6    8  21
// 4. Ipiranga    20   6    8  19
// 5. Flores      20   5   12  25
// 6. Educandos   17   5    1  15
