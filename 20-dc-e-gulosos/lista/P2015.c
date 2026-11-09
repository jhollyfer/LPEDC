// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2015 · ★★☆ · Huffman sem heap, para poucos símbolos
//
// Com só 6 símbolos, o heap é exagero: dá para achar os dois nós de menor
// frequência com um laço simples, O(n) por passo. A rádio comunitária vai
// transmitir boletins com as letras A, E, M, N, O e S, com estas
// frequências (em cada 100 letras):
//
//   A: 30   E: 20   M: 5   N: 10   O: 25   S: 10
//
// Escreva do zero a árvore de Huffman num vetor de nós (folhas nas
// posições 0 a 5, nós internos de 6 em diante), cada nó com freq, esq, dir
// e um flag de "já usado". Em cada passo, junte os dois de menor
// frequência ainda não usados. Depois, calcule a profundidade de cada
// folha (o tamanho do código) e o total de bits.
//
//   Saída esperada:
//   A: freq 30, código de 2 bits
//   E: freq 20, código de 2 bits
//   M: freq  5, código de 4 bits
//   N: freq 10, código de 4 bits
//   O: freq 25, código de 2 bits
//   S: freq 10, código de 3 bits
//   Total: 240 bits (código fixo: 300)
//
// Dicas:
// 1. menor_livre(n) devolve o índice do nó livre de menor freq entre 0 e n
//    - 1 (empate: o de menor índice). Chame duas vezes, marcando o
//    primeiro como usado antes de procurar o segundo.
// 2. A profundidade sai de uma recursão a partir da raiz (o último nó
//    criado): prof(no, d) chega na folha com d = tamanho do código.
// 3. Resposta esperada: 240 bits para as 100 letras, contra 300 de um
//    código fixo de 3 bits.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
