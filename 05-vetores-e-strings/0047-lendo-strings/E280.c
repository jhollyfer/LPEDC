// 0047 · Lendo strings
// Exercício E280 · ★★☆
//
// O cadastro do banco exige uma senha com pelo menos 8 caracteres, uma letra
// maiúscula, uma minúscula e um dígito (espaço é permitido). Leia a senha com
// fgets, tire o '\n' e mostre, para cada regra que falhar, uma linha "Falta:".
// Se nenhuma falhar, mostre "Senha forte.".
//
//   Exemplo de execução 1:
//   Senha: banana12
//   Falta: letra maiúscula
//
//   Exemplo de execução 2:
//   Senha: abc
//   Falta: 8 caracteres (tem 3)
//   Falta: letra maiúscula
//   Falta: dígito
//
//   Exemplo de execução 3:
//   Senha: Pao de Queijo 1
//   Senha forte.
//
// Dicas:
// 1. Um laço até o '\0' com três bool: tem_maiuscula, tem_minuscula,
//    tem_digito. Use isupper, islower e isdigit.
// 2. O tamanho vem do strlen DEPOIS de tirar o '\n'.
// 3. Guarde num bool se alguma regra falhou, para decidir o "Senha forte.".
// 4. Resposta esperada: as três execuções acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {

    return 0;
}
