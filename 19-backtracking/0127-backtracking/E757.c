// 0127 · Backtracking
// Exercício E757 · ★☆☆
//
// Para a trilha do fim de semana, a mochila tem que pesar exatamente 12 kg
// (nem mais, para não cansar, nem menos, para não faltar nada). Os itens
// pesam: barraca 7, comida 5, água 4, saco de dormir 3 e fogareiro 2. O
// programa abaixo enumera todas as escolhas, mas ainda não poda nada: ele
// mostra as soluções certas e faz 63 chamadas. Complete os dois testes do
// começo da função tenta (a poda e a solução) para que ele faça só o
// necessário.
//
//   Saída esperada:
//   barraca comida
//   barraca saco fogareiro
//   comida água saco
//   45 chamadas
//
// Dicas:
// 1. Primeiro teste: se soma passou de ALVO, volte.
// 2. Segundo teste: se soma é igual a ALVO, mostre leva[0..i-1] e volte.
//    Esse teste precisa vir ANTES do if (i == N), senão "barraca saco
//    fogareiro" (que fecha com o último item) se perde.
// 3. Quando tudo estiver certo, apague o bloco do if (i == N) que mostra a
//    solução: com o seu segundo teste, ele vira só "return;".
// 4. Resposta esperada: as 4 linhas acima.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdbool.h>
#include <stdio.h>

#define N 5
#define ALVO 12

const char *itens[N] = {"barraca", "comida", "água", "saco", "fogareiro"};
const int pesos[N] = {7, 5, 4, 3, 2};
bool leva[N];
int chamadas = 0;

void mostra(int ate) {
    int primeiro = 1;
    for (int j = 0; j < ate; j++) {
        if (leva[j]) {
            printf(primeiro ? "%s" : " %s", itens[j]);
            primeiro = 0;
        }
    }
    printf("\n");
}

void tenta(int i, int soma) {
    chamadas++;
    // complete aqui: a poda e a solução

    if (i == N) {
        if (soma == ALVO) {
            mostra(N);
        }
        return;
    }
    leva[i] = true;
    tenta(i + 1, soma + pesos[i]);
    leva[i] = false;
    tenta(i + 1, soma);
}

int main(void) {
    tenta(0, 0);
    printf("%d chamadas\n", chamadas);
    return 0;
}
