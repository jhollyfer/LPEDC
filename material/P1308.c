// Lista · Módulo 13 · Busca e ordenação
// Exercício P1308 · ★☆☆ · As capitais mais quentes primeiro
//
// As máximas do dia em sete capitais foram 34, 29, 38, 22, 31, 36 e 27 graus.
// O programa abaixo já ordena em ordem crescente com qsort. Estenda: escreva
// a função decrescente (use a crescente, trocando a ordem dos argumentos),
// ordene de novo do maior para o menor e mostre as 3 mais quentes.
//
//   Saída esperada:
//   crescente: 22 27 29 31 34 36 38
//   decrescente: 38 36 34 31 29 27 22
//   as 3 mais quentes: 38 36 34
//
// Dicas:
// 1. A compara recebe const void *; decrescente(a, b) pode só devolver
//    crescente(b, a).
// 2. A crescente usa (x > y) - (x < y) em vez de x - y: a subtração pode
//    estourar o int com valores grandes.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (estenda o programa):

#include <stdio.h>
#include <stdlib.h>

int crescente(const void *a, const void *b) {
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y);
}

void mostra(const char *rotulo, const int v[], int n) {
    printf("%s:", rotulo);
    for (int i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
    printf("\n");
}

int main(void) {
    int maximas[] = {34, 29, 38, 22, 31, 36, 27};
    int n = 7;

    qsort(maximas, n, sizeof maximas[0], crescente);
    mostra("crescente", maximas, n);
    return 0;
}
