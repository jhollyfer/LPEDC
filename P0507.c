// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0507 · ★☆☆ · Raio-x do endereço
//
// O cadastro da loja recebeu o endereço abaixo e quer saber do que ele é
// feito. Conte, com as funções do ctype.h, as letras maiúsculas, as
// minúsculas, os dígitos, os espaços e o resto (pontuação):
//
//   char endereco[] = "Rua 7 de Setembro, 1500 - Centro";
//
//   Saída esperada:
//   Maiúsculas: 3
//   Minúsculas: 16
//   Dígitos: 5
//   Espaços: 6
//   Outros: 2
//   Total: 32 (strlen = 32)
//
// Dicas:
// 1. Ande até o '\0': for (int i = 0; endereco[i] != '\0'; i++).
// 2. Uma cadeia de if/else if com isupper, islower, isdigit e isspace; o que
//    sobrar cai no else (outros).
// 3. Confira: a soma das cinco contagens tem que dar o strlen do endereço.
// 4. Resposta esperada: a saída acima (32 caracteres no total).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char endereco[] = "Rua 7 de Setembro, 1500 - Centro";
    (void) endereco; // apague esta linha quando escrever

    return 0;
}
