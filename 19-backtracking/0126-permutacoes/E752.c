// 0126 · Permutações
// Exercício E752 · ★☆☆
//
// Lia, Max e Nina vão tirar uma foto lado a lado e querem ver todas as
// ordens possíveis. O programa abaixo usa o vetor usado[] (como no exemplo
// A251) em vez de trocas, mas faltam três linhas dentro do laço: marcar a
// pessoa como usada, colocá-la na posição pos da foto e desmarcar depois da
// chamada recursiva. Complete.
//
//   Saída esperada:
//   Lia Max Nina
//   Lia Nina Max
//   Max Lia Nina
//   Max Nina Lia
//   Nina Lia Max
//   Nina Max Lia
//
// Dicas:
// 1. A posição pos da foto guarda o ÍNDICE da pessoa: foto[pos] = p.
// 2. Marque usado[p] = true antes de chamar fotos(pos + 1) e volte para
//    false depois. Se esquecer de desmarcar, só a primeira linha aparece.
// 3. Resposta esperada: as 6 linhas acima (repare que, ao contrário das
//    trocas do texto, esta saída está em ordem alfabética).
//
// Escreva sua resposta abaixo (complete o código):

#include <stdbool.h>
#include <stdio.h>

#define N 3

const char *pessoas[N] = {"Lia", "Max", "Nina"};
int foto[N];
bool usado[N];

void fotos(int pos) {
    if (pos == N) {
        printf("%s %s %s\n", pessoas[foto[0]], pessoas[foto[1]], pessoas[foto[2]]);
        return;
    }
    for (int p = 0; p < N; p++) {
        if (usado[p]) {
            continue;
        }
        // complete aqui: marque, ponha na foto, desça e desmarque

        fotos(pos + 1);

    }
}

int main(void) {
    fotos(0);
    return 0;
}
