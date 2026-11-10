// Lista · Módulo 03 · Laços
// Exercício P0322 · ★★★ · De decimal para qualquer base
//
// Escreva um programa que leia um número inteiro positivo e uma base de 2 a 16
// e mostre o número naquela base, com os dígitos de 10 a 15 como A a F. Ainda
// não há vetores, então você não pode guardar os restos para mostrar ao
// contrário: em vez disso, ache a maior potência da base que cabe no número e
// vá descendo, mostrando um dígito por potência. Repita a pergunta da base até
// ela valer de 2 a 16. Duas interações:
//
//   Saída esperada:
//   Número e base: 2026 16
//   2026 na base 16: 7EA
//
//   Número e base: 2026 2
//   2026 na base 2: 11111101010
//
// Dicas:
// 1. potencia = 1; while (potencia <= n / base) potencia *= base; (dividir
//    antes evita estourar o int).
// 2. Depois: while (potencia > 0) { digito = n / potencia; n %= potencia;
//    potencia /= base; ... }.
// 3. Para mostrar o dígito: se for menor que 10, '0' + digito; senão, 'A' +
//    digito - 10, com %c.
// 4. Resposta esperada: 7EA na base 16; 11111101010 na base 2; 2026 na base 8
//    é 3752.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
