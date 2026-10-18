// 0160 · Rabin-Karp
// Exercício E957 · ★★☆
//
// Quanto o tamanho do módulo pesa? O programa abaixo procura "2026" numa
// série de 48 dígitos com Q fixo em 13 e só conta as ocorrências. Estenda:
// troque o Q fixo por um parâmetro int q, conte também os falsos positivos e
// rode para q = 7, 13, 101 e 10007:
//
//   Saída esperada:
//   q =     7: 5 ocorrências,  4 falsos positivos
//   q =    13: 5 ocorrências,  3 falsos positivos
//   q =   101: 5 ocorrências,  0 falsos positivos
//   q = 10007: 5 ocorrências,  0 falsos positivos
//
// Dicas:
// 1. Toda conta com Q passa a usar q, inclusive o pot.
// 2. Falso positivo: ht == hp, mas iguais() devolve 0.
// 3. As ocorrências não mudam com q: o que muda é o trabalho jogado fora com
//    conferências inúteis. Com q pequeno, uma janela qualquer tem chance de
//    1 em q de colidir.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (mude a função e o main):

#include <stdio.h>
#include <string.h>

#define Q 13

int iguais(const char *t, const char *p, int m) {
    for (int j = 0; j < m; j++) {
        if (t[j] != p[j]) {
            return 0;
        }
    }
    return 1;
}

void rabin_karp(const char *t, const char *p) {
    int n = (int) strlen(t);
    int m = (int) strlen(p);
    int pot = 1;
    for (int j = 0; j < m - 1; j++) {
        pot = pot * 10 % Q;
    }
    int hp = 0, ht = 0;
    for (int j = 0; j < m; j++) {
        hp = (hp * 10 + (p[j] - '0')) % Q;
        ht = (ht * 10 + (t[j] - '0')) % Q;
    }
    int achados = 0;
    for (int i = 0; i <= n - m; i++) {
        if (ht == hp && iguais(t + i, p, m)) {
            achados++;
        }
        if (i < n - m) {
            ht = (ht - (t[i] - '0') * pot % Q + Q) % Q;
            ht = (ht * 10 + (t[i + m] - '0')) % Q;
        }
    }
    printf("Q = %d: %d ocorrências\n", Q, achados);
}

int main(void) {
    const char *serie = "902620261187420263355926102026738920261049582026";
    rabin_karp(serie, "2026");
    return 0;
}
