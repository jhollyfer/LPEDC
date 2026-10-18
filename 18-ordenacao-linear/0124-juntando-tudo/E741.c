// 0124 · Juntando tudo
// Exercício E741 · ★★☆
//
// O texto ordenou pelo valor e DEPOIS pelo horário para ter a linha do
// tempo com os empates de segundo em ordem de valor. E se fizer na ordem
// contrária? Escreva bool em_ordem(const Pix v[], int n, bool
// horario_primeiro), que confere se v está em ordem de (horário, valor) ou,
// com horario_primeiro = false, de (valor, horário). Depois, com 200 mil Pix
// (semente 77) em dois vetores iguais, faça as duas ordens de passadas e
// confira.
//
//   Saída esperada:
//   valor, depois horário: (horário, valor)? sim
//   horário, depois valor: (horário, valor)? não
//   horário, depois valor: (valor, horário)? sim
//
// Dicas:
// 1. Em ordem de (horário, valor) quer dizer: para cada vizinho, o horário
//    de v[i - 1] é menor, ou é igual e o valor é menor ou igual.
// 2. Use memcpy para começar os dois vetores iguais e um aux só para as
//    quatro ordenações.
// 3. A última passada é a que manda (é a chave principal); as anteriores só
//    desempatam, e só porque as duas ordenações são estáveis.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pix.h"

#define N 200000

int main(void) {

    return 0;
}
