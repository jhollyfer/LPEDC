// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1805 · ★☆☆ · O 3º posto mais barato, partição por partição
//
// O app de combustível tem o preço do litro (em centavos) em 9 postos de
// Manaus e quer o 3º MENOR preço sem ordenar tudo. Escreva o quickselect com
// a partição de Lomuto (pivô = último elemento do pedaço) e mostre cada
// partição: o pedaço [ini, fim], o pivô, a posição final dele e para que lado
// a busca continua. Use k a partir de 1 (k = 1 é o menor).
//
//   Saída esperada:
//   [0, 8] pivô 594 foi para 3 -> esquerda
//   [0, 2] pivô 579 foi para 1 -> direita
//   [2, 2] pivô 589 foi para 2 -> achou
//   3º menor preço: 589 centavos (R$ 5,89)
//
// Dicas:
// 1. Depois da partição, o pivô está na posição p, e há p - ini elementos
//    menores à esquerda dele no pedaço. Compare p com a posição procurada,
//    k - 1 (índice a partir de 0).
// 2. Se p == k - 1, achou. Se k - 1 < p, continue em [ini, p - 1]; senão, em
//    [p + 1, fim]. Só UM lado: por isso o caso médio é Θ(n), e não n lg n.
// 3. Faça iterativo (um laço while): não precisa de recursão, porque só há
//    uma chamada.
// 4. Resposta esperada: três partições, e o 3º menor preço é 589 centavos
//    (R$ 5,89).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define N 9

int main(void) {
    int preco[N] = {629, 575, 612, 599, 589, 649, 579, 605, 594};

    for (int i = 0; i < N; i++) printf("%d ", preco[i]);
    printf("\n");
    return 0;
}
