// 0146 · Árvore B
// Exercício E876 · ★★★
//
// Escreva do zero uma árvore B de grau mínimo T = 3: cada nó guarda de 2 a 5
// chaves (a raiz pode ter 1) e tem até 6 filhos. Use a inserção com divisão
// na descida, como no texto, mas com T e MAX definidos no seu arquivo (o TAD
// arvoreb.h tem T = 2 fixo). Insira i * 7 % 31 para i de 1 a 30 (são os
// números de 1 a 30, embaralhados: 7, 14, 21, 28, 4, 11...). Mostre a árvore
// por nível e o resultado de duas buscas, contando os blocos lidos.
//
//   Saída esperada:
//   nível 0: [14]
//   nível 1: [4 7 11] [18 21 26]
//   nível 2: [1 2 3] [5 6] [8 9 10] [12 13] [15 16 17] [19 20] [22 23 24 25] [27 28 29 30]
//   busca 23: achou, 3 blocos lidos
//   busca 31: não achou, 3 blocos lidos
//
// Dicas:
// 1. Struct com int n, int chave[MAX], ponteiros filho[MAX + 1] e bool
//    folha, com #define T 3 e #define MAX (2 * T - 1). Nenhuma linha da
//    divisão depende de T valer 2: escreva tudo com T e MAX.
// 2. Na divisão, a chave do meio é a de índice T - 1; o nó novo recebe as
//    T - 1 chaves dos índices T a MAX - 1 e, se não for folha, os T filhos
//    dos índices T a MAX.
// 3. Resposta esperada: a saída acima. Com 3 chaves por nó (T = 2), as
//    mesmas 30 chaves precisariam de mais um nível.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
