// Lista · Módulo 07 · Memória dinâmica
// Exercício P0730 · ★★★ · O editor de linhas
//
// Escreva um editor de texto mínimo: o documento é um vetor dinâmico de
// linhas (char **, cada linha uma cópia no heap) com n e cap. Escreva:
//
//   bool inserir(char ***doc, int *n, int *cap, int pos, const char *texto);
//   void apagar(char **doc, int *n, int pos);
//
// inserir abre espaço na posição pos (0 <= pos <= n) empurrando as linhas
// seguintes uma casa para frente com memmove; apagar libera a linha pos e
// puxa as seguintes com memmove. O vetor dobra quando enche (começando em
// 2). Execute os comandos abaixo e mostre o documento no fim:
//
//   inserir 0 "Ata da reunião do condomínio"
//   inserir 1 "Pauta: portão da garagem"
//   inserir 2 "Encerrada às 21h"
//   inserir 2 "Aprovado o conserto por R$ 850"
//   inserir 1 "Presentes: 14 moradores"
//   apagar 3
//   inserir 3 "Aprovado o conserto por R$ 790"
//
//   Saída esperada:
//   (capacidade 2)
//   (capacidade 4)
//   (capacidade 8)
//   1 | Ata da reunião do condomínio
//   2 | Presentes: 14 moradores
//   3 | Pauta: portão da garagem
//   4 | Aprovado o conserto por R$ 790
//   5 | Encerrada às 21h
//   5 linhas, capacidade 8
//
// Dicas:
// 1. *doc é o vetor de linhas do main; como o realloc pode mudá-lo de
//    lugar, inserir recebe char *** (o endereço do char ** do main).
// 2. memmove(&v[pos + 1], &v[pos], (*n - pos) * sizeof *v) empurra os
//    PONTEIROS (as linhas não saem do lugar). memmove, e não memcpy, porque
//    as duas áreas se sobrepõem.
// 3. Em apagar: free(v[pos]) antes de puxar, senão a linha vaza.
// 4. No fim, libere cada linha e o vetor.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void) {

    return 0;
}
