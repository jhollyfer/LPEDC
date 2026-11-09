// Lista · Módulo 13 · Busca e ordenação
// Exercício P1318 · ★★☆ · O pior caso do quick sort, medido
//
// O quick sort abaixo usa a partição de Lomuto (pivô no fim). Instrumente:
//
// a) conte numa variável global comparacoes cada v[j] <= pivo;
// b) acrescente um parâmetro prof em quick (a raiz chama com 0 e cada
//    chamada recursiva passa prof + 1) e guarde em profundidade_max a maior
//    profundidade alcançada, contando também as chamadas com p >= r;
// c) escreva testa(nome, v, n), que zera os contadores, ordena e mostra.
//
// Rode no vetor crescente 1..10 e no misturado 6 3 9 1 8 2 10 5 7 4, e
// mostre n(n-1)/2 para comparar.
//
//   Saída esperada:
//   crescente  comparações 45, profundidade 9
//   misturado  comparações 20, profundidade 4
//   n(n-1)/2 = 45
//
// Dicas:
// 1. Atualize profundidade_max logo no começo de quick, antes do if.
// 2. No crescente, o pivô é sempre o maior: cada partição deixa o lado
//    direito vazio e o esquerdo com um a menos. 9 + 8 + ... + 1 = 45.
// 3. A profundidade 9 é a pilha de chamadas crescendo em O(n): com um vetor
//    de um milhão já ordenado, o programa estouraria a pilha.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (modifique o código):

#include <stdio.h>

int comparacoes, profundidade_max;

int particiona(int v[], int p, int r) {
    int pivo = v[r], i = p - 1;
    for (int j = p; j < r; j++) {
        if (v[j] <= pivo) {
            i++;
            int t = v[i];
            v[i] = v[j];
            v[j] = t;
        }
    }
    int t = v[i + 1];
    v[i + 1] = v[r];
    v[r] = t;
    return i + 1;
}

void quick(int v[], int p, int r) {
    if (p < r) {
        int q = particiona(v, p, r);
        quick(v, p, q - 1);
        quick(v, q + 1, r);
    }
}

int main(void) {
    int crescente[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int misturado[] = {6, 3, 9, 1, 8, 2, 10, 5, 7, 4};

    quick(crescente, 0, 9);
    quick(misturado, 0, 9);
    return 0;
}
