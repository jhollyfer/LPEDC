// Lista · Módulo 13 · Busca e ordenação
// Exercício P1305 · ★☆☆ · Insertion sort das encomendas
//
// A transportadora carrega as encomendas da mais leve para a mais pesada.
// Os pesos, em kg, chegaram nesta ordem: 14, 9, 22, 5, 17, 9. Escreva um
// insertion sort que mostre o vetor depois de encaixar cada elemento
// (j = 1 até j = 5). Use pesos[i] > x no while, para o algoritmo ser
// estável.
//
//   Saída esperada:
//   j = 1: 9 14 22 5 17 9
//   j = 2: 9 14 22 5 17 9
//   j = 3: 5 9 14 22 17 9
//   j = 4: 5 9 14 17 22 9
//   j = 5: 5 9 9 14 17 22
//
// Dicas:
// 1. Guarde x = pesos[j] antes de deslocar: a posição j vai ser sobrescrita.
// 2. Desloque para a direita enquanto i >= 0 e pesos[i] > x; depois,
//    pesos[i + 1] = x.
// 3. Depois do passo j, só a parte pesos[0..j] está garantidamente
//    ordenada; o resto continua como chegou.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
