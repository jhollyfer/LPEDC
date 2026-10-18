// 0047 · Ponteiros e vetores
// Exercício E278 · ★☆☆
//
// Complete o programa. O vetor e o ponteiro já estão declarados:
//
//   int v[6] = {10, 20, 30, 40, 50, 60};
//   int *p = v + 1;
//
// Sem escrever v nem números entre colchetes de v (só p, *, + e p[...]),
// mostre, um por linha:
//
//   a) o 20, com *
//   b) o 50, com * e +
//   c) o 23, somando 3 ao valor apontado
//   d) o 40, com colchetes em p
//   e) o endereço de p e o de p + 3, com %p
//
// Depois faça p += 2 e mostre:
//
//   f) o 40, com *
//   g) o 30, com colchetes em p
//   h) quantos elementos p está à frente do começo do vetor (aqui pode
//      usar v)
//
//   Saída esperada (o endereço muda a cada execução):
//   a) 20
//   b) 50
//   c) 23
//   d) 40
//   e) p = 0x7f...24, p + 3 = 0x7f...30
//   f) 40
//   g) 30
//   h) 3
//
// Dicas:
// 1. p começa em v[1]. p[k] é *(p + k), contado a partir de onde p está.
// 2. *(p + 3) anda antes de pegar o valor; *p + 3 pega o valor e soma. Um
//    índice negativo, como p[-1], olha para trás.
// 3. Resposta esperada: a saída acima, com *p, *(p + 3), *p + 3, p[2],
//    depois *p, p[-1] e p - v (formato %td). O endereço de p + 3 fica 12
//    bytes depois do de p.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

int main(void) {
    int v[6] = {10, 20, 30, 40, 50, 60};
    int *p = v + 1;

    // a) a e)

    p += 2;

    // f) a h)

    return 0;
}
