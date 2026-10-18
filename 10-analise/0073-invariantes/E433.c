// 0073 · Invariantes de laço e corretude
// Exercício E433 · ★☆☆
//
// Complete o main com os quatro laços abaixo. Em cada um, ponha um assert
// com o invariante logo no começo do corpo e outro depois do laço (o
// término). As funções que conferem os invariantes já estão prontas. Use os
// dados do main.
//
//   a) s = 0;  for (i = 0; i < n; i++)  s = s + gastos[i];
//   b) c = 0;  for (i = 0; i < n; i++)  if (notas[i] >= 6) c++;
//   c) p = 1;  for (k = 0; k < e; k++)  p = p * 2;
//   d) k = n - 1;  while (k >= 0 && v[k] != x)  k--;
//
//   Saída esperada:
//   a) gastos: R$ 120
//   b) aprovados: 3
//   c) 2 elevado a 10: 1024
//   d) último 8 na posição 3
//
// Dicas:
// 1. Pergunte: "o que o laço já sabe sobre a parte que ele já viu?". Com
//    i = 0, o pedaço v[0..-1] está vazio: a soma de nada é 0.
// 2. a) assert(s == soma_ate(gastos, i)); depois do laço, troque i por n.
// 3. d) anda de trás para frente: a parte já vista fica à direita de k.
//    assert(nao_esta(v, k + 1, n, x)); depois do laço,
//    assert(k == -1 || v[k] == x).
// 4. Resposta esperada: a saída acima. Invariantes: a) s é a soma de
//    gastos[0..i-1]; b) c conta as notas >= 6 de notas[0..i-1]; c) p é 2
//    elevado a k; d) x não está em v[k+1..n-1].
//
// Escreva sua resposta abaixo (complete o main):

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

// Soma de v[0..i-1].
int soma_ate(const int v[], int i) {
    int s = 0;
    for (int k = 0; k < i; k++) {
        s += v[k];
    }
    return s;
}

// Quantos de v[0..i-1] são >= 6.
int aprovados_ate(const int v[], int i) {
    int c = 0;
    for (int k = 0; k < i; k++) {
        if (v[k] >= 6) {
            c++;
        }
    }
    return c;
}

// 2 elevado a k.
int potencia_de_2(int k) {
    int p = 1;
    for (int j = 0; j < k; j++) {
        p *= 2;
    }
    return p;
}

// true se x não aparece em v[ini..fim-1].
bool nao_esta(const int v[], int ini, int fim, int x) {
    for (int j = ini; j < fim; j++) {
        if (v[j] == x) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int gastos[4] = {20, 35, 15, 50};
    int notas[5] = {7, 4, 9, 6, 5};
    int e = 10;
    int v[5] = {3, 8, 5, 8, 1};
    int x = 8;

    // TODO: os quatro laços, com os asserts e os printf
    (void)gastos;
    (void)notas;
    (void)e;
    (void)v;
    (void)x;
    return 0;
}
