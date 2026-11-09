// Lista · Módulo 04 · Funções e modularização
// Exercício P0420 · ★★☆ · O maior dígito que sumiu
//
// A função recursiva abaixo deveria devolver o maior dígito de um número, mas
// para 9123 devolve 3. O erro está no caso base, de propósito. Conserte só o
// caso base e confira com os três testes:
//
//   Saída esperada:
//   Maior dígito de 9123: 9
//   Maior dígito de 4718: 8
//   Maior dígito de 5: 5
//
// Dicas:
// 1. Siga a recursão na mão para 9123: quem é o último a responder, e o que
//    ele responde?
// 2. Um número de um dígito só é o seu próprio maior dígito.
// 3. Resposta esperada: 9, 8 e 5.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int maior_digito(int n) {
    if (n < 10) {
        return 0;
    }
    int resto = maior_digito(n / 10);
    return n % 10 > resto ? n % 10 : resto;
}

int main(void) {
    printf("Maior dígito de 9123: %d\n", maior_digito(9123));
    printf("Maior dígito de 4718: %d\n", maior_digito(4718));
    printf("Maior dígito de 5: %d\n", maior_digito(5));
    return 0;
}
