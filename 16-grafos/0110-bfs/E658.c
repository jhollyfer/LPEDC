// 0110 · BFS: busca em largura
// Exercício E658 · ★★☆
//
// Depois do temporal, a companhia de energia sabe quais cabos entre os oito
// bairros (A a H) continuam inteiros. Bairros ligados, direta ou
// indiretamente, formam um grupo que pode ser religado de uma vez. Os cabos
// inteiros são:
//
//   A-B, B-C, D-E, F-G, G-H, F-H
//
// Escreva um programa que descobre os grupos (as COMPONENTES CONEXAS do
// grafo) usando BFS e mostra cada um:
//
//   Saída esperada:
//   Grupo 1: A B C
//   Grupo 2: D E
//   Grupo 3: F G H
//   Total de grupos: 3
//
// Dicas:
// 1. Uma BFS a partir de A visita só o grupo de A. Quem sobrar sem visita
//    está em outro grupo.
// 2. Laço externo: para cada bairro v ainda não visitado, comece uma BFS
//    nova a partir de v e some 1 nos grupos.
// 3. Um vetor visitado[] só, compartilhado por todas as BFS.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
