// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0516 · ★★☆ · A mediana do tempo de entrega
//
// O app de entregas mediu, em minutos, as 9 últimas corridas de um motoboy:
//
//   int tempos[9] = {34, 18, 52, 27, 41, 23, 19, 60, 30};
//
// A média engana quando há corrida muito demorada; a MEDIANA é o valor do
// meio depois de ordenar. Ordene o vetor com a ordenação por seleção (a cada
// passo, ache o menor do que sobrou e troque com a posição i), mostrando o
// vetor depois de cada passo. No fim, mostre a média e a mediana:
//
//   Saída esperada:
//   Passo 1: 18 34 52 27 41 23 19 60 30
//   Passo 2: 18 19 52 27 41 23 34 60 30
//   Passo 3: 18 19 23 27 41 52 34 60 30
//   Passo 4: 18 19 23 27 41 52 34 60 30
//   Passo 5: 18 19 23 27 30 52 34 60 41
//   Passo 6: 18 19 23 27 30 34 52 60 41
//   Passo 7: 18 19 23 27 30 34 41 60 52
//   Passo 8: 18 19 23 27 30 34 41 52 60
//   Média: 33.78 min
//   Mediana: 30 min
//
// Dicas:
// 1. Para i de 0 a n - 2: ache o índice do menor entre v[i] e v[n - 1] e
//    troque-o com v[i]. Mostre o vetor depois da troca.
// 2. Com n ímpar, a mediana é v[n / 2] depois de ordenado.
// 3. A média usa double: soma / (double) n.
// 4. Resposta esperada: a saída acima (média 33.78, mediana 30).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int tempos[9] = {34, 18, 52, 27, 41, 23, 19, 60, 30};
    (void) tempos; // apague esta linha quando escrever

    return 0;
}
