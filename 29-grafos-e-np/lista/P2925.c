// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2925 · ★★★ · De 3-SAT para conjunto independente
//
// Outra redução clássica: 3-SAT para CONJUNTO INDEPENDENTE. Cada literal de
// cada cláusula vira um vértice; ligue (1) os três vértices de uma mesma
// cláusula entre si (um triângulo) e (2) todo par de vértices
// contraditórios (x e não x), em qualquer cláusula. A fórmula é
// satisfatível se e só se o grafo tem um conjunto independente de tamanho
// m (o número de cláusulas). Para
//
//   (x1 ou x2 ou não x3) (não x1 ou x3 ou x4) (não x2 ou não x4 ou x3)
//   (x1 ou não x3 ou não x4)
//
// monte o grafo, mostre quantas arestas ele tem, procure pela força bruta
// (máscaras de 12 bits com exatamente 4 bits ligados, em ordem crescente)
// o primeiro conjunto independente de tamanho 4 e traduza-o numa
// atribuição (variável não escolhida fica falsa). Confira a atribuição na
// fórmula.
//
//   Saída esperada:
//   Grafo: 12 vértices, 21 arestas
//   Independente: x1 x3 não x2 x1
//   Atribuição: x1=V x2=F x3=V x4=F
//   Satisfaz a fórmula? sim
//
// Dicas:
// 1. O vértice a é o literal f[a / 3][a % 3]. Aresta se a / 3 == b / 3 ou
//    f(a) == -f(b).
// 2. Um independente de tamanho m pega exatamente um literal por cláusula (o
//    triângulo impede dois) e nunca x junto com não x.
// 3. Resposta esperada: a saída acima. São 12 arestas dos triângulos mais as
//    dos pares contraditórios.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
