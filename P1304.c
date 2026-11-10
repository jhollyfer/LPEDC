// Lista · Módulo 13 · Busca e ordenação
// Exercício P1304 · ★☆☆ · Selection sort das senhas da farmácia
//
// As senhas da fila da farmácia estão bagunçadas: 27, 12, 44, 8, 31, 19.
// Complete o selection sort: em cada passada i, ache o menor de
// senhas[i..n-1] e troque com senhas[i], mas SÓ troque se o menor não estiver
// já em i. Mostre o vetor depois de cada passada e, no fim, quantas trocas
// aconteceram de verdade.
//
//   Saída esperada:
//   passada 1: 8 12 44 27 31 19
//   passada 2: 8 12 44 27 31 19
//   passada 3: 8 12 19 27 31 44
//   passada 4: 8 12 19 27 31 44
//   passada 5: 8 12 19 27 31 44
//   trocas: 2
//
// Dicas:
// 1. Guarde o ÍNDICE do menor (int menor = i), não o valor.
// 2. Conte a troca dentro do if (menor != i).
// 3. O selection sempre faz n - 1 passadas: ele não percebe que o vetor
//    ficou pronto na passada 3.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

void mostra(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
    printf("\n");
}

int main(void) {
    int senhas[] = {27, 12, 44, 8, 31, 19};
    int n = 6, trocas = 0;

    for (int i = 0; i < n - 1; i++) {
        // ache o menor de senhas[i..n-1] e troque com senhas[i]

        printf("passada %d:", i + 1);
        mostra(senhas, n);
    }
    printf("trocas: %d\n", trocas);
    return 0;
}
