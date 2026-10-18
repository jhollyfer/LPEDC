// 0026 · Aleatórios
// Exercício E151 · ★☆☆
//
// Escreva a expressão com rand() que sorteia cada faixa abaixo. Para testar,
// faça um for que mostra 10 sorteios de cada uma (com srand(1) no começo) e
// confira se nenhum número sai da faixa:
//
//   a) um dado: 1 a 6
//   b) um dígito: 0 a 9
//   c) a idade de um sorteado entre 10 e 20 anos
//   d) uma variação de temperatura de -5 a 5
//   e) só os pares de 2 a 20
//
// Dicas:
// 1. rand() % n dá de 0 a n - 1. Somando a, a faixa começa em a.
// 2. Para a faixa de a até b: a + rand() % (b - a + 1).
// 3. Resposta esperada: a) 1 + rand() % 6; b) rand() % 10;
//    c) 10 + rand() % 11; d) -5 + rand() % 11; e) 2 + 2 * (rand() % 10)
//    (sorteia de 0 a 9 e transforma em 2, 4, ..., 20).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
