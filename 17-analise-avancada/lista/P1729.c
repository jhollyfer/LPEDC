// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1729 · ★★★ · A roda do amigo-secreto: simular ou recorrer?
//
// Na roda de n pessoas, numeradas de 1 a n no sentido horário, a pessoa 1
// começa: ela "pula" a vizinha, que sai da roda, e a vez passa para a pessoa
// seguinte à que saiu. Isso se repete (sai uma, pula uma) até sobrar uma,
// que escolhe o primeiro presente. É o problema de Josephus com passo 2.
//
// Dois jeitos de achar quem sobra:
//
// - SIMULAR com uma lista circular encadeada (malloc): n - 1 remoções, cada
//   uma com um passo de ponteiro: Θ(n) passos.
// - RECORRER: J(1) = 1, J(2m) = 2 J(m) - 1 e J(2m + 1) = 2 J(m) + 1. Uma
//   chamada com n/2: C(n) = C(n/2) + 1 = ⌊lg n⌋ + 1 chamadas.
//
// Escreva os dois, contando passos e chamadas, e confira com a fórmula
// fechada J(n) = 2(n - 2^⌊lg n⌋) + 1. Rode para n = 5, 10, 41, 1000 e
// 100000.
//
//   Saída esperada:
//        n  simulação  passos  recursão  chamadas  fórmula
//        5          3       4         3         3        3
//       10          5       9         5         4        5
//       41         19      40        19         6       19
//     1000        977     999       977        10      977
//   100000      68929   99999     68929        17    68929
//
// Dicas:
// 1. Lista circular: crie os nós 1..n, ligue o último ao primeiro e guarde
//    em atual a pessoa da vez. Remover: alvo = atual->prox; atual->prox =
//    alvo->prox; free(alvo); atual = atual->prox (conte 1 passo).
// 2. Sobra um nó só quando atual->prox == atual. Libere-o no fim.
// 3. Na recursão, J(m) é a resposta para metade da roda: depois da primeira
//    volta, só sobram os ímpares, e a numeração deles é "dobrada".
// 4. Resposta esperada: sobram 3, 5, 19, 977 e 68929; a simulação gasta
//    n - 1 passos, a recursão no máximo 17 chamadas.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa {
    int num;
    struct Pessoa *prox;
} Pessoa;

int main(void) {

    return 0;
}
