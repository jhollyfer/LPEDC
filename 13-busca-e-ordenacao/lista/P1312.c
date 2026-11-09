// Lista · Módulo 13 · Busca e ordenação
// Exercício P1312 · ★★☆ · Encaixando consultas na agenda
//
// A agenda da clínica guarda os horários marcados em minutos desde a
// meia-noite (480 é 8h00), em ordem crescente: 480, 540, 600, 660, 780, 840.
// Chegam novos pedidos de horário: 615, 450, 900 e 600 (este já existe; o
// novo entra ANTES do antigo).
//
// Escreva:
//
//   int ponto_insercao(const int v[], int n, int x)
//     busca binária que devolve a primeira posição com v[i] >= x (de 0 a n)
//   int insere(int v[], int *n, int x)
//     acha o ponto de inserção, desloca o resto uma casa para a direita,
//     grava x, aumenta *n e devolve a posição
//
// Mostre a agenda depois de cada inserção (o vetor tem capacidade 10).
//
//   Saída esperada:
//   615 entrou na posição 3: 480 540 600 615 660 780 840
//   450 entrou na posição 0: 450 480 540 600 615 660 780 840
//   900 entrou na posição 8: 450 480 540 600 615 660 780 840 900
//   600 entrou na posição 3: 450 480 540 600 600 615 660 780 840 900
//
// Dicas:
// 1. É a busca binária de sempre, com intervalo fechado, mas sem o "achou,
//    devolve": se v[meio] < x, ini = meio + 1; senão, fim = meio - 1.
// 2. Quando o while termina, ini é o ponto de inserção. Faça o teste de mesa
//    com x = 900: ini chega a 8 = n.
// 3. Desloque de trás para frente (i de *n até pos + 1), para não apagar
//    ninguém.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
