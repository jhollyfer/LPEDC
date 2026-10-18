// 0131 · Divisão e conquista
// Exercício E784 · ★★☆
//
// Uma trilha de 10 km foi medida a cada quilômetro. A altitude só sobe até
// o pico e depois só desce (o pico não fica nas pontas):
//
//   km:       0    1    2    3    4    5    6    7    8    9   10
//   altitude: 820  905 1010 1180 1340 1415 1390 1250 1100  960  870
//
// Escreva int pico(const int v[], int ini, int fim), que acha o índice do
// ponto mais alto SEM olhar todos os pontos. Divisão e conquista com um
// pedaço só, como a busca binária: olhe o meio e o vizinho da direita. Se
// ainda está subindo, o pico está à direita do meio; senão, está no meio ou
// à esquerda. Conte numa variável global quantas vezes comparou v[meio] com
// v[meio + 1].
//
//   Saída esperada:
//   Pico: 1415 m no km 5
//   Comparações: 3
//
// Dicas:
// 1. Caso base: ini == fim, sobrou um ponto só, e ele é o pico.
// 2. Se v[meio] < v[meio + 1], chame pico(v, meio + 1, fim); senão,
//    pico(v, ini, meio). Repare que o meio continua no segundo caso.
// 3. Resposta esperada: a saída acima. Os pedaços são [0, 10], [0, 5],
//    [3, 5], [5, 5]. Com 1 milhão de pontos seriam umas 20 comparações:
//    O(log n), contra O(n) de procurar o maior com um laço.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int altitude[] = {820, 905, 1010, 1180, 1340, 1415, 1390, 1250, 1100, 960, 870};
    int n = 11;
    (void)altitude;
    (void)n;

    return 0;
}
