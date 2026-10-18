// 0119 · Shell sort
// Exercício E710 · ★☆☆
//
// O técnico do time de vôlei quer as idades das 11 atletas em ordem. Em vez
// dos saltos de Knuth, use os saltos fixos 5, 3 e 1. O main já faz as três
// rodadas e mostra o vetor depois de cada uma: complete a função rodada,
// que faz o insertion sort entre os elementos a h casas de distância.
//
//   Saída esperada:
//   início: 31 19 27 22 35 18 24 29 20 33 26
//   h = 5: 18 19 27 20 33 26 24 29 22 35 31
//   h = 3: 18 19 22 20 29 26 24 31 27 35 33
//   h = 1: 18 19 20 22 24 26 27 29 31 33 35
//
// Dicas:
// 1. É o laço de dentro do shell_sort do texto, sem o laço dos saltos.
// 2. O i começa em h, e o j anda de h em h para trás: j >= h e v[j - h].
// 3. Com h = 5, as fileiras são 31 18 26, 19 24, 27 29, 22 20 e 35 33.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete a função rodada):

#include <stdio.h>

void mostra(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
    printf("\n");
}

// insertion sort entre os elementos que estão a h casas de distância
void rodada(int v[], int n, int h) {
    (void) v; // apague estas três linhas
    (void) n;
    (void) h;
}

int main(void) {
    int idades[] = {31, 19, 27, 22, 35, 18, 24, 29, 20, 33, 26};
    int n = 11;
    int saltos[] = {5, 3, 1};

    printf("início:");
    mostra(idades, n);
    for (int s = 0; s < 3; s++) {
        rodada(idades, n, saltos[s]);
        printf("h = %d:", saltos[s]);
        mostra(idades, n);
    }
    return 0;
}
