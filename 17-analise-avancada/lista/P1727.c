// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1727 · ★★★ · Montar o heap: n inserções ou BUILD-HEAP?
//
// A central do SAMU recebe de uma vez a lista de chamados do turno e precisa
// de um heap MÍNIMO pela gravidade (1 é o mais grave). Há dois jeitos:
//
// - inserir um por um: cada inserção sobe o novo item, até lg i trocas. Total
// O(n lg n);
// - BUILD-HEAP (Floyd): põe tudo no vetor e chama "desce" para i de n/2 - 1
// até 0. Um nó de altura h desce no máximo h níveis, e só ~n/2^(h+1) nós
// têm altura h: a soma Σ h · n/2^(h+1) é menor que n. Total O(n).
//
// Implemente os dois, contando as TROCAS, e teste no pior caso de cada um:
// gravidades em ordem DECRESCENTE (n, n - 1, ..., 1), com n = 2^k - 1 para
// k = 4, 8, 12, 16 e 20. Mostre as trocas, n lg n e n, e confira que os dois
// heaps são válidos.
//
//   Saída esperada:
//         n   inserindo   build-heap      n lg n  válidos
//        15          34           11          59      sim
//       255        1538          247        2039      sim
//      4095       40962         4083       49139      sim
//     65535      917506        65519     1048559      sim
//   1048575    18874370      1048555    20971499      sim
//
// Dicas:
// 1. Em ordem decrescente, cada novo item é o menor de todos: sobe até a
//    raiz. São ⌊lg i⌋ trocas para o i-ésimo item.
// 2. No BUILD-HEAP, cada nó desce até uma folha. Para n = 2^k - 1, a soma das
//    alturas dá exatamente n - k.
// 3. Heap mínimo válido: v[(i - 1) / 2] <= v[i] para todo i >= 1.
// 4. Resposta esperada: com n = 1048575, 18874370 trocas inserindo e 1048555
//    com BUILD-HEAP (n - 20).
//
// Escreva sua resposta abaixo:

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
