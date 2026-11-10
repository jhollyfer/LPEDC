// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2616 · ★★☆ · A pilha do quick sort azarado
//
// O quick sort abaixo usa o último elemento como pivô. Meça a profundidade
// máxima da recursão (prof e prof_max globais) ao ordenar 1000 senhas de
// atendimento em três situações: já em ordem crescente, em ordem
// decrescente e embaralhadas (com o gerador do programa):
//
//   Saída esperada:
//   crescente  : profundidade 1000
//   decrescente: profundidade 1000
//   embaralhado: profundidade 22
//
// Dicas:
// 1. Conte o frame na entrada do quick e descarte na saída, antes do return.
// 2. Com a entrada em ordem, cada partição tira só o pivô: 1000 níveis, Θ(n)
//    de pilha.
// 3. Embaralhado, a profundidade fica perto de alguns log2 n: Θ(log n) em
//    média.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (mude o programa):

#include <stdio.h>

unsigned semente = 42;

int sorteia(int limite) {
    semente = semente * 1103515245u + 12345u;
    return (int)((semente / 65536u) % (unsigned)limite);
}

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// ordena v[ini..fim] com pivô no último
void quick(int v[], int ini, int fim) {
    if (ini >= fim) {
        return;
    }
    int pivo = v[fim], i = ini;
    for (int j = ini; j < fim; j++) {
        if (v[j] < pivo) {
            troca(&v[i], &v[j]);
            i++;
        }
    }
    troca(&v[i], &v[fim]);
    quick(v, ini, i - 1);
    quick(v, i + 1, fim);
}

int main(void) {
    int v[1000];
    for (int i = 0; i < 1000; i++) {
        v[i] = sorteia(100000);
    }
    quick(v, 0, 999);
    printf("ordenado: %d ... %d\n", v[0], v[999]);
    return 0;
}
