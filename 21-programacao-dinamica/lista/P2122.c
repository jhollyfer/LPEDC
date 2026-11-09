// Lista · Módulo 21 · Programação dinâmica
// Exercício P2122 · ★★★ · Todas as maiores subsequências comuns
//
// A LCS nem sempre é única. Entre ABCBDAB e BDCABA (o exemplo clássico do
// Cormen) há várias sequências de tamanho máximo. Escreva do zero: monte a
// tabela da LCS e depois uma recursão que, a partir de (m, n), gera TODAS
// as LCS: se as letras são iguais, a letra entra e você vai na diagonal;
// senão, siga para CADA vizinho (de cima e da esquerda) que tem o mesmo
// valor da casa atual. Caminhos diferentes podem dar a mesma string: guarde
// as achadas num vetor de strings e só acrescente as novas. Mostre-as em
// ordem alfabética (qsort com strcmp).
//
//   Saída esperada:
//   LCS de ABCBDAB e BDCABA: tamanho 4
//     BCAB
//     BCBA
//     BDAB
//   3 sequências diferentes
//
// Dicas:
// 1. gera(i, j, buf, pos): buf é preenchido de trás para a frente; pos
//    começa no tamanho da LCS. Quando pos == 0 (ou i == 0 ou j == 0),
//    copie buf + pos para a lista, se for nova.
// 2. Na comparação do qsort, os elementos são char[8]: use strcmp(a, b)
//    direto nos ponteiros recebidos.
// 3. Resposta esperada: 3 LCS de 4 letras: BCAB, BCBA e BDAB.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
