// 0136 · Código de Huffman
// Exercício E814 · ★★☆
//
// Ache o bug. Cinco arquivos de log, de 8, 3, 15, 6 e 10 MB, precisam ser
// juntados (intercalados) dois a dois, e juntar dois custa a soma dos
// tamanhos. O programa deveria usar o guloso do Huffman (sempre as duas
// MENORES, com um heap de mínimo), mas o custo sai alto:
//
//   Saída que aparece:
//   junta 15 + 10
//   junta 25 + 8
//   junta 33 + 6
//   junta 39 + 3
//   Custo: 139 MB lidos
//
//   Saída esperada:
//   junta 3 + 6
//   junta 8 + 9
//   junta 10 + 15
//   junta 17 + 25
//   Custo: 93 MB lidos
//
// O heap está com o sentido trocado. Conserte poe e tira para virar um
// heap de mínimo. Para conferir, mostre o vetor v depois de cada poe.
//
// Dicas:
// 1. São três comparações para inverter: a da subida, a da escolha do
//    filho e a da parada da descida.
// 2. Heap de mínimo: sobe enquanto for MENOR que o pai; desce trocando com o
//    MENOR filho; para quando for menor ou igual ao menor filho.
// 3. Resposta esperada: v[i] < v[(i - 1) / 2] na subida; v[f + 1] < v[f] na
//    escolha; v[i] <= v[f] na parada. Consertado, mostra a saída acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define CAP 16

int v[CAP];
int n = 0;

void troca(int a, int b) {
    int t = v[a];
    v[a] = v[b];
    v[b] = t;
}

void poe(int x) {
    int i = n++;
    v[i] = x;
    while (i > 0 && v[i] > v[(i - 1) / 2]) {
        troca(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

int tira(void) {
    int topo = v[0];
    v[0] = v[--n];
    int i = 0;
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && v[f + 1] > v[f]) {
            f++;
        }
        if (v[i] >= v[f]) {
            break;
        }
        troca(i, f);
        i = f;
    }
    return topo;
}

int main(void) {
    int mb[] = {8, 3, 15, 6, 10}; // tamanho de cada arquivo de log, em MB
    for (int i = 0; i < 5; i++) {
        poe(mb[i]);
    }
    int custo = 0;
    while (n > 1) {
        int a = tira();
        int b = tira();
        printf("junta %d + %d\n", a, b);
        custo += a + b;
        poe(a + b);
    }
    printf("Custo: %d MB lidos\n", custo);
    return 0;
}
