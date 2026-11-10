// Lista · Módulo 08 · Tipos compostos
// Exercício P0824 · ★★★ · Matriz esparsa vezes vetor
//
// A rede de distribuição de água de um bairro tem 6 reservatórios, e a
// matriz A diz quanto (em mil litros) cada reservatório j manda para o
// ponto i. Quase tudo é zero, então A é guardada só pelos termos não nulos:
//
//   typedef struct { int l, c; double v; } Termo;
//
//   Termo a[7] = {{0, 0, 2.0}, {0, 3, 1.5}, {1, 1, 4.0}, {2, 5, 0.5},
//                 {3, 0, 1.0}, {3, 2, 3.0}, {5, 4, 2.5}};
//
// Escreva void mult(const Termo *t, int k, const double *x, double *y,
// int linhas), que calcula y = A x passando UMA vez pelos k termos (sem
// montar a matriz 6x6): cada termo (l, c, v) soma v * x[c] em y[l]. Com o
// vetor x de horas de bomba ligada abaixo, mostre y, quantas multiplicações
// foram feitas e quantas a matriz cheia faria. Depois calcule a transposta
// (troque l e c de cada termo) e mostre Aᵀ x:
//
//   double x[6] = {3, 1, 2, 4, 2, 6};
//
//   Saída esperada:
//   A x = 12.0 4.0 3.0 9.0 0.0 5.0
//   Multiplicações: 7 (a matriz cheia faria 36)
//   At x = 10.0 4.0 12.0 4.5 15.0 1.0
//
// Dicas:
// 1. Zere y antes: for (int i = 0; i < linhas; i++) y[i] = 0;
// 2. Depois: for (int p = 0; p < k; p++) y[t[p].l] += t[p].v * x[t[p].c];
// 3. Matriz cheia: 6 x 6 = 36 multiplicações; esparsa: só k = 7.
// 4. Na transposta, monte um Termo tt[7] com tt[p].l = a[p].c e tt[p].c =
//    a[p].l. A ordem dos termos não importa para a multiplicação.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

typedef struct {
    int l, c;
    double v;
} Termo;

int main(void) {
    Termo a[7] = {{0, 0, 2.0}, {0, 3, 1.5}, {1, 1, 4.0}, {2, 5, 0.5},
                  {3, 0, 1.0}, {3, 2, 3.0}, {5, 4, 2.5}};
    double x[6] = {3, 1, 2, 4, 2, 6};
    (void) a, (void) x; // apague esta linha quando escrever

    return 0;
}
