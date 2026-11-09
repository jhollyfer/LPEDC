// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2023 · ★★★ · Huffman de ida e volta
//
// Escreva do zero, sem o TAD do módulo, um Huffman completo para a frase
//
//   MANAUS AMAZONAS
//
// (1) conte as frequências dos caracteres; (2) monte a árvore com um
// heap-mínimo de índices de nós, escrito à mão (sobe e desce do assunto
// de heap), juntando sempre os dois de menor frequência; (3) gere o código
// de cada caractere (esquerda = 0, direita = 1); (4) codifique a frase numa
// string de '0' e '1'; (5) decodifique essa string descendo a árvore e
// confira que voltou a frase original. Para a saída sair igual, desempate
// no heap pelo índice do nó (o menor índice sai primeiro), crie as folhas
// em ordem de código ASCII e ponha o primeiro retirado à esquerda.
//
//   Saída esperada:
//   ' ' 1 vez(es): 1010
//   'A' 5 vez(es): 11
//   'M' 2 vez(es): 010
//   'N' 2 vez(es): 011
//   'O' 1 vez(es): 1011
//   'S' 2 vez(es): 100
//   'U' 1 vez(es): 000
//   'Z' 1 vez(es): 001
//   Bits: 010110111100010010101101011001101101111100
//   15 caracteres, 42 bits (ASCII: 120)
//   Decodificado: MANAUS AMAZONAS (igual)
//
// Dicas:
// 1. Nós num vetor: folhas de 0 a f - 1, internos depois. menor(i, j)
//    compara freq e, no empate, o índice.
// 2. Para gerar os códigos, uma recursão com um buffer char cod[32] e a
//    profundidade: na folha, copie o buffer para a tabela do caractere.
// 3. Resposta esperada: 15 caracteres, 42 bits (contra 120 em ASCII de 8
//    bits) e a frase decodificada igual à original.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
