// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0902 · ★☆☆ · Lista de chamada numerada
//
// Grave em /tmp/p0902_chamada.txt os nomes da chamada do cursinho, um por
// linha: Ana Clara, Bruno, Iara Souza e Joao. Depois leia o arquivo linha a
// linha com fgets e mostre cada nome numerado e com o tamanho (sem contar o
// '\n'). No fim, mostre quantas linhas o arquivo tinha e apague o arquivo.
//
//   Saída esperada:
//   1: Ana Clara (9 caracteres)
//   2: Bruno (5 caracteres)
//   3: Iara Souza (10 caracteres)
//   4: Joao (4 caracteres)
//   Total: 4 linhas
//
// Dicas:
// 1. fgets(linha, sizeof linha, arq) devolve NULL quando o arquivo acaba.
// 2. A linha lida vem com o '\n' no fim: tire com
//    linha[strcspn(linha, "\n")] = '\0' antes do strlen.
// 3. Resposta esperada: a saída acima; sem tirar o '\n', cada tamanho sairia
//    com 1 a mais.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
