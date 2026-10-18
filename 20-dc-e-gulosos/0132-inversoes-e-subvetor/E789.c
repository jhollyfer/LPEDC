// 0132 · Inversões e subvetor de soma máxima
// Exercício E789 · ★★☆
//
// Você e a Bia ranquearam os mesmos seis pratos, do favorito ao último:
//
//   você: Feijoada, Moqueca, Coxinha, Acarajé, Pastel, Pão de queijo
//   Bia:  Moqueca, Coxinha, Feijoada, Pão de queijo, Acarajé, Pastel
//
// Mostre cada par de pratos em que vocês discordam (no formato "A x B", com
// A antes de B no SEU ranking) e o total. O truque: monte um vetor v em que
// v[i] é a posição, no ranking da Bia, do seu i-ésimo prato. Os pares em
// desacordo são exatamente as inversões de v.
//
//   Saída esperada:
//   Feijoada x Moqueca
//   Feijoada x Coxinha
//   Acarajé x Pão de queijo
//   Pastel x Pão de queijo
//   Pares em desacordo: 4 de 15
//
// Dicas:
// 1. Escreva int posicao(const char *lista[], int n, const char *nome), uma
//    busca sequencial (assunto 0089) com strcmp.
// 2. Para seu ranking, v fica 2 0 1 4 5 3. Agora é o E787 com nomes: dois
//    laços, e quando v[i] > v[j] mostre meu[i] e meu[j].
// 3. Resposta esperada: a saída acima. Com 6 itens, 4 desacordos em 15
//    pares: os gostos batem em 11/15, uns 73%.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

#define N 6

int main(void) {
    const char *meu[N] = {"Feijoada", "Moqueca", "Coxinha", "Acarajé", "Pastel", "Pão de queijo"};
    const char *dela[N] = {"Moqueca", "Coxinha", "Feijoada", "Pão de queijo", "Acarajé", "Pastel"};
    (void)meu;
    (void)dela;

    return 0;
}
