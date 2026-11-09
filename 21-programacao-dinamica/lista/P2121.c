// Lista · Módulo 21 · Programação dinâmica
// Exercício P2121 · ★★★ · A ordem das multiplicações de matrizes
//
// Multiplicar uma matriz p × q por uma q × r custa p · q · r
// multiplicações de números. Num produto A1 A2 A3 A4 A5, o resultado é o
// mesmo em qualquer parentização, mas o custo muda muito. As dimensões
// são (Ai é d[i - 1] × d[i]):
//
//   d = 30 35 15 5 10 20
//
// Escreva do zero a PD da MULTIPLICAÇÃO EM CADEIA (Cormen 15.2): m[i][j] é
// o menor custo para multiplicar Ai..Aj; m[i][i] = 0 e, para i < j,
// m[i][j] = min, para k de i a j - 1, de m[i][k] + m[k + 1][j] + d[i - 1]
// · d[k] · d[j]. Preencha por tamanho de trecho crescente, guarde o k
// ótimo em s[i][j] e mostre a parentização com uma função recursiva.
// Compare com a ordem da esquerda para a direita.
//
//   Saída esperada:
//   Ótimo: 11875 multiplicações com ((A1(A2A3))(A4A5))
//   Da esquerda para a direita: 25500 multiplicações
//
// Dicas:
// 1. Laço externo: tam de 2 a n; i de 1 a n - tam + 1; j = i + tam - 1.
// 2. mostra(i, j): se i == j, imprime "A" e i; senão, "(", mostra(i,
//    s[i][j]), mostra(s[i][j] + 1, j), ")".
// 3. Resposta esperada: 11875 multiplicações com ((A1(A2A3))(A4A5)),
//    contra 17000 da esquerda para a direita... confira na saída.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
