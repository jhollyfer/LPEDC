// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1012 · ★★☆ · Primos: dividir contra peneirar

#include <stdbool.h>
#include <stdio.h>

#define MAX 10000

int por_divisao(int n, long *ops) {
    int primos = 0;
    *ops = 0;
    for (int k = 2; k <= n; k++) {
        bool primo = true;
        for (int d = 2; d * d <= k; d++) {
            (*ops)++;
            if (k % d == 0) {
                primo = false;
                break;
            }
        }
        if (primo) {
            primos++;
        }
    }
    return primos;
}

int por_crivo(int n, long *ops) {
    static bool primo[MAX + 1];
    *ops = 0;
    for (int i = 0; i <= n; i++) {
        primo[i] = i >= 2;
    }
    for (int i = 2; i * i <= n; i++) {
        if (primo[i]) {
            for (int j = i * i; j <= n; j += i) {
                primo[j] = false;
                (*ops)++;
            }
        }
    }
    int cont = 0;
    for (int i = 2; i <= n; i++) {
        if (primo[i]) {
            cont++;
        }
    }
    return cont;
}

int main(void) {
    int testes[2] = {100, MAX};
    for (int t = 0; t < 2; t++) {
        long od, oc;
        int pd = por_divisao(testes[t], &od);
        int pc = por_crivo(testes[t], &oc);
        if (pd != pc) {
            printf("Os dois discordam!\n");
        }
        printf("N = %d: %d primos | divisão: %ld ops | crivo: %ld ops\n", testes[t], pd, od, oc);
    }
    return 0;
}
