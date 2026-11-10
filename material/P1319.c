// Lista · Módulo 13 · Busca e ordenação
// Exercício P1319 · ★★☆ · Busca binária no ranking decrescente
//
// O ranking do torneio de xadrez da escola está em ordem DECRESCENTE de
// pontos: 980, 875, 870, 720, 650, 610, 455, 300. A busca abaixo foi copiada
// de um vetor crescente e, aqui, erra quase tudo. Adapte a busca para vetor
// decrescente e mostre a colocação (posição + 1) de quem fez 650, 980, 300 e
// 500 pontos.
//
//   Saída esperada:
//   650 pontos: 5º lugar
//   980 pontos: 1º lugar
//   300 pontos: 8º lugar
//   500 pontos: ninguém
//
// Dicas:
// 1. Rode antes: nenhuma das quatro é achada, porque a busca vai sempre
//    para o lado errado.
// 2. No vetor decrescente, se v[meio] > x, o x está à DIREITA do meio.
// 3. Só uma comparação muda de sentido; o resto da busca fica igual.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (adapte o código):

#include <stdio.h>

int busca(const int v[], int n, int x) {
    int ini = 0, fim = n - 1;
    while (ini <= fim) {
        int meio = ini + (fim - ini) / 2;
        if (v[meio] == x) {
            return meio;
        }
        if (v[meio] < x) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main(void) {
    int pontos[] = {980, 875, 870, 720, 650, 610, 455, 300};
    int n = 8;
    int consultas[] = {650, 980, 300, 500};

    for (int k = 0; k < 4; k++) {
        int pos = busca(pontos, n, consultas[k]);
        if (pos >= 0) {
            printf("%d pontos: %dº lugar\n", consultas[k], pos + 1);
        } else {
            printf("%d pontos: ninguém\n", consultas[k]);
        }
    }
    return 0;
}
