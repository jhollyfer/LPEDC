// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1717 · ★★☆ · Conserte o vetor que cresce de 10 em 10
//
// Conserte o programa. O app de delivery guarda os pedidos do dia num vetor
// dinâmico, e o colega fez o vetor crescer de 10 em 10 posições "para não
// desperdiçar memória". O erro de propósito não é de memória (o
// AddressSanitizer não reclama): é de ANÁLISE. Com crescimento aditivo, n
// inserções copiam 10 + 20 + 30 + ... ≈ n²/20 itens: Θ(n²) no total, Θ(n)
// por inserção. Veja a saída com 10 mil pedidos:
//
//   Saída que aparece:
//   Pedidos: 10000 | capacidade: 10000
//   Realocações: 999 | cópias: 4995000 (499.50 por pedido)
//
// Troque a regra de crescimento para DOBRAR a capacidade (começando em 10) e
// confira que as cópias caem para menos de 2n, ou seja, O(1) amortizado:
//
//   Saída esperada:
//   Pedidos: 10000 | capacidade: 10240
//   Realocações: 10 | cópias: 10230 (1.02 por pedido)
//
// Dicas:
// 1. A única linha que muda é a da nova capacidade.
// 2. Dobrando a partir de 10, as cópias são 10 + 20 + 40 + ... + 5120: uma
//    progressão geométrica que soma menos que o dobro do último termo.
// 3. Se quiser ver a diferença no relógio, aumente para 1 milhão de pedidos:
//    a versão aditiva copia uns 50 bilhões de itens.
// 4. Resposta esperada: 10 realocações e 10230 cópias, contra 999 e 4995000.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *item;
    int num, cap;
    long copias;
    int realocacoes;
} Vetor;

void insere(Vetor *v, int x) {
    if (v->num == v->cap) {
        int nova = v->cap + 10;
        int *novo = malloc(nova * sizeof *novo);
        if (novo == NULL) exit(1);
        for (int i = 0; i < v->num; i++) novo[i] = v->item[i];
        v->copias += v->num;
        v->realocacoes++;
        free(v->item);
        v->item = novo;
        v->cap = nova;
    }
    v->item[v->num++] = x;
}

int main(void) {
    Vetor v = {malloc(10 * sizeof(int)), 0, 10, 0, 0};
    if (v.item == NULL) return 1;
    for (int i = 0; i < 10000; i++) insere(&v, 5000 + i);
    printf("Pedidos: %d | capacidade: %d\n", v.num, v.cap);
    printf("Realocações: %d | cópias: %ld (%.2f por pedido)\n", v.realocacoes, v.copias,
           (double)v.copias / v.num);
    free(v.item);
    return 0;
}
