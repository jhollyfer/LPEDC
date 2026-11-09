// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2625 · ★★★ · Total alocado contra pico de memória
//
// Este merge sort pede um vetor auxiliar novo a CADA intercalação, do
// tamanho do pedaço, e libera logo depois. Instrumente o programa com três
// medidas: o total de bytes pedidos ao malloc somando todas as chamadas,
// os bytes vivos agora e o pico de bytes vivos ao mesmo tempo. Mostre as
// três para n = 1024 e 4096 (o "vivos agora" no fim tem que ser 0):
//
//   Saída esperada:
//   n = 1024: total  40960 bytes, pico  4096 bytes, vivos no fim 0
//   n = 4096: total 196608 bytes, pico 16384 bytes, vivos no fim 0
//
// Dicas:
// 1. Some os bytes no malloc (total e vivos, atualizando o pico) e subtraia
//    no free.
// 2. O total é 4 n log2 n: cada nível da recursão aloca n inteiros. Mas só um
//    auxiliar vive por vez: o pico é 4n, o da última intercalação.
// 3. Espaço é o pico, não o total: Θ(n). O total pesa no tempo (o malloc
//    custa), não na memória.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (mude o programa):

#include <stdio.h>
#include <stdlib.h>

void intercala(int v[], int ini, int meio, int fim) {
    int n = fim - ini;
    int *aux = malloc(n * sizeof(int));
    if (aux == NULL) {
        return;
    }
    int i = ini, j = meio, k = 0;
    while (i < meio || j < fim) {
        if (j >= fim || (i < meio && v[i] <= v[j])) {
            aux[k++] = v[i++];
        } else {
            aux[k++] = v[j++];
        }
    }
    for (k = 0; k < n; k++) {
        v[ini + k] = aux[k];
    }
    free(aux);
}

void ordena(int v[], int ini, int fim) {
    if (fim - ini > 1) {
        int meio = ini + (fim - ini) / 2;
        ordena(v, ini, meio);
        ordena(v, meio, fim);
        intercala(v, ini, meio, fim);
    }
}

int main(void) {
    static int v[4096];
    for (int i = 0; i < 4096; i++) {
        v[i] = 4096 - i;
    }
    ordena(v, 0, 4096);
    printf("%d %d\n", v[0], v[4095]);
    return 0;
}
