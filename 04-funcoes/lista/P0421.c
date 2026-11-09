// Lista · Módulo 04 · Funções e modularização
// Exercício P0421 · ★★★ · Hanói com 4 discos e a conta de cada disco
//
// Resolva a Torre de Hanói com 4 discos, das hastes A para C, usando B de
// apoio. Escreva "void hanoi(int n, char origem, char destino, char apoio)",
// recursiva, e "void mover(int disco, char de, char para)", que numera e mostra
// cada movimento e conta quantas vezes cada disco se moveu (sem vetor: quatro
// contadores e um switch). No fim, mostre o total e a conta de cada disco:
//
//   Saída esperada:
//    1: disco 1 de A para B
//    2: disco 2 de A para C
//    3: disco 1 de B para C
//    4: disco 3 de A para B
//    5: disco 1 de C para A
//    6: disco 2 de C para B
//    7: disco 1 de A para B
//    8: disco 4 de A para C
//    9: disco 1 de B para C
//   10: disco 2 de B para A
//   11: disco 1 de C para A
//   12: disco 3 de B para C
//   13: disco 1 de A para B
//   14: disco 2 de A para C
//   15: disco 1 de B para C
//   Total: 15 movimentos
//   Disco 1: 8, disco 2: 4, disco 3: 2, disco 4: 1
//
// Dicas:
// 1. hanoi(n): se n == 0, nada; senão hanoi(n - 1, origem, apoio, destino),
//    mover(n, origem, destino), hanoi(n - 1, apoio, destino, origem).
// 2. Os contadores podem ser globais ou static dentro de mover; o total é a
//    soma deles.
// 3. Repare: o disco k se move 2^(4 - k) vezes, e o total é 2^4 - 1.
// 4. Resposta esperada: 15 movimentos; 8, 4, 2 e 1.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
