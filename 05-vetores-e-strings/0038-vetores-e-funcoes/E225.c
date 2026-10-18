// 0038 · Vetores e funções
// Exercício E225 · ★★☆
//
// A função mexer abaixo recebe um vetor e um int. Uma das duas mudanças que
// ela faz chega ao main; a outra se perde. Mostre isso na tela:
//
//   1. No fim de mexer, acrescente um printf que mostre v[0], v[1], v[2] e x
//      (formato "dentro: ...", como na saída esperada).
//   2. No main, troque os dois printf pelos do formato "fora: ...".
//   3. Escreva void vezes_dez(int v[], int pos), que multiplica por 10 só a
//      gaveta pos do vetor, e use no fim do main para multiplicar a[2] de
//      verdade (coisa que mexer(a, a[2]) não fez).
//
//   Saída esperada:
//   dentro: v = 10 50 3, x = 50
//   fora: a = 10 50 3, b = 5
//   dentro: v = 100 30 3, x = 30
//   fora: a = 100 30 3
//   depois de vezes_dez: a = 100 30 30
//
// Dicas:
// 1. v recebe o endereço de a: v[0] e a[0] são a mesma gaveta.
// 2. x recebe uma cópia: mudar x não muda b, nem a[2].
// 3. Para mudar a[2] dentro de uma função, mande o vetor e a posição, não o
//    valor da gaveta.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete o programa):

#include <stdio.h>

void mexer(int v[], int x) {
    v[0] = v[0] * 10;
    x = x * 10;
    v[1] = x;
}

int main(void) {
    int a[3] = {1, 2, 3};
    int b = 5;

    mexer(a, b);
    printf("%d %d %d %d\n", a[0], a[1], a[2], b);
    mexer(a, a[2]);
    printf("%d %d %d\n", a[0], a[1], a[2]);
    return 0;
}
