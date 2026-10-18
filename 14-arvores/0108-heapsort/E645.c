// 0108 · Heapsort
// Exercício E645 · ★★☆
//
// Existem dois jeitos de montar o heap da fase 1: inserir os elementos um a
// um (cada um SOBE, como no heap_insere) ou descer cada pai, do último até a
// raiz (o jeito do texto). Escreva as duas funções, contando as trocas, e
// rode nos tempos da corrida:
//
//   Saída esperada:
//   Por inserções:    [91 73 66 18 40 25 52], 5 trocas
//   Descendo os pais: [91 52 73 40 18 25 66], 2 trocas
//
// Os dois vetores são heaps? Por que deram diferentes?
//
// Dicas:
// 1. Por inserções: para k de 1 até n - 1, faça v[k] subir enquanto for
//    maior que v[(k - 1) / 2]. A parte v[0..k-1] já é heap.
// 2. Some 1 no contador a cada troca (passe um int * para as funções).
// 3. Resposta esperada: a saída acima. Os dois são heaps válidos: a regra
//    só exige pai >= filhos, e existem vários vetores que a respeitam. O
//    método dos pais faz menos trabalho porque metade dos elementos (as
//    folhas) nem se mexe; em geral ele é O(n) e o das inserções, O(n log n).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int a[] = {52, 18, 73, 40, 91, 25, 66};
    int b[] = {52, 18, 73, 40, 91, 25, 66};
    (void)a; // apague estas duas linhas
    (void)b;

    return 0;
}
