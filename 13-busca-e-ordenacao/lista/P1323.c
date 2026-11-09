// Lista · Módulo 13 · Busca e ordenação
// Exercício P1323 · ★★★ · Mediana de três contra o vetor ordenado
//
// O quick sort com pivô no fim cai no pior caso justamente quando a lista
// já vem ordenada, o que é comum (planilha exportada, senhas em ordem). A
// defesa clássica é a MEDIANA DE TRÊS: antes de cada partição de v[p..r]
// (com pelo menos 3 elementos), olhe v[p], v[m] e v[r], com
// m = p + (r - p) / 2, ponha os três em ordem com até 3 trocas e leve a
// mediana (que ficou em m) para v[r]. A partição de Lomuto não muda.
//
// Escreva void quick(int v[], int p, int r, bool mediana) e conte as
// comparações v[j] <= pivo (global comparacoes). Para cada vetor de 15
// elementos (crescente 1..15, decrescente 15..1 e o misturado do esqueleto),
// ordene uma cópia com cada versão e mostre:
// printf("%-11s pivô no fim: %3d   mediana de três: %3d\n", ...).
//
//   Saída esperada:
//   crescente   pivô no fim: 105   mediana de três:  34
//   decrescente pivô no fim: 105   mediana de três:  38
//   misturado   pivô no fim:  37   mediana de três:  36
//
// Dicas:
// 1. Ordene os três assim: se v[m] < v[p], troca; se v[r] < v[p], troca; se
//    v[r] < v[m], troca. Depois, troca v[m] com v[r].
// 2. Só conte as comparações da partição (as 3 da mediana ficam de fora).
// 3. 105 = 15 · 14 / 2: o pior caso. Com a mediana, o pivô do vetor ordenado
//    é o elemento do meio, e o quick volta a dividir ao meio.
// 4. No vetor misturado quase não muda nada: a mediana não deixa o caso
//    médio pior, só tira o pior caso dos dados "fáceis".
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>

int comparacoes;

int main(void) {
    int crescente[15], decrescente[15];
    int misturado[15] = {8, 14, 3, 11, 1, 6, 15, 9, 2, 12, 5, 13, 7, 4, 10};
    for (int i = 0; i < 15; i++) {
        crescente[i] = i + 1;
        decrescente[i] = 15 - i;
    }
    (void)crescente;
    (void)decrescente;
    (void)misturado;

    return 0;
}
