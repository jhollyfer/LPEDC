// A295 · Sem os dois truques, a árvore vira lista

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10000

int pai[N], tam[N];
long passos; // quantas vezes alguém subiu de um nó para o pai

void inicia(void) {
    for (int i = 0; i < N; i++) {
        pai[i] = i;
        tam[i] = 1;
    }
    passos = 0;
}

int acha(int x, bool comprime) {
    int raiz = x;
    while (pai[raiz] != raiz) {
        raiz = pai[raiz];
        passos++;
    }
    while (comprime && pai[x] != raiz) {
        int prox = pai[x];
        pai[x] = raiz;
        x = prox;
    }
    return raiz;
}

void une(int a, int b, bool por_tamanho, bool comprime) {
    int ra = acha(a, comprime), rb = acha(b, comprime);
    if (ra == rb) {
        return;
    }
    if (por_tamanho && tam[ra] < tam[rb]) {
        int t = ra;
        ra = rb;
        rb = t;
    }
    if (por_tamanho) {
        pai[rb] = ra; // o menor vai para baixo do maior
        tam[ra] += tam[rb];
    } else {
        pai[ra] = rb; // ingênuo: o grupo de a vai sempre para baixo do de b
    }
}

int profundidade_maxima(void) {
    int maior = 0;
    for (int i = 0; i < N; i++) {
        int d = 0;
        for (int x = i; pai[x] != x; x = pai[x]) {
            d++;
        }
        if (d > maior) {
            maior = d;
        }
    }
    return maior;
}

void testa(const char *nome, bool por_tamanho, bool comprime) {
    inicia();
    for (int i = 1; i < N; i++) {
        une(0, i, por_tamanho, comprime); // o 0 chama todo mundo para o grupo dele
    }
    long nas_unioes = passos;
    int prof = profundidade_maxima();
    passos = 0;
    for (int i = 0; i < N; i++) {
        acha(i, comprime); // depois, cada um pergunta quem é o representante
    }
    printf("%s passos nas uniões: %9ld | profundidade: %4d | passos nas buscas: %8ld\n",
           nome, nas_unioes, prof, passos);
}

int main(void) {
    testa("ingênuo:             ", false, false);
    testa("só por tamanho:      ", true, false);
    testa("ingênuo + compressão:", false, true);
    return 0;
}
// Saída:
// ingênuo:              passos nas uniões:  49985001 | profundidade: 9999 | passos nas buscas: 49995000
// só por tamanho:       passos nas uniões:         0 | profundidade:    1 | passos nas buscas:     9999
// ingênuo + compressão: passos nas uniões:     19995 | profundidade: 9998 | passos nas buscas:    19997
