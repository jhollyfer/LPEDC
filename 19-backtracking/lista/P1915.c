// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1915 · ★★☆ · Quanto a poda economiza
//
// O caixa da cooperativa precisa achar quais boletos somam exatamente R$
// 100 entre 12 boletos pendentes. O programa abaixo testa todos os 2^12
// subconjuntos, sem poda, e conta as chamadas. Estenda-o: escreva
// com_poda(i, soma, resto), igual a sem_poda, mas que corta o ramo em dois
// casos: quando soma > ALVO (passou) e quando soma + resto < ALVO (nem
// levando tudo o que falta chega lá). resto é a soma dos boletos de i em
// diante. Mostre as soluções e as chamadas das duas versões.
//
//   Saída esperada:
//   Sem poda: 50 soluções, 8191 chamadas
//   Com poda: 50 soluções, 745 chamadas
//
// Dicas:
// 1. Calcule o resto inicial (soma de todos) no main. Ao descer para i + 1,
//    o resto perde v[i], leve ou não leve o boleto.
// 2. Os dois cortes vêm antes do teste i == N. O teste soma == ALVO pode
//    contar a solução na hora e voltar: os boletos que faltam só aumentariam
//    a soma.
// 3. Resposta esperada: as duas acham 9 soluções; sem poda são 8191
//    chamadas, com poda bem menos (a saída de cima).
//
// Escreva sua resposta abaixo (estenda o código):

#include <stdio.h>

#define N 12
#define ALVO 100

const int v[N] = {45, 38, 30, 27, 22, 20, 15, 12, 10, 8, 5, 3};
long chamadas;
int solucoes;

void sem_poda(int i, int soma) {
    chamadas++;
    if (i == N) {
        if (soma == ALVO) {
            solucoes++;
        }
        return;
    }
    sem_poda(i + 1, soma + v[i]);
    sem_poda(i + 1, soma);
}

int main(void) {
    chamadas = 0;
    solucoes = 0;
    sem_poda(0, 0);
    printf("Sem poda: %d soluções, %ld chamadas\n", solucoes, chamadas);
    return 0;
}
