// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2007 · ★☆☆ · O código que confunde
//
// O código de Huffman é LIVRE DE PREFIXO: nenhum código é o começo de
// outro, e por isso dá para ler a sequência de bits sem separador. Um
// estagiário montou três tabelas para os símbolos A, B, C, D e E e quer
// saber quais servem. Escreva do zero livre_de_prefixo(cod, n), que
// compara cada par de códigos e devolve 0 ao achar um que é começo do
// outro (mostrando qual), ou 1 se a tabela serve.
//
//   Tabela 1: A=0   B=10  C=110  D=1110  E=1111
//   Tabela 2: A=0   B=01  C=110  D=111   E=10
//   Tabela 3: A=00  B=01  C=10   D=110   E=111
//
//   Saída esperada:
//   Tabela 1:
//     serve
//   Tabela 2:
//     A=0 é começo de B=01
//     não serve
//   Tabela 3:
//     serve
//
// Dicas:
// 1. a é prefixo de b quando strlen(a) <= strlen(b) e strncmp(a, b,
//    strlen(a)) == 0.
// 2. Teste os dois sentidos para cada par i < j.
// 3. Resposta esperada: as tabelas 1 e 3 servem; na 2, o 0 do A é começo
//    do 01 do B (e "01" poderia ser AE... ou B).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
