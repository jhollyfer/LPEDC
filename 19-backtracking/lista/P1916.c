// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1916 · ★★☆ · Pacotes de pão de queijo
//
// A padaria embala pão de queijo em pacotes de 3, 4 e 5 unidades, e pode
// usar quantos pacotes de cada tamanho quiser. Uma encomenda de 15 pães
// pode sair como 5 + 5 + 5, como 3 + 3 + 4 + 5 e de outros jeitos. Escreva
// do zero um backtracking que lista todos os jeitos, cada um em ordem
// crescente de pacote (3 + 4 + 4 + 4 e 4 + 3 + 4 + 4 são o mesmo jeito),
// e o total.
//
//   Saída esperada:
//   3 + 3 + 3 + 3 + 3
//   3 + 3 + 4 + 5
//   3 + 4 + 4 + 4
//   5 + 5 + 5
//   Total: 4 jeitos
//
// Dicas:
// 1. É combinação COM repetição: escolhe(menor, falta) tenta os pacotes do
//    índice menor em diante, e pode escolher o mesmo de novo (chama com
//    menor = j, não j + 1).
// 2. Corte quando o pacote não cabe no que falta. Com falta == 0, mostre.
// 3. Resposta esperada: 6 jeitos.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
