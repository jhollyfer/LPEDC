// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2420 · ★★☆ · Quantos trechos diferentes no DNA
//
// Quantos trechos DIFERENTES de tamanho m existem no DNA
// "ACGTACGTTACGAACGT"? Escreva distintos(dna, m) do zero com hash rolante:
// A, C, G e T valem 0, 1, 2 e 3, base B = 4 e módulo Q = 101. Para cada
// janela, compare o hash com o dos trechos já guardados; só se o hash for
// igual, confira as letras com strncmp (conte essas conferências). Trecho
// novo é guardado (hash e início) e mostrado. Rode com m = 3 e m = 4.
//
//   Saída esperada:
//   m = 3: ACG CGT GTA TAC GTT TTA CGA GAA AAC
//     9 diferentes em 15 janelas, 6 conferências
//   m = 4: ACGT CGTA GTAC TACG CGTT GTTA TTAC ACGA CGAA GAAC AACG
//     11 diferentes em 14 janelas, 3 conferências
//
// Dicas:
// 1. Guarde num vetor hash_de[] e inicio[] (64 posições bastam).
// 2. Cada janela repetida gera pelo menos uma conferência (a que acha o
//    igual); hash igual de trecho diferente também conferiria.
// 3. Resposta esperada: 9 diferentes de tamanho 3 (6 conferências) e 11 de
//    tamanho 4 (3 conferências).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
