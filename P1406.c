// Lista · Módulo 14 · Árvores
// Exercício P1406 · ★☆☆ · Chamando os pacientes mais urgentes
//
// No pronto-socorro, as urgências dos pacientes já estão num heap de máximo:
// 95, 80, 70, 40, 75, 30, 65, 10. A função desce está pronta. Escreva
// int extrai_max(int heap[], int *n): guarda a raiz, leva o último elemento
// para a raiz, diminui n e faz a raiz descer. Chame três pacientes,
// mostrando o heap que sobra a cada chamada.
//
//   Saída esperada:
//   chamou 95, sobrou: 80 75 70 40 10 30 65
//   chamou 80, sobrou: 75 65 70 40 10 30
//   chamou 75, sobrou: 70 65 30 40 10
//
// Dicas:
// 1. heap[0] = heap[--(*n)]; e depois desce(heap, *n, 0).
// 2. Na primeira extração o 10 vai para a raiz e desce trocando com o maior
//    filho: primeiro o 80, depois o 75.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void desce(int heap[], int n, int i) {
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && heap[f + 1] > heap[f]) {
            f++;
        }
        if (heap[i] >= heap[f]) {
            break;
        }
        troca(&heap[i], &heap[f]);
        i = f;
    }
}

int main(void) {
    int urgencia[] = {95, 80, 70, 40, 75, 30, 65, 10};
    int n = 8;
    (void)urgencia;
    (void)n;

    return 0;
}
