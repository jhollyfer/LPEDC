// 0144 · Árvores gerais
// Exercício E864 · ★★★
//
// Monte a árvore pela entrada. Cada linha tem "pai nome valor"; na primeira,
// o pai é "-" e o nome é a raiz. Um filho novo entra no fim da fila de
// irmãos do pai. Se o pai não existir, avise e ignore a linha. No fim,
// mostre a árvore (ag_mostra), o número de nós, a altura e qual filho da raiz
// tem o maior total. Sem nenhuma linha, mostre "Árvore vazia".
//
// Teste com:
//   printf -- '- casamento 0\ncasamento buffet 0\nbuffet salgados 1800\nbuffet bolo 950\ncasamento decoracao 0\ndecoracao flores 1200\nigreja padre 300\ndecoracao luzes 400\ncasamento musica 2500\nbuffet doces 700\n' | ~/LPEDC/rodar 22-arvores-avancadas/0144-arvores-gerais/E864.c
//
//   Saída esperada:
//   pai igreja não existe: linha ignorada
//   casamento: 7550
//     buffet: 3450
//       salgados: 1800
//       bolo: 950
//       doces: 700
//     decoracao: 1600
//       flores: 1200
//       luzes: 400
//     musica: 2500
//   Itens: 9 | altura: 2
//   Maior gasto: buffet (R$ 3450)
//
// Dicas:
// 1. Leia cada linha com fgets e separe com sscanf(linha, "%19s %19s %d",
//    pai, nome, &valor) == 3. Linha que não casa, ignore.
// 2. A primeira linha válida cria a raiz com ag_cria. Nas outras, ag_busca
//    acha o pai e ag_adiciona pendura o filho.
// 3. Para o maior gasto, ande pelos filhos da raiz comparando ag_total.
//    Resposta esperada: a saída acima. Não esqueça do ag_libera no fim.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "arvgen.h"

int main(void) {

    return 0;
}
