// 0117 · Limite inferior da ordenação
// Exercício E698 · ★☆☆
//
// Com 4 elementos, o limite é ⌈log₂ 24⌉ = 5 comparações no pior caso. O
// insertion sort chega lá? Teste nas 24 ordens possíveis de 4 preços
// (10, 20, 30 e 40): gere as ordens com quatro laços aninhados (a, b, c, d
// de 0 a 3, todos diferentes), monte v = {precos[a], precos[b], precos[c],
// precos[d]}, ordene com o insertion sort abaixo contando as comparações e
// mostre o melhor caso, o pior, em quantas ordens o pior acontece e a
// média:
//
//   Saída esperada:
//   24 ordens testadas
//   melhor: 3, pior: 6 (em 8 ordens), média: 4.92
//   limite inferior: 5
//
// Dicas:
// 1. Para pular as combinações com índices repetidos, use continue quando
//    a == b || a == c || ... (são 6 pares para testar).
// 2. Conte as comparações dentro de uma função maior(a, b) que soma 1 num
//    contador global e devolve a > b; use-a no while do insertion.
// 3. Ao achar um pior novo, zere o contador de "quantas no pior".
// 4. Resposta esperada: a saída acima. O insertion de 4 não é ótimo: faz
//    6 no pior caso, um a mais que o limite (o exercício E702 mostra um
//    método com 5). A média 4,92 abaixo de 5 não contradiz nada: o limite
//    é de pior caso.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

void insertion(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int x = v[i], j = i - 1;
        while (j >= 0 && v[j] > x) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
    }
}

int main(void) {
    int precos[4] = {10, 20, 30, 40};
    (void)precos; // apague esta linha

    return 0;
}
