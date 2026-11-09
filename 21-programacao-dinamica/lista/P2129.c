// Lista · Módulo 21 · Programação dinâmica
// Exercício P2129 · ★★★ · Juntar os sacos vizinhos
//
// No armazém, 6 sacos de farinha estão enfileirados, com 4, 7, 2, 6, 3 e 5
// kg. A máquina junta DOIS SACOS VIZINHOS num só, e o custo da operação é
// o peso do saco resultante. Ela repete até sobrar um saco. Qual a ordem
// mais barata? Se desse para juntar quaisquer dois (não só vizinhos), o
// guloso de Huffman (módulo 20) resolveria. Com a regra dos vizinhos, o
// guloso falha e entra a PD DE INTERVALOS: c[i][j] é o menor custo para
// transformar os sacos i..j em um; c[i][i] = 0 e c[i][j] = min, para k de
// i a j - 1, de c[i][k] + c[k + 1][j] + soma(i, j). Escreva do zero as
// duas contas e mostre a ordem ótima entre vizinhos como parênteses.
//
//   Saída esperada:
//   Só vizinhos: custo 70 com ((4 7) ((2 6) (3 5)))
//   Quaisquer dois (Huffman): custo 68
//
// Dicas:
// 1. É a mesma forma da multiplicação em cadeia: preencha por tamanho de
//    trecho e guarde o k ótimo em s[i][j].
// 2. Para o custo "quaisquer dois", repita: ache os dois menores pesos,
//    some o resultado ao custo e troque os dois pelo resultado (com 6
//    sacos, dois laços simples bastam).
// 3. Resposta esperada: o custo entre vizinhos é maior que o de Huffman,
//    e a ordem ótima está na saída.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
