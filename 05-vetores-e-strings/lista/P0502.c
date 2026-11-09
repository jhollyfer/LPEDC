// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0502 · ★☆☆ · Procurando o código no estoque
//
// O mercadinho guarda os códigos dos produtos num vetor, na ordem em que
// foram cadastrados:
//
//   int codigos[8] = {4410, 1270, 9031, 5588, 1270, 3302, 7745, 6120};
//
// Escreva int buscar(const int v[], int n, int procurado), que devolve a
// POSIÇÃO da primeira ocorrência de procurado no vetor, ou -1 se ele não
// estiver lá. No main, procure 5588, 1270 e 2000 e mostre o resultado assim:
//
//   Saída esperada:
//   Código 5588: posição 3
//   Código 1270: posição 1
//   Código 2000: não cadastrado
//
// Dicas:
// 1. Uma busca linear: um for de 0 a n - 1 que compara v[i] com procurado.
// 2. Achou? return i na hora: é isso que garante a PRIMEIRA ocorrência.
// 3. O return -1 fica depois do laço: só chega lá quem não achou.
// 4. Resposta esperada: a saída acima (1270 aparece duas vezes, mas a busca
//    para na posição 1).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int codigos[8] = {4410, 1270, 9031, 5588, 1270, 3302, 7745, 6120};
    (void) codigos; // apague esta linha quando escrever

    return 0;
}
