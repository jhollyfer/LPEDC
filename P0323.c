// Lista · Módulo 03 · Laços
// Exercício P0323 · ★★★ · Validação de CPF com laço
//
// Escreva um programa que leia um CPF de 11 dígitos, só números, num long long,
// e diga se ele é válido. Separe os dígitos com um laço. Regras: CPF com os 11
// dígitos iguais é inválido; o 1º verificador vem dos 9 primeiros dígitos com
// pesos de 10 a 2; o 2º vem dos 10 primeiros com pesos de 11 a 2; em cada um,
// r = soma % 11 e o dígito é 0 se r < 2, senão 11 − r. Três interações:
//
//   Saída esperada:
//   CPF (11 dígitos): 11144477735
//   CPF válido
//
//   CPF (11 dígitos): 11144477734
//   CPF inválido: o 2º dígito deveria ser 5
//
//   CPF (11 dígitos): 22222222222
//   CPF inválido: dígitos todos iguais
//
// Dicas:
// 1. O dígito na posição p (1 é o mais à esquerda) é cpf / 10^(11 - p) % 10.
//    Num laço, vá dividindo uma potência de 10 que começa em 10000000000.
// 2. Some soma1 nas posições 1 a 9 e soma2 nas posições 1 a 10, com os pesos
//    11 - p e 12 - p.
// 3. Para os dígitos iguais, compare cada dígito com o primeiro e use uma flag.
// 4. Resposta esperada: as três saídas acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
