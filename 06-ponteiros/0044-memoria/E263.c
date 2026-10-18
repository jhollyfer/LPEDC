// 0044 · Memória e endereços
// Exercício E263 · ★★★
//
// Investigue: variáveis declaradas juntas ficam juntas na memória? Declare
//
//   int a = 1, b = 2, c = 3;
//   int v[3] = {1, 2, 3};
//
// e mostre o endereço de a, b, c e de v[0], v[1], v[2]. Rode com o rodar.
// Depois compile SEM o sanitizer e rode de novo:
//
//   gcc -std=c17 E263.c -o e293 && ./e293
//
// Responda: (a) os elementos do vetor ficam colados e em ordem? (b) e a, b
// e c? (c) o que você pode concluir para escrever programas?
//
// Dicas:
// 1. Compare os últimos dígitos hexa de cada endereço.
// 2. O AddressSanitizer coloca "zonas proibidas" entre as variáveis para
//    pegar estouros; sem ele, o compilador arruma do jeito que quiser.
// 3. Resposta esperada: (a) sim, sempre: v[0], v[1], v[2] sobem de 4 em 4,
//    nas duas compilações; (b) depende: com o rodar ficaram 16 bytes
//    distantes; sem o sanitizer costumam ficar a 4 bytes, mas a ordem e
//    a distância são escolha do compilador e podem mudar; (c) só o vetor tem ordem garantida. Nunca suponha que
//    b mora "logo depois" de a.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
