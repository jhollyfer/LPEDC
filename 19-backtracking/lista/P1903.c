// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1903 · ★☆☆ · Luzes que não ficam lado a lado
//
// Na fachada da loja há 5 lâmpadas em fila. Para economizar energia e não
// esquentar o letreiro, a regra é: nunca duas lâmpadas vizinhas acesas ao
// mesmo tempo. Escreva do zero um backtracking que monta a fila da
// esquerda para a direita, com 0 (apagada) ou 1 (acesa), e CORTA o ramo na
// hora em que ia acender uma lâmpada ao lado de outra acesa. Mostre as
// configurações válidas e o total.
//
//   Saída esperada:
//   00000
//   00001
//   00010
//   00100
//   00101
//   01000
//   01001
//   01010
//   10000
//   10001
//   10010
//   10100
//   10101
//   Total: 13 configurações
//
// Dicas:
// 1. Guarde a fila num char luz[6] com '\0' no fim. Na posição p, o 0 sempre
//    pode; o 1 só pode se p == 0 ou luz[p - 1] == '0'.
// 2. Teste o '0' antes do '1' para a saída sair na ordem de cima.
// 3. Resposta esperada: 13 configurações. Com n lâmpadas, o total segue
//    Fibonacci: 2, 3, 5, 8, 13...
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
