// 0041 · Strings
// Exercício E244 · ★★☆
//
// Um palíndromo se lê igual nos dois sentidos: "arara", "osso". Escreva
//
//   bool eh_palindromo(const char s[]);
//
// que ignora a diferença entre maiúsculas e minúsculas ("Reviver" vale) e
// teste com as palavras do vetor de strings abaixo (cada linha da matriz de
// char é uma string):
//
//   char palavras[5][12] = {"arara", "Reviver", "carro", "Osso", "A"};
//
//   Saída esperada:
//   arara: sim
//   Reviver: sim
//   carro: não
//   Osso: sim
//   A: sim
//
// Dicas:
// 1. Dois índices: i começa em 0 e j em strlen(s) - 1. Compare, e ande com
//    os dois para o meio enquanto i < j.
// 2. Compare tolower(s[i]) com tolower(s[j]).
// 3. palavras[k] é a linha k da matriz: uma string que você passa para a
//    função como qualquer outra.
// 4. Resposta esperada: a saída acima. Desafio extra: ignore também os
//    espaços e teste com "Anotaram a data da maratona".
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {

    return 0;
}
