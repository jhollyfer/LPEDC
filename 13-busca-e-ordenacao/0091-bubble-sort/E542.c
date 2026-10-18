// 0091 · Bubble sort
// Exercício E542 · ★☆☆
//
// A fila do caixa preferencial tem senhas fora de ordem: 9, 4, 7, 1, 5. O
// programa abaixo ordena com bubble sort (sem bandeira) e mostra o vetor no
// fim de cada passada. Melhore o programa:
//
// a) conte as trocas de CADA passada numa variável própria e mostre esse
//    número entre parênteses no fim da linha da passada;
// b) acrescente a bandeira trocou, para parar na primeira passada sem troca.
//
//   Saída esperada:
//   passada 1: 4 7 1 5 9 (4 trocas)
//   passada 2: 4 1 5 7 9 (2 trocas)
//   passada 3: 1 4 5 7 9 (1 trocas)
//   passada 4: 1 4 5 7 9 (0 trocas)
//   trocas: 7
//
// Dicas:
// 1. Declare int nesta = 0; no começo de cada passada (dentro do laço de
//    fora) e some 1 junto com trocas++.
// 2. A bandeira: bool trocou = true; antes do laço, condição
//    passada < n && trocou, e trocou = false; no começo de cada passada.
// 3. A passada 4 ainda acontece: a bandeira só descobre que acabou depois de
//    uma passada inteira sem trocas.
// 4. Resposta esperada: a saída acima. O total 7 é o número de inversões do
//    vetor original.
//
// Escreva sua resposta abaixo (modifique o código):

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int senhas[] = {9, 4, 7, 1, 5};
    int n = 5, trocas = 0;

    for (int passada = 1; passada < n; passada++) {
        for (int j = 0; j < n - passada; j++) {
            if (senhas[j] > senhas[j + 1]) {
                int aux = senhas[j];
                senhas[j] = senhas[j + 1];
                senhas[j + 1] = aux;
                trocas++;
            }
        }
        printf("passada %d:", passada);
        for (int i = 0; i < n; i++) {
            printf(" %d", senhas[i]);
        }
        printf("\n");
    }
    printf("trocas: %d\n", trocas);
    return 0;
}
