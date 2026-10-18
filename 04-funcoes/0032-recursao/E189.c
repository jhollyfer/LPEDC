// 0032 · Recursão
// Exercício E189 · ★★☆
//
// Escreva "void eco(int n, int nivel)", recursiva, que mostra "ida n" antes
// da chamada recursiva, "fundo" no caso base (n == 0) e "volta n" depois da
// chamada. Cada linha é recuada 2 espaços por nível: o main chama eco(3, 0),
// e cada chamada recursiva passa nivel + 1. Use uma função "void recuo(int
// nivel)" para os espaços.
//
//   Saída esperada:
//   ida 3
//     ida 2
//       ida 1
//         fundo
//       volta 1
//     volta 2
//   volta 3
//
// Dicas:
// 1. recuo: um for de 0 até nivel - 1 com printf("  ").
// 2. eco: if (n == 0) { recuo; "fundo"; return; } depois recuo, "ida",
//    eco(n - 1, nivel + 1), recuo, "volta".
// 3. Resposta esperada: a saída acima. O printf da volta só roda depois que a
//    chamada de dentro terminou, e cada quadro lembra o seu n e o seu nivel.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
