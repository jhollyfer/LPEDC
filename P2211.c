// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2211 · ★★☆ · O fiscal completo da rubro-negra
//
// Escreva do zero o fiscal da rubro-negra clássica (Cormen), que confere,
// nesta ordem, as regras que fazem sentido num nó com cor: (1) é árvore de
// busca (cada chave entre um mínimo e um máximo herdados); (2) a raiz é
// preta; (3) nenhum vermelho tem filho vermelho; (4) todo caminho até um
// NULL tem o mesmo número de pretos. Ele devolve o número da primeira
// regra quebrada (0 se todas valem) e, se valem, a altura negra. Teste as
// quatro árvores do main (raiz(esquerda, direita), - é vazio):
//
//   A: 40P(20V(10P, 30P), 60V(50P, 70P))
//   B: 40P(20P(10V, 30V), 60P(50V, 45V))
//   C: 40V(20P, 60P)
//   D: 40P(20P(10P, -), 60P(50V, 70P))
//
//   Saída esperada:
//   A: rubro-negra válida, altura negra 2
//   B: quebra a regra 1
//   C: quebra a regra 2
//   D: quebra a regra 4
//
// Dicas:
// 1. Regra 1: busca_ok(r, min, max), com INT_MIN e INT_MAX de <limits.h>
//    no começo; cada chave tem que ficar estritamente entre os limites.
// 2. Regras 3 e 4 juntas numa recursão que devolve a altura negra ou -1;
//    separe as duas com um flag global para saber qual quebrou.
// 3. Resposta esperada: A vale (altura negra 2); B quebra a regra 1 (45 à
//    direita de 60); C quebra a 2; D quebra a 4.
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
