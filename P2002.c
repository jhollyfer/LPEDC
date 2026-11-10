// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2002 · ★☆☆ · Maior e menor temperatura, dividindo ao meio
//
// A estação de Manaus registrou as máximas de 8 dias: 31 34 29 36 33 30 35
// 32 graus. Complete a função recursiva extremos(v, ini, fim, &menor,
// &maior), que acha os DOIS de uma vez por divisão e conquista: um
// elemento só é menor e maior ao mesmo tempo (0 comparações); dois
// elementos custam 1 comparação; com mais, divida ao meio, resolva cada
// metade e junte com 2 comparações (menor com menor, maior com maior).
// Conte as comparações entre temperaturas.
//
//   Saída esperada:
//   Menor: 29 graus
//   Maior: 36 graus
//   Comparações: 10
//
// Dicas:
// 1. No caso de dois elementos: comps++; if (v[ini] < v[fim]) {...} else
//    {...}.
// 2. Para juntar: chame para [ini, meio] e [meio + 1, fim] com variáveis
//    locais e faça dois comps++.
// 3. Resposta esperada: menor 29, maior 36 e 10 comparações, que é 3n/2 -
//    2 para n = 8. Achar os dois com dois laços separados custaria 2(n - 1)
//    = 14.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

#define N 8

int comps = 0;

void extremos(const int v[], int ini, int fim, int *menor, int *maior) {
    (void)v;
    (void)ini;
    (void)fim;
    *menor = *maior = 0;
    // COMPLETE AQUI
}

int main(void) {
    const int temp[N] = {31, 34, 29, 36, 33, 30, 35, 32};
    int menor, maior;
    extremos(temp, 0, N - 1, &menor, &maior);
    printf("Menor: %d graus\n", menor);
    printf("Maior: %d graus\n", maior);
    printf("Comparações: %d\n", comps);
    return 0;
}
