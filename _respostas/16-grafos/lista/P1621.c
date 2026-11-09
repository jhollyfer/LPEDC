// Lista · Módulo 16 · Grafos
// Exercício P1621 · ★★★ · As duas jarras do vendedor de caldo de cana

#include <stdio.h>

#define MAXE (11 * 11) // jarras de até 10 litros

const char *nomes_op[] = {"enche A", "enche B", "esvazia A", "esvazia B", "A -> B", "B -> A"};

int min(int x, int y) { return x < y ? x : y; }

// aplica a operação k ao estado (a, b) e devolve o novo (a, b) em *na, *nb
void aplica(int k, int A, int B, int a, int b, int *na, int *nb) {
    int x;
    *na = a;
    *nb = b;
    switch (k) {
    case 0: *na = A; break;
    case 1: *nb = B; break;
    case 2: *na = 0; break;
    case 3: *nb = 0; break;
    case 4: x = min(a, B - b); *na = a - x; *nb = b + x; break;
    default: x = min(b, A - a); *na = a + x; *nb = b - x; break;
    }
}

void jarras(int A, int B, int alvo) {
    int dist[MAXE], pai[MAXE], op[MAXE], fila[MAXE], ini = 0, fim = 0;
    int total = (A + 1) * (B + 1), achado = -1;
    for (int e = 0; e < total; e++) dist[e] = -1;
    dist[0] = 0; // (0, 0)
    pai[0] = -1;
    fila[fim++] = 0;
    while (ini < fim && achado == -1) {
        int u = fila[ini++], a = u / (B + 1), b = u % (B + 1);
        if (a == alvo || b == alvo) {
            achado = u;
            break;
        }
        for (int k = 0; k < 6; k++) {
            int na, nb;
            aplica(k, A, B, a, b, &na, &nb);
            int v = na * (B + 1) + nb;
            if (dist[v] != -1) continue;
            dist[v] = dist[u] + 1;
            pai[v] = u;
            op[v] = k;
            fila[fim++] = v;
        }
    }
    printf("Jarras de %d L e %d L, alvo %d L: ", A, B, alvo);
    if (achado == -1) {
        printf("impossível (%d estados descobertos)\n", fim);
        return;
    }
    printf("%d passos (%d estados descobertos)\n", dist[achado], fim);
    int passos[MAXE], n = 0;
    for (int e = achado; pai[e] != -1; e = pai[e]) passos[n++] = e;
    for (int i = n - 1; i >= 0; i--) {
        int e = passos[i];
        printf("  %-9s -> (%d, %d)\n", nomes_op[op[e]], e / (B + 1), e % (B + 1));
    }
}

int main(void) {
    jarras(3, 5, 4);
    jarras(4, 6, 3);
    return 0;
}
