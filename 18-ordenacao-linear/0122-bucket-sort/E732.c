// 0122 · Bucket sort
// Exercício E732 · ★★★
//
// O fiscal da linha de ônibus quer saber qual é a maior espera entre duas
// partidas seguidas. Os horários chegam fora de ordem, em minutos desde a
// meia-noite. Ordenar e olhar os vizinhos resolve em O(n log n); o desafio
// é resolver em O(n), com baldes e SEM ordenar:
//
// 1. ache o menor e o maior horário;
// 2. use N baldes de largura L = teto((maior - menor) / (N - 1)). Cada
// balde guarda só o menor e o maior horário que caíram nele (e se foi
// usado);
// 3. o maior intervalo nunca fica dentro de um balde: ele é sempre a
// diferença entre o MENOR de um balde usado e o MAIOR do balde usado
// anterior. Percorra os baldes e pegue a maior dessas diferenças.
//
// No fim, confira a resposta ordenando com qsort.
//
//   Saída esperada:
//   maior intervalo: 160 min, entre 17:30 e 20:10
//   conferindo com qsort: 160 min
//
// Dicas:
// 1. Por que funciona: os N - 1 intervalos entre vizinhos somam
//    maior - menor, então o maior intervalo é pelo menos a média, que é
//    L. Dois horários no mesmo balde distam menos que L.
// 2. Teto com inteiros: (maior - menor + N - 2) / (N - 1). O balde de x é
//    (x - menor) / L, que vai de 0 a N - 1.
// 3. O balde 0 sempre tem o menor horário: comece com anterior = maior do
//    balde 0 e pule os baldes vazios.
// 4. Para mostrar a hora: sprintf(s, "%02d:%02d", m / 60, m % 60).
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10

int main(void) {
    // partidas do ônibus, em minutos desde a meia-noite (fora de ordem)
    int partidas[N] = {345, 1210, 480, 615, 390, 905, 1300, 760, 1050, 530};
    (void) partidas; // apague esta linha

    return 0;
}
