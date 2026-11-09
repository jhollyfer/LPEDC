// Lista · Módulo 21 · Programação dinâmica
// Exercício P2123 · ★★★ · A árvore de busca ótima do dicionário
//
// Um dicionário de bolso tem 5 palavras, em ordem alfabética, e se sabe
// quantas vezes cada uma é procurada por mil buscas:
//
//   chave    açaí  boto  cuia  jambu  tacacá
//   buscas    15    10    5     40     30
//
// Numa árvore binária de busca, procurar uma chave na profundidade p (a
// raiz tem profundidade 1) custa p comparações. Qual árvore minimiza o
// custo total (soma de buscas · profundidade)? Esta é a ÁRVORE DE BUSCA
// ÓTIMA (Cormen 15.5, aqui sem as buscas que falham). Escreva do zero a
// PD: c[i][j] é o custo ótimo para as chaves i..j; escolhendo a raiz r,
// c[i][j] = c[i][r - 1] + c[r + 1][j] + soma das buscas de i a j (todas
// descem um nível). Mostre o custo, a raiz de cada subárvore em pré-ordem e
// compare com a árvore "equilibrada" de raiz cuia.
//
//   Saída esperada:
//   Custo ótimo: 180 comparações
//     jambu (nível 1)
//     açaí (nível 2)
//     boto (nível 3)
//     cuia (nível 4)
//     tacacá (nível 2)
//   Raiz cuia: 235 comparações
//
// Dicas:
// 1. Use índices de 1 a 5 e c[i][i - 1] = 0 (trecho vazio). Preencha por
//    tamanho de trecho, como na cadeia de matrizes, guardando raiz[i][j].
// 2. pre(i, j, prof): se i > j, volte; senão mostre a chave raiz[i][j] com
//    a profundidade e chame para os dois lados com prof + 1.
// 3. Resposta esperada: custo 190, com jambu na raiz. A árvore de raiz
//    cuia (açaí e boto à esquerda, jambu e tacacá à direita) custa mais:
//    veja na saída.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
