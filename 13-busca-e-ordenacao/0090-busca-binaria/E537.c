// 0090 · Busca binária
// Exercício E537 · ★★☆
//
// As avaliações de um app (de 1 a 5 estrelas) já estão ordenadas:
//
//   1, 1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5
//
// Para cada nota de 1 a 5, mostre em que posições ela aparece e quantas vezes,
// usando DUAS buscas binárias por nota (nada de percorrer o vetor contando):
// uma acha a primeira posição com valor >= nota, a outra a primeira posição
// com valor > nota.
//
//   Saída esperada:
//   Nota 1: posições 0 a 1, 2 avaliações
//   Nota 2: posições 2 a 2, 1 avaliação
//   Nota 3: posições 3 a 6, 4 avaliações
//   Nota 4: posições 7 a 8, 2 avaliações
//   Nota 5: posições 9 a 11, 3 avaliações
//
// Dicas:
// 1. Use o estilo semiaberto do exemplo A180: ini = 0, fim = n, while (ini < fim).
// 2. As duas funções só diferem numa comparação: v[meio] < x ou v[meio] <= x.
// 3. Se a primeira dá a e a segunda dá b, a nota aparece b - a vezes, nas
//    posições a até b - 1.
// 4. Resposta esperada: a saída acima. Com um milhão de avaliações, cada
//    contagem custa umas 40 voltas, e não um milhão.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
