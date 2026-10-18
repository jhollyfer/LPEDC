// 0092 · Selection sort
// Exercício E551 · ★★★
//
// Na estufa, as mudas precisam ficar em fila da mais baixa para a mais alta.
// Este selection sort tem UM erro, de propósito: compila sem aviso, roda sem
// reclamação do sanitizer e mesmo assim mostra
//
//   40 15 21 28 33
//
// Faça o teste de mesa das passadas i = 0 e i = 1, anotando o valor de menor,
// explique o erro e conserte.
//
//   Saída esperada (depois de consertar):
//   15 21 28 33 40
//
// Dicas:
// 1. Em que linha menor recebe um valor? Quantas vezes essa linha roda?
// 2. Na passada 0, o 15 já está na gaveta 0: menor fica 0 e a troca é dele
//    com ele mesmo. Para onde menor aponta quando a passada 1 começa?
// 3. Resposta esperada: menor é inicializado uma vez só, com 0, fora do laço
//    de fora. Na passada 1 ele ainda vale 0 (o 15, o menor de todos), ninguém
//    de v[2..4] é menor que 15, e a troca joga o 15 de volta para a gaveta 1
//    e o 40 para a 0. Conserto: int menor = i; no começo de cada passada.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int alturas[] = {15, 40, 28, 33, 21};   // mudas de planta, em cm
    int n = 5;
    int menor = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (alturas[j] < alturas[menor]) {
                menor = j;
            }
        }
        int aux = alturas[i];
        alturas[i] = alturas[menor];
        alturas[menor] = aux;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", alturas[i]);
    }
    printf("\n");
    return 0;
}
