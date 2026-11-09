// Lista · Módulo 06 · Ponteiros
// Exercício P0613 · ★★☆ · O filtro do extrato do Pix
//
// O extrato do mês tem estes valores (positivo é entrada, negativo é saída):
//
//   int pix[10] = {1500, -89, -230, 45, -12, 3200, -1450, -75, 300, -640};
//
// Escreva int filtrar(const int *v, int n, int *saida, bool (*passa)(int)),
// que copia para saida, na ordem, só os valores para os quais passa devolve
// true, e devolve quantos copiou. Escreva três critérios e mostre o
// resultado de cada um com a soma:
// - entrada: o valor é positivo;
// - saida_grande: é uma saída de mais de R$ 100;
// - miudo: o valor, com ou sem sinal, é menor que R$ 100.
//
//   Saída esperada:
//   Entradas: 1500 45 3200 300 (4 itens, soma 5045)
//   Saídas grandes: -230 -1450 -640 (3 itens, soma -2320)
//   Miúdos: -89 45 -12 -75 (4 itens, soma -131)
//
// Dicas:
// 1. saida_grande(int x) é x < -100; miudo(int x) é abs(x) < 100 (abs está
//    no stdlib.h).
// 2. O vetor saida precisa caber o pior caso: todos passam. int saida[10].
// 3. Escreva void relatorio(const char *nome, const int *v, int n,
//    bool (*passa)(int)) para o main ficar com três linhas.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    int pix[10] = {1500, -89, -230, 45, -12, 3200, -1450, -75, 300, -640};
    (void) pix; // apague esta linha quando escrever

    return 0;
}
