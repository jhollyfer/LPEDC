// 0095 · Quick sort
// Exercício E565 · ★☆☆
//
// As senhas de uma fila de exames são 9, 2, 6, 4, 8, 5. O programa abaixo faz
// UMA separação (só o separa, sem recursão), com o pivô no fim, e mostra cada
// troca. Dê o próximo passo do quick sort à mão, no código:
//
// a) conte as comparações (v[k] <= pivo) numa variável static;
// b) depois da primeira separação, chame separa de novo só no lado DIREITO
//    do pivô e mostre outra vez o vetor e a nova posição do pivô;
// c) no fim, mostre o total de comparações das duas separações.
//
//   Saída esperada:
//   troca v[0] e v[1]
//   troca v[1] e v[3]
//   troca v[2] e v[5]
//   vetor: 2 4 5 9 8 6
//   pivô na posição 2
//   troca v[3] e v[5]
//   vetor: 2 4 5 6 8 9
//   pivô na posição 3
//   comparações: 7
//
// Escreva sua resposta abaixo (modifique o código):

#include <stdio.h>

void troca(int v[], int a, int b) {
    printf("troca v[%d] e v[%d]\n", a, b);
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

int separa(int v[], int p, int r) {
    int pivo = v[r], j = p;
    for (int k = p; k < r; k++) {
        if (v[k] <= pivo) {
            troca(v, j, k);
            j++;
        }
    }
    troca(v, j, r);
    return j;
}

int main(void) {
    int senhas[] = {9, 2, 6, 4, 8, 5};
    int j = separa(senhas, 0, 5);

    printf("vetor:");
    for (int i = 0; i < 6; i++) {
        printf(" %d", senhas[i]);
    }
    printf("\npivô na posição %d\n", j);
    return 0;
}
