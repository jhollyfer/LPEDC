// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1722 · ★★★ · A árvore de recursão de qualquer a T(n/b) + n^k
//
// O teorema mestre é a árvore de recursão resumida. Escreva um programa que
// DESENHE a árvore, por nível, para qualquer recorrência T(n) = a T(n/b) + n^k
// com T(1) = 1 (n potência de b), e que confira o total com uma função
// recursiva que realmente soma os custos.
//
//   void arvore(int a, int b, int k, long n);
//
// Para cada nível i: o número de nós a^i, o tamanho n/b^i, o custo de cada
// nó (n/b^i)^k e o custo do nível. No fim: o total da tabela, o total da
// recursão (têm de bater) e o diagnóstico pela razão r = a / b^k entre o
// custo de um nível e o do anterior:
//
// - r > 1: o custo cresce para baixo, as FOLHAS dominam (caso 1);
// - r == 1: todos os níveis custam o mesmo, total = custo × níveis (caso 2);
// - r < 1: o custo cai, a RAIZ domina (caso 3).
//
// Rode para (8, 2, 2), (4, 2, 2) e (2, 2, 2), todas com n = 64, e para
// (9, 3, 1) com n = 81.
//
//   Saída esperada:
//   T(n) = 8 T(n/2) + n^2, n = 64
//     nível      nós  tamanho  custo/nó  custo do nível
//         0        1       64      4096            4096
//         1        8       32      1024            8192
//         2       64       16       256           16384
//         3      512        8        64           32768
//         4     4096        4        16           65536
//         5    32768        2         4          131072
//         6   262144        1         1          262144
//     total da tabela 520192, da recursão 520192
//     r = 8/4 > 1: as folhas dominam (caso 1)
//   T(n) = 4 T(n/2) + n^2, n = 64
//     nível      nós  tamanho  custo/nó  custo do nível
//         0        1       64      4096            4096
//         1        4       32      1024            4096
//         2       16       16       256            4096
//         3       64        8        64            4096
//         4      256        4        16            4096
//         5     1024        2         4            4096
//         6     4096        1         1            4096
//     total da tabela 28672, da recursão 28672
//     r = 1: 7 níveis iguais (caso 2)
//   T(n) = 2 T(n/2) + n^2, n = 64
//     nível      nós  tamanho  custo/nó  custo do nível
//         0        1       64      4096            4096
//         1        2       32      1024            2048
//         2        4       16       256            1024
//         3        8        8        64             512
//         4       16        4        16             256
//         5       32        2         4             128
//         6       64        1         1              64
//     total da tabela 8128, da recursão 8128
//     r = 2/4 < 1: a raiz domina (caso 3)
//   T(n) = 9 T(n/3) + n^1, n = 81
//     nível      nós  tamanho  custo/nó  custo do nível
//         0        1       81        81              81
//         1        9       27        27             243
//         2       81        9         9             729
//         3      729        3         3            2187
//         4     6561        1         1            6561
//     total da tabela 9801, da recursão 9801
//     r = 9/3 > 1: as folhas dominam (caso 1)
//
// Dicas:
// 1. Compare a com b^k em inteiros: nada de double nem de log, que erram por
//    arredondamento.
// 2. A função recursiva custo(a, b, k, n) devolve n^k + a · custo(a, b, k,
//    n/b), com custo(1) = 1. É a própria recorrência.
// 3. A última linha da tabela (tamanho 1) tem a^(log_b n) = n^(log_b a)
//    folhas: é o termo que o caso 1 compara com f(n).
// 4. Resposta esperada: 8T(n/2)+n² tem folhas 262144 de 520192 (caso 1);
//    4T(n/2)+n² tem 7 níveis de 4096 (caso 2); 2T(n/2)+n² tem raiz 4096 de
//    8128 (caso 3); 9T(n/3)+n é caso 1.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

void arvore(int a, int b, int k, long n) {
    printf("T(n) = %d T(n/%d) + n^%d, n = %ld\n", a, b, k, n);
}

int main(void) {
    arvore(8, 2, 2, 64);
    arvore(4, 2, 2, 64);
    arvore(2, 2, 2, 64);
    arvore(9, 3, 1, 81);
    return 0;
}
