// Lista · Módulo 04 · Funções e modularização
// Exercício P0423 · ★★★ · Os verificadores do CNPJ
//
// O CNPJ tem 12 dígitos e 2 verificadores, com uma regra parecida com a do CPF.
// Para cada verificador, multiplique os dígitos, da DIREITA para a esquerda,
// pelos pesos 2, 3, 4, ..., 9, voltando a 2 depois do 9; com r = soma % 11, o
// dígito é 0 se r < 2, senão 11 − r. O 1º usa os 12 primeiros dígitos; o 2º
// usa os 12 mais o 1º verificador. Escreva "int verificador(long long n)",
// "bool todos_iguais(long long cnpj)" e "bool cnpj_valido(long long cnpj)", e
// teste três CNPJs de 14 dígitos:
//
//   Saída esperada:
//   11222333000181: válido
//   11222333000182: inválido
//   11111111111111: inválido
//
// Dicas:
// 1. Em verificador, ande de n % 10 para a esquerda com n /= 10, e o peso faz
//    peso = peso == 9 ? 2 : peso + 1.
// 2. Em cnpj_valido: base = cnpj / 100; dv1 = verificador(base); dv2 =
//    verificador(base * 10 + dv1); confira com cnpj % 100.
// 3. todos_iguais compara cada dígito com o último.
// 4. Resposta esperada: válido, inválido, inválido.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
