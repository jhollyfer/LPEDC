// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2029 · ★★★ · Juntando as notas de quatro turmas
//
// A secretaria tem as notas de 4 turmas, cada lista já em ordem crescente,
// e quer uma lista única ordenada. Intercalar uma a uma (a primeira com a
// segunda, o resultado com a terceira...) faz os primeiros elementos serem
// comparados de novo a cada rodada. Por divisão e conquista, intercale as
// turmas 0 e 1, as 2 e 3, e depois os dois resultados: com k listas são
// só lg k rodadas. Escreva do zero intercala(a, na, b, nb, saida), que
// conta as comparações, e as duas estratégias. Mostre a lista final e as
// comparações de cada uma.
//
//   Turma 0: 52 61 78 90 95          Turma 1: 48 55 70
//   Turma 2: 35 66 74 81 88 93 99    Turma 3: 40 59
//
//   Saída esperada:
//   Lista: 35 40 48 52 55 59 61 66 70 74 78 81 88 90 93 95 99
//   Uma a uma: 25 comparações
//   Divisão e conquista: 24 comparações
//   Listas iguais: sim
//
// Dicas:
// 1. A intercalação do merge sort: compare a[i] com b[j] (1 comparação),
//    copie o menor; quando uma acabar, copie o resto da outra sem comparar.
// 2. junta(listas, ini, fim): com ini == fim devolve a própria lista; senão
//    junta a metade de cima, a de baixo e intercala as duas. Use vetores
//    locais de tamanho 17 (o total).
// 3. Resposta esperada: a mesma lista, com 25 comparações uma a uma e 24
//    por divisão e conquista. A diferença é pequena com listas curtas; com
//    k listas de m notas, uma a uma custa O(k² m) e a divisão e conquista,
//    O(k m lg k).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
