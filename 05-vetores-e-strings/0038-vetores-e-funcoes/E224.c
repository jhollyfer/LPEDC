// 0038 · Vetores e funções
// Exercício E224 · ★☆☆
//
// Complete as duas funções. O main já está pronto: ele prepara as 10 vagas de
// um estacionamento (0 = livre), ocupa algumas e mostra o mapa.
//
//   preencher(v, n, valor)  põe valor em todas as n posições
//   mostrar(v, n)           mostra as posições separadas por espaço e quebra
//                           a linha no fim
//
//   Saída esperada:
//   0 0 0 0 0 0 0 0 0 0
//   1 0 0 1 0 0 0 1 1 0
//
// Dicas:
// 1. preencher altera o vetor do main; mostrar só lê, então merece const.
// 2. O for das duas é igual: de 0 a n - 1.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete as funções):

#include <stdio.h>

#define VAGAS 10

void preencher(int v[], int n, int valor) {
    (void) v, (void) n, (void) valor; // apague esta linha quando escrever

}

void mostrar(const int v[], int n) {
    (void) v, (void) n; // apague esta linha quando escrever

}

int main(void) {
    int vagas[VAGAS];

    preencher(vagas, VAGAS, 0);
    mostrar(vagas, VAGAS);

    vagas[0] = 1;
    vagas[3] = 1;
    vagas[7] = 1;
    vagas[8] = 1;
    mostrar(vagas, VAGAS);
    return 0;
}
