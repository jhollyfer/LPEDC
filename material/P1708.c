// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1708 · ★☆☆ · Quão funda fica a pilha de chamadas
//
// A recorrência mede o TEMPO; a altura da árvore de recursão mede a PILHA.
// O esqueleto tem duas somas recursivas das contas de luz de um condomínio,
// as duas com Θ(n) chamadas:
//
// - soma_fila(v, n) = v[n - 1] + soma_fila(v, n - 1): T(n) = T(n - 1) + 1;
// - soma_meio(v, ini, fim) divide ao meio: T(n) = 2 T(n/2) + 1.
//
// Instrumente as duas com um parâmetro de profundidade e guarde a maior
// profundidade alcançada (a raiz tem profundidade 1). Mostre, para n = 10,
// 100 e 1000, as chamadas e a profundidade máxima de cada uma.
//
//   Saída esperada:
//   n =   10  fila: soma   1385,   11 chamadas, profundidade   11
//             meio: soma   1385,   19 chamadas, profundidade    5
//   n =  100  fila: soma  15350,  101 chamadas, profundidade  101
//             meio: soma  15350,  199 chamadas, profundidade    8
//   n = 1000  fila: soma 154400, 1001 chamadas, profundidade 1001
//             meio: soma 154400, 1999 chamadas, profundidade   11
//
// Dicas:
// 1. Passe prof + 1 nas chamadas recursivas e atualize uma variável global
//    max_prof logo no começo da função.
// 2. soma_fila desce até n == 0: a pilha chega a n + 1 chamadas abertas ao
//    mesmo tempo.
// 3. soma_meio para em pedaços de 1 elemento. A altura é ⌈lg n⌉ + 1: com
//    n = 1000, só 11 chamadas abertas, contra 1001.
// 4. Resposta esperada: as duas somas dão o mesmo valor; chamadas n + 1 e
//    2n - 1; profundidades 1001 e 11 para n = 1000.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define MAX 1000

int conta[MAX];

long soma_fila(const int v[], int n) {
    if (n == 0) return 0;
    return v[n - 1] + soma_fila(v, n - 1);
}

long soma_meio(const int v[], int ini, int fim) {
    if (ini == fim) return v[ini];
    int meio = (ini + fim) / 2;
    return soma_meio(v, ini, meio) + soma_meio(v, meio + 1, fim);
}

int main(void) {
    for (int i = 0; i < MAX; i++) conta[i] = 80 + (i * 13) % 150; // R$ por apartamento

    printf("%ld %ld\n", soma_fila(conta, MAX), soma_meio(conta, 0, MAX - 1));
    return 0;
}
