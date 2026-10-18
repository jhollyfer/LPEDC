// 0100 · Quick sort
// Exercício E595 · ★☆☆
//
// As senhas de uma fila de exames são 9, 2, 6, 4, 8, 5. O programa abaixo faz
// UMA separação (só o separa, sem recursão), com o pivô no fim. SEM RODAR,
// escreva a saída exata: cada troca feita, o vetor final e a posição do pivô.
// Depois rode e confira.
//
// Dicas:
// 1. O pivô é 5. Só 2 e 4 são <= 5.
// 2. k anda sempre; j só anda depois de uma troca.
// 3. No fim, o pivô troca de lugar com quem está em v[j].
// 4. Resposta esperada: troca v[0] e v[1]; troca v[1] e v[3]; troca v[2] e
//    v[5]; vetor: 2 4 5 9 8 6; pivô na posição 2.
//
// Escreva sua resposta abaixo (como comentário):

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
