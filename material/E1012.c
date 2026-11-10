// 0169 · Juntando tudo: passos e bytes conferidos
// Exercício E1012 · ★★☆
//
// Três funções misteriosas estão no esqueleto. Declare um contador global
// de passos e acrescente passos++ ao laço mais interno de cada uma. Rode
// cada função com n = 1024 e n = 2048 e escreva const char *classe(double
// razao), que devolve um texto conforme a razão p(2048) / p(1024):
// menor que 1.5: "constante ou log n"; menor que 2.1: "n";
// menor que 3.0: "n log n"; menor que 5.0: "n²"; senão: "pior que n²".
//
//   Saída esperada:
//   a:   10240 ->   22528, razão 2.20, classe n log n
//   b:  261632 -> 1047552, razão 4.00, classe n²
//   c:    2047 ->    4095, razão 2.00, classe n
//
// Escreva sua resposta abaixo:

#include <stdio.h>

void misterio_a(int n) {
    for (int i = 1; i < n; i *= 2) {
        for (int j = 0; j < n; j++) {
        }
    }
}

void misterio_b(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i / 2; j++) {
        }
    }
}

void misterio_c(int n) {
    for (int i = n; i > 0; i /= 2) {
        for (int j = 0; j < i; j++) {
        }
    }
}

int main(void) {

    return 0;
}
