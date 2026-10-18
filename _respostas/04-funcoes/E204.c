// 0034 · Módulos: .h, .c e compilação separada
// Exercício E204 · ★★★
//
// No cofrinho.h de verdade iria:
//   #ifndef COFRINHO_H
//   #define COFRINHO_H
//   #include <stdbool.h>
//   void depositar(double valor);
//   bool sacar(double valor);
//   double saldo(void);
//   int operacoes(void);
//   #endif
// No cofrinho.c: #include "cofrinho.h", as duas variáveis static e os corpos.

#include <stdbool.h>
#include <stdio.h>

// cofrinho.h
void depositar(double valor);
bool sacar(double valor);
double saldo(void);
int operacoes(void);

int main(void) {
    depositar(50);
    depositar(-10);
    printf("Saque de 30.00: %s\n", sacar(30) ? "ok" : "sem saldo");
    printf("Saque de 100.00: %s\n", sacar(100) ? "ok" : "sem saldo");
    depositar(25);
    printf("Saldo: R$ %.2f\n", saldo());
    printf("Operações: %d\n", operacoes());
    return 0;
}

// cofrinho.c
static double saldo_atual = 0;
static int contador = 0;

void depositar(double valor) {
    if (valor <= 0) {
        return;
    }
    saldo_atual += valor;
    contador++;
}

bool sacar(double valor) {
    if (valor <= 0 || valor > saldo_atual) {
        return false;
    }
    saldo_atual -= valor;
    contador++;
    return true;
}

double saldo(void) {
    return saldo_atual;
}

int operacoes(void) {
    return contador;
}
