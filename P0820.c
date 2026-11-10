// Lista · Módulo 08 · Tipos compostos
// Exercício P0820 · ★★☆ · A série do tamanho certo
//
// Desde o C99, o ÚLTIMO campo de uma struct pode ser um vetor sem tamanho (o
// "membro flexível"): typedef struct { char nome[16]; int n; double v[]; }
// Serie;. O sizeof da struct não conta o vetor, e você aloca a struct junto
// com quantas posições quiser, num bloco só:
//
//   Serie *s = malloc(sizeof *s + n * sizeof s->v[0]);
//
// Escreva Serie *nova_serie(const char *nome, const double *dados, int n), e
// crie duas séries de chuva (em mm), uma de 3 dias e outra de 7. Mostre cada
// série, a média, o sizeof da struct e quantos bytes cada bloco tem. Libere
// com UM free por série:
//
//   Belém: 12.5 30.0 8.0
//   Manaus: 0.0 4.5 22.0 18.0 0.0 6.5 11.0
//
//   Saída esperada:
//   sizeof(Serie) = 24 bytes
//   Belém (3 dias): 12.5 30.0  8.0
//     média 16.83 mm, bloco de 48 bytes
//   Manaus (7 dias):  0.0  4.5 22.0 18.0  0.0  6.5 11.0
//     média 8.86 mm, bloco de 80 bytes
//
// Dicas:
// 1. sizeof(Serie) conta nome (16) e n (4), mais o preenchimento que
//    alinha o double: 24 bytes. O vetor v não entra.
// 2. Depois do malloc, preencha s->n e copie os dados para s->v[i].
// 3. Como é um bloco só, um free(s) libera a struct e o vetor juntos.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
