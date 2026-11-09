// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2325 · ★★★ · Quantas ordens tem a reforma

#include <stdio.h>

#define MAXN 12

int n;
int pred[MAXN]; // pred[v]: bits das tarefas que precisam vir antes de v
long long jeitos[1 << MAXN];

// backtracking (assunto 0127): monta as ordens uma a uma
long long enumera(int feitas) {
    if (feitas == (1 << n) - 1) return 1;
    long long total = 0;
    for (int v = 0; v < n; v++)
        if (!(feitas >> v & 1) && (pred[v] & ~feitas) == 0) total += enumera(feitas | 1 << v);
    return total;
}

// programação dinâmica: jeitos[S] = ordens possíveis para fazer o conjunto S primeiro
long long conta_pd(void) {
    for (int s = 0; s < 1 << n; s++) jeitos[s] = 0;
    jeitos[0] = 1;
    for (int s = 0; s < 1 << n; s++) {
        if (jeitos[s] == 0) continue;
        for (int v = 0; v < n; v++)
            if (!(s >> v & 1) && (pred[v] & ~s) == 0) jeitos[s | 1 << v] += jeitos[s];
    }
    return jeitos[(1 << n) - 1];
}

void regras(int pares[][2], int m) {
    for (int v = 0; v < MAXN; v++) pred[v] = 0;
    for (int k = 0; k < m; k++) pred[pares[k][1]] |= 1 << pares[k][0];
}

int main(void) {
    // banheiro: 0 quebrar, 1 hidráulica, 2 elétrica, 3 contrapiso, 4 azulejo, 5 louças
    int banheiro[][2] = {{0, 1}, {0, 2}, {1, 3}, {3, 4}, {2, 4}, {4, 5}};
    n = 6;
    regras(banheiro, 6);
    printf("Banheiro (6 tarefas): backtracking %lld, PD %lld\n", enumera(0), conta_pd());

    // casa inteira: 12 tarefas
    int casa[][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 4}, {2, 4}, {3, 5}, {4, 6},
                     {5, 6}, {6, 7}, {6, 8}, {7, 9}, {8, 10}, {9, 11}, {10, 11}};
    n = 12;
    regras(casa, 14);
    printf("Casa (12 tarefas): backtracking %lld, PD %lld\n", enumera(0), conta_pd());

    // sem regra nenhuma: 12! ordens
    n = 12;
    regras(casa, 0);
    printf("Sem regras (12 tarefas): PD %lld\n", conta_pd());
    return 0;
}
