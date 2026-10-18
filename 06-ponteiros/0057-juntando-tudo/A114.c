// A114 · O caixa eletrônico de comandos

#include <stdio.h>
#include <string.h>

int deposita(int *saldo, int valor) {
    *saldo += valor;
    return 1;
}

int saca(int *saldo, int valor) {
    if (valor > *saldo) {
        return 0; // negado: o saldo não muda
    }
    *saldo -= valor;
    return 1;
}

// tabela de comandos: o nome na posição i corresponde à função na posição i
const char *nomes[] = {"deposito", "saque"};
int (*acoes[])(int *, int) = {deposita, saca};

int indice_do(const char *comando) {
    for (int i = 0; i < 2; i++) {
        if (strcmp(nomes[i], comando) == 0) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    int saldo = 100;
    const char *roteiro[] = {"deposito", "saque", "pix", "saque"};
    int valores[] = {200, 50, 30, 500};

    for (int i = 0; i < 4; i++) {
        int k = indice_do(roteiro[i]);
        if (k < 0) {
            printf("%-9s %4d: comando desconhecido\n", roteiro[i], valores[i]);
        } else if (acoes[k](&saldo, valores[i])) { // chama pela tabela
            printf("%-9s %4d: ok, saldo %d\n", roteiro[i], valores[i], saldo);
        } else {
            printf("%-9s %4d: negado, saldo %d\n", roteiro[i], valores[i], saldo);
        }
    }
    return 0;
}
// Saída:
// deposito   200: ok, saldo 300
// saque       50: ok, saldo 250
// pix         30: comando desconhecido
// saque      500: negado, saldo 250
