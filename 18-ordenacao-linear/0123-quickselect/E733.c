// 0123 · Quickselect
// Exercício E733 · ★☆☆
//
// A escola quer um resumo das notas de redação do simulado: a menor, a
// segunda menor, a mediana, a segunda maior e a maior, todas com o
// quickselect do texto (já está no arquivo). Só que o quickselect bagunça o
// vetor, e a escola quer a lista na ordem original. Escreva
// int seleciona_copia(const int v[], int n, int k), que copia v para um
// vetor local e roda o quickselect na cópia, e use para mostrar o resumo.
// No fim, mostre notas[0] para provar que o vetor não mudou.
//
//   Saída esperada:
//   menor:       380
//   2ª menor:    480
//   mediana:     680
//   2ª maior:    860
//   maior:       920
//   primeira do vetor continua: 720
//
// Dicas:
// 1. Um int copia[MAX]; com MAX 100 basta para este programa.
// 2. As posições contam de 0: a menor é k = 0, a segunda menor é k = 1, a
//    maior é k = n - 1 e a segunda maior, k = n - 2.
// 3. Com n = 11, a mediana está em k = n / 2 = 5.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define MAX 100

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int separa(int v[], int p, int r) {
    int pivo = v[r], j = p;
    for (int k = p; k < r; k++) {
        if (v[k] <= pivo) {
            troca(&v[j], &v[k]);
            j++;
        }
    }
    troca(&v[j], &v[r]);
    return j;
}

int quickselect(int v[], int n, int k) {
    int p = 0, r = n - 1;
    while (p < r) {
        int j = separa(v, p, r);
        if (j == k) {
            return v[j];
        }
        if (k < j) {
            r = j - 1;
        } else {
            p = j + 1;
        }
    }
    return v[p];
}

int main(void) {
    // redação do simulado: notas de 11 alunos
    int notas[] = {720, 480, 860, 640, 920, 560, 700, 380, 800, 600, 680};
    int n = 11;

    (void) notas; // apague estas duas linhas
    (void) n;

    return 0;
}
