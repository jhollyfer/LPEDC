// 0119 · Shell sort
// Exercício E712 · ★★☆
//
// Um vetor está h-ORDENADO quando toda fileira de passo h (v[i], v[i + h],
// v[i + 2h], ...) está em ordem. O programa abaixo roda o shell sort num
// vetor de 40 números e, depois de cada rodada, pergunta se o vetor está
// 13-, 4- e 1-ordenado. Escreva a função esta_h_ordenado e rode.
//
//   Saída esperada:
//   início: 13-ordenado? não, 4-ordenado? não, 1-ordenado? não
//   h = 13: 13-ordenado? sim, 4-ordenado? não, 1-ordenado? não
//   h =  4: 13-ordenado? sim, 4-ordenado? sim, 1-ordenado? não
//   h =  1: 13-ordenado? sim, 4-ordenado? sim, 1-ordenado? sim
//
// Repare na coluna do 13: a rodada com h = 4 mexe no vetor, mas não desfaz o
// que a rodada h = 13 arrumou. É isso que faz cada rodada aproveitar o
// trabalho da anterior.
//
// Dicas:
// 1. Não precisa separar as fileiras: basta conferir v[i - h] <= v[i] para
//    todo i de h até n - 1.
// 2. Achou um par fora de ordem? Pode devolver false na hora.
// 3. 1-ordenado é o mesmo que ordenado.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete esta_h_ordenado):

#include <stdio.h>
#include <stdbool.h>

// toda fileira de passo h está em ordem?
bool esta_h_ordenado(const int v[], int n, int h) {
    (void) v; // apague estas três linhas
    (void) n;
    (void) h;
    return false;
}

void confere(const int v[], int n) {
    int testes[] = {13, 4, 1};
    for (int t = 0; t < 3; t++) {
        printf("%s%d-ordenado? %s", t == 0 ? " " : ", ", testes[t],
               esta_h_ordenado(v, n, testes[t]) ? "sim" : "não");
    }
    printf("\n");
}

int main(void) {
    int v[40];
    int n = 40;
    for (int i = 0; i < n; i++) {
        v[i] = (i * 17 + 5) % 40; // os números de 0 a 39, embaralhados
    }

    printf("início:");
    confere(v, n);
    int h = 1;
    while (h < n / 3) {
        h = 3 * h + 1;
    }
    for (; h >= 1; h /= 3) {
        for (int i = h; i < n; i++) {
            int x = v[i];
            int j = i;
            while (j >= h && v[j - h] > x) {
                v[j] = v[j - h];
                j -= h;
            }
            v[j] = x;
        }
        printf("h = %2d:", h);
        confere(v, n);
    }
    return 0;
}
