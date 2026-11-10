// A335 · Quanto a recursão empilha

#include <stdio.h>

int prof = 0;      // frames vivos agora
int prof_max = 0;  // o máximo que já ficou vivo ao mesmo tempo

void entra(void) {
    prof++;
    if (prof > prof_max) {
        prof_max = prof;
    }
}

// soma dos n primeiros consumos do mês: T(n) = T(n-1) + 1
long soma_rec(const int v[], int n) {
    entra();
    long r = (n == 0) ? 0 : v[n - 1] + soma_rec(v, n - 1);
    prof--;
    return r;
}

// busca binária: cada chamada joga fora metade
int busca_rec(const int v[], int ini, int fim, int x) {
    entra();
    int r;
    if (ini >= fim) {
        r = -1;
    } else {
        int meio = ini + (fim - ini) / 2;
        if (v[meio] == x) {
            r = meio;
        } else if (x < v[meio]) {
            r = busca_rec(v, ini, meio, x);
        } else {
            r = busca_rec(v, meio + 1, fim, x);
        }
    }
    prof--;
    return r;
}

int main(void) {
    static int consumo[100000];
    for (int i = 0; i < 100000; i++) {
        consumo[i] = 2 * i;              // ordenado, para a busca binária
    }
    printf("     n  frames soma  frames busca\n");
    for (int n = 10; n <= 100000; n *= 10) {
        prof_max = 0;
        soma_rec(consumo, n);
        int f_soma = prof_max;
        prof_max = 0;
        busca_rec(consumo, 0, n, -1);    // não está: desce até o fim
        printf("%6d %12d %13d\n", n, f_soma, prof_max);
    }
    // soma: n + 1 frames, Θ(n) de pilha. busca: uns log2(n) + 1, Θ(log n).
    return 0;
}
// Saída:
//      n  frames soma  frames busca
//     10           11             5
//    100          101             8
//   1000         1001            11
//  10000        10001            15
// 100000       100001            18
