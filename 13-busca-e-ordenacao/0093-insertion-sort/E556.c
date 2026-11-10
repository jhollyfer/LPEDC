// 0093 · Insertion sort
// Exercício E556 · ★★☆
//
// Os pedidos de uma lanchonete chegam com o tempo de preparo, em minutos:
// 6, 3, 8, 3, 1. O programa abaixo ordena com insertion sort e mostra cada
// encaixe. Transforme-o:
//
// a) leve a ordenação para int ordena(int v[], int n, bool maior_ou_igual,
//    bool mostrar), que devolve o total de deslocamentos. Com maior_ou_igual
//    falso, o while usa preparo[i] > x (como agora); com verdadeiro, usa >=;
// b) na linha de cada encaixe, mostre também x e a posição onde ele entrou;
// c) no main, ordene o vetor com > (mostrando os encaixes) e uma cópia dele
//    com >= (sem mostrar), e imprima os dois totais.
//
//   Saída esperada:
//   j = 1 (x = 3 entrou na posição 0): 3 6 8 3 1 (deslocou 1)
//   j = 2 (x = 8 entrou na posição 2): 3 6 8 3 1 (deslocou 0)
//   j = 3 (x = 3 entrou na posição 1): 3 3 6 8 1 (deslocou 2)
//   j = 4 (x = 1 entrou na posição 0): 1 3 3 6 8 (deslocou 4)
//   total com >: 7
//   total com >=: 8
//
// Escreva sua resposta abaixo (modifique o código):

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int preparo[] = {6, 3, 8, 3, 1};
    int n = 5, total = 0;

    for (int j = 1; j < n; j++) {
        int x = preparo[j];
        int i = j - 1;
        int d = 0;
        while (i >= 0 && preparo[i] > x) {
            preparo[i + 1] = preparo[i];
            i--;
            d++;
        }
        preparo[i + 1] = x;
        total += d;
        printf("j = %d:", j);
        for (int k = 0; k < n; k++) {
            printf(" %d", preparo[k]);
        }
        printf(" (deslocou %d)\n", d);
    }
    printf("total: %d\n", total);
    return 0;
}
