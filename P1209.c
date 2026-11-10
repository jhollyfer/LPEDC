// Lista · Módulo 12 · Pilhas e filas
// Exercício P1209 · ★☆☆ · Por que a fila em vetor é circular
//
// Um jeito ingênuo de fazer fila em vetor: o primeiro está SEMPRE em v[0];
// para retirar, todo mundo anda uma casa para a frente. Escreva essa fila
// (insere no fim, retira de v[0] deslocando os outros) contando os
// deslocamentos, e a fila circular (inicio, n) contando os mesmos. Nas
// duas, insira as senhas 1 a 5 e depois retire as 5, mostrando a ordem em
// que saíram.
//
//   Saída esperada:
//   Deslocando: saíram 1 2 3 4 5 com 10 deslocamentos
//   Circular:   saíram 1 2 3 4 5 com 0 deslocamentos
//
// Dicas:
// 1. Na ingênua, retirar com n itens desloca n - 1: 4 + 3 + 2 + 1 + 0.
//    Esvaziar uma fila de n itens custa n (n - 1) / 2: O(n²).
// 2. Na circular, retirar só anda o inicio: inicio = (inicio + 1) % CAP.
//    Cada operação é O(1).
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define CAP 8

int main(void) {

    return 0;
}
