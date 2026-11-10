// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2208 · ★☆☆ · A torre que o posto não deixa crescer
//
// O union-find abaixo é o ingênuo: une(a, b) pendura a raiz de a embaixo da
// raiz de b, sempre, e acha não comprime o caminho. Com as uniões une(0,
// 1), une(1, 2), ..., une(14, 15), a árvore vira uma fila de 16 andares.
// Estenda o programa: escreva une_posto(a, b), com união por POSTO (rank)
// e o mesmo acha sem compressão, rode as mesmas 15 uniões num segundo
// vetor de pais e mostre a profundidade máxima (em arestas) nas duas
// versões.
//
//   Saída esperada:
//   Sem posto: profundidade máxima 15
//   Com posto: profundidade máxima 1
//
// Dicas:
// 1. profundidade(pai, x) conta quantos passos x dá até a raiz. A máxima
//    é o maior valor entre os 16 elementos.
// 2. Com posto, a raiz mais "alta" fica por cima. Aqui a árvore do 0 já tem
//    posto 1 depois da primeira união, e cada elemento novo (posto 0) entra
//    pendurado direto nela.
// 3. Resposta esperada: 15 sem posto e 1 com posto. Com posto, a altura
//    nunca passa de lg n, mesmo sem compressão.
//
// Escreva sua resposta abaixo (estenda o código):

#include <stdio.h>

#define N 16

int acha(const int pai[], int x) {
    while (pai[x] != x) {
        x = pai[x];
    }
    return x;
}

void une_ingenuo(int pai[], int a, int b) {
    int ra = acha(pai, a), rb = acha(pai, b);
    if (ra != rb) {
        pai[ra] = rb;
    }
}

int profundidade(const int pai[], int x) {
    int d = 0;
    while (pai[x] != x) {
        x = pai[x];
        d++;
    }
    return d;
}

int maxima(const int pai[]) {
    int m = 0;
    for (int i = 0; i < N; i++) {
        int d = profundidade(pai, i);
        if (d > m) {
            m = d;
        }
    }
    return m;
}

int main(void) {
    int pai[N];
    for (int i = 0; i < N; i++) {
        pai[i] = i;
    }
    for (int i = 0; i + 1 < N; i++) {
        une_ingenuo(pai, i, i + 1);
    }
    printf("Sem posto: profundidade máxima %d\n", maxima(pai));
    return 0;
}
