// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2828 · ★★★ · A tabela do campeonato em duas passadas

#include <stdio.h>

typedef struct {
    char nome[12];
    int pontos, saldo;
} Time;

// pigeonhole estável, da casa mais alta para a mais baixa
void passada(Time *v, int n, int pelo_saldo) {
    Time saida[16];
    int k = 0;
    int topo = pelo_saldo ? 20 : 30;
    for (int casa = topo; casa >= 0; casa--) {
        for (int i = 0; i < n; i++) {
            int c = pelo_saldo ? v[i].saldo + 10 : v[i].pontos;
            if (c == casa) {
                saida[k++] = v[i];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        v[i] = saida[i];
    }
}

int main(void) {
    Time v[] = {{"Aleixo", 13, 4},  {"Betânia", 16, -1}, {"Coroado", 13, 4}, {"Dom Pedro", 16, 6},
                {"Educandos", 9, -3}, {"Flores", 13, -2}, {"Glória", 16, -1}};
    passada(v, 7, 1);
    passada(v, 7, 0);
    for (int i = 0; i < 7; i++) {
        printf("%d. %s: %d pontos, saldo %+d\n", i + 1, v[i].nome, v[i].pontos, v[i].saldo);
    }
    return 0;
}
