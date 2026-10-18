// 0047 · Lendo strings
// Exercício E281 · ★★★
//
// Monte uma lista de compras. Leia até 5 itens, um por linha, com fgets,
// guardando cada um numa linha da matriz char itens[5][16] (até 15
// caracteres por item). A leitura para numa linha vazia, no fim da entrada
// (EOF) ou quando a lista enche.
//
// Se a pessoa digitar um item com mais de 15 caracteres, guarde só o que
// coube, mostre "(cortado)" e jogue fora o resto da linha: senão o resto vira
// o próximo item!
//
// No fim, mostre a lista numerada e qual item vem primeiro em ordem
// alfabética.
//
//   Exemplo de execução:
//   Item: leite
//   Item: feijao preto
//   Item: arroz
//   Item: detergente de coco neutro
//   (cortado)
//   Item:
//   Lista com 4 itens:
//   1. leite
//   2. feijao preto
//   3. arroz
//   4. detergente de c
//   Primeiro em ordem alfabética: arroz
//
// Dicas:
// 1. fgets(itens[n], sizeof(itens[n]), stdin): cada linha da matriz é uma
//    string de 16 bytes.
// 2. Depois do fgets, procure o '\n' com strcspn. Se achou, troque por '\0'.
//    Se não achou, a linha não coube: descarte o resto com o laço do getchar.
// 3. Linha vazia: depois de tirar o '\n', strlen(itens[n]) == 0.
// 4. Para o primeiro em ordem alfabética, guarde o ÍNDICE do menor e compare
//    com strcmp(itens[i], itens[menor]) < 0.
// 5. Resposta esperada: a execução acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

#define MAX_ITENS 5
#define TAM_ITEM 16

int main(void) {

    return 0;
}
