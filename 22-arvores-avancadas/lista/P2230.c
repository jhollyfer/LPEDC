// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2230 · ★★★ · Três árvores, mil chaves
//
// Escreva do zero, no mesmo programa, três estruturas de busca: a árvore
// de busca comum (sem balanceamento), a rubro-negra esquerdista e a árvore
// B com t = 2. Insira as chaves 0 a 999 em dois cenários: (a) em ordem
// crescente; (b) na ordem de s = (s * 41 + 11) % 1000 a partir de s = 0
// (passa por todos os números, embaralhados). Mostre a altura de cada uma
// em cada cenário: para as binárias, o número de nós do caminho mais
// longo; para a B, o número de níveis.
//
//   Saída esperada:
//   Em ordem: comum 1000, rubro-negra 10, B 9 níveis
//   Embaralhadas: comum 24, rubro-negra 13, B 8 níveis
//
// Dicas:
// 1. Com 1000 chaves em ordem, a árvore comum vira uma lista: a inserção
//    recursiva desce 1000 níveis. Funciona, mas faça a inserção da árvore
//    comum iterativa (com um ponteiro para ponteiro) para não depender do
//    tamanho da pilha.
// 2. A altura da árvore comum em ordem crescente também é melhor calcular
//    sem recursão profunda: como ela só tem filhos à direita, ande pelo
//    dir contando; para o caso geral, a recursão desce no máximo a altura.
// 3. Resposta esperada: a árvore comum tem altura 1000 em ordem e 24
//    embaralhada; a rubro-negra fica com 10 e 13, e a B com 9 e 8 níveis.
//    Balancear é garantir o pior caso, não melhorar o caso médio.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
