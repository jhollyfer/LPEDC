// 0085 · Fila
// Exercício E505 · ★☆☆
//
// Uma fila circular de 4 gavetas, com os campos à vista: struct Fila4 com o vetor
// itens, o índice inicio e o contador n (todas as gavetas começam com -1).
// Escreva bool insere(Fila4 *f, int valor), bool retira(Fila4 *f, int *valor) e
// void mostra(const Fila4 *f), que imprime o vetor inteiro (_ nas gavetas que
// valem -1) e depois inicio e n. No main, insira 1 a 6 mostrando o estado depois
// de cada tentativa (com "recusado" quando não couber); logo depois do 2, retire
// um; no fim, retire mais dois e mostre a gaveta onde entraria o próximo.
//
//   Saída esperada:
//   insere 1: [1 _ _ _] inicio 0, n 1
//   insere 2: [1 2 _ _] inicio 0, n 2
//   retira 1: [1 2 _ _] inicio 1, n 1
//   insere 3: [1 2 3 _] inicio 1, n 2
//   insere 4: [1 2 3 4] inicio 1, n 3
//   insere 5: [5 2 3 4] inicio 1, n 4
//   insere 6: recusado [5 2 3 4] inicio 1, n 4
//   retira 2: [5 2 3 4] inicio 2, n 3
//   retira 3: [5 2 3 4] inicio 3, n 2
//   próxima vaga: gaveta 1
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define CAP 4

typedef struct {
    int itens[CAP];
    int inicio;
    int n;
} Fila4;

int main(void) {

    return 0;
}
