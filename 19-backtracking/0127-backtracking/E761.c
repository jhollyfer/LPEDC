// 0127 · Backtracking
// Exercício E761 · ★★★
//
// Ache o bug. No buffet a quilo, você quer montar um prato de sobremesas com
// exatamente 500 g. As porções pesam: pudim 250 g, mousse 200 g, torta
// 150 g, gelatina 100 g e brigadeiro 50 g. Para economizar parâmetros, o
// autor guardou a soma numa variável GLOBAL. O programa compila sem aviso e
// roda, mas não mostra nenhuma combinação. Ache o erro, conserte (sem
// transformar a soma em parâmetro) e rode de novo.
//
//   Saída esperada:
//   pudim mousse brigadeiro
//   pudim torta gelatina
//   mousse torta gelatina brigadeiro
//
// Dicas:
// 1. Mostre soma no começo de cada chamada. Depois de voltar do caminho
//    "com o item", quanto ela vale?
// 2. Com a soma em parâmetro, voltar desfaz a escolha de graça. Global, ela
//    é uma só para todas as chamadas: quem soma precisa subtrair na volta.
// 3. Resposta esperada: falta soma -= porcoes[i]; logo depois da primeira
//    chamada recursiva (antes de tentar sem o item). Com isso, a saída é a
//    de cima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdbool.h>
#include <stdio.h>

#define N 5
#define ALVO 500

const char *nomes[N] = {"pudim", "mousse", "torta", "gelatina", "brigadeiro"};
const int porcoes[N] = {250, 200, 150, 100, 50};
bool leva[N];
int soma = 0;

void tenta(int i) {
    if (soma > ALVO) {
        return;
    }
    if (soma == ALVO) {
        int primeiro = 1;
        for (int j = 0; j < i; j++) {
            if (leva[j]) {
                printf(primeiro ? "%s" : " %s", nomes[j]);
                primeiro = 0;
            }
        }
        printf("\n");
        return;
    }
    if (i == N) {
        return;
    }
    leva[i] = true;
    soma += porcoes[i];
    tenta(i + 1);
    leva[i] = false;
    tenta(i + 1);
}

int main(void) {
    tenta(0);
    return 0;
}
