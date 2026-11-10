// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1705 · ★☆☆ · A árvore de recursão do merge sort, nível por nível
//
// O merge sort do esqueleto ordena os preços de 16 produtos. A recorrência
// é T(n) = 2 T(n/2) + n: cada chamada com um pedaço de tamanho m custa m (o
// trabalho de intercalar).
//
// Instrumente o merge sort com um parâmetro nivel (a raiz é o nível 0) e,
// em vetores globais, acumule por nível o número de chamadas e o custo (a
// soma dos tamanhos dos pedaços). Mostre a tabela da árvore de recursão para
// n = 16 e para n = 10 e o custo total. Para n potência de 2, o total é
// n lg n + n: lg n + 1 níveis com custo n cada.
//
//   Saída esperada:
//   n = 16: 2 3 5 7 8 9 11 12 15 18 19 22 25 30 33 40
//   nível  chamadas  custo
//       0         1     16
//       1         2     16
//       2         4     16
//       3         8     16
//       4        16     16
//   Total: 80
//   n = 10: 3 5 8 9 12 15 18 22 30 40
//   nível  chamadas  custo
//       0         1     10
//       1         2     10
//       2         4     10
//       3         8     10
//       4         4      4
//   Total: 44
//
// Dicas:
// 1. Acrescente int nivel aos parâmetros: a chamada recursiva passa
//    nivel + 1. Logo no começo, faça nos[nivel]++ e custo[nivel] += m.
// 2. Conte também as folhas (pedaços de tamanho 1): elas formam o último
//    nível, com custo 1 cada.
// 3. Com n = 10 os pedaços não têm o mesmo tamanho, e o último nível fica
//    incompleto. Mesmo assim cada nível cheio custa n.
// 4. Resposta esperada: n = 16 dá 5 níveis de custo 16 (total 80 = 16 · 4 +
//    16); n = 10 dá 5 níveis, o último com 4 chamadas e custo 4 (total 44).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int aux[16];

void intercala(int v[], int ini, int meio, int fim) {
    int i = ini, j = meio + 1, k = 0;
    while (i <= meio && j <= fim) aux[k++] = v[i] <= v[j] ? v[i++] : v[j++];
    while (i <= meio) aux[k++] = v[i++];
    while (j <= fim) aux[k++] = v[j++];
    memcpy(v + ini, aux, k * sizeof(int));
}

void merge_sort(int v[], int ini, int fim) {
    if (ini >= fim) return;
    int meio = (ini + fim) / 2;
    merge_sort(v, ini, meio);
    merge_sort(v, meio + 1, fim);
    intercala(v, ini, meio, fim);
}

int main(void) {
    int precos[16] = {12, 5, 30, 8, 22, 9, 15, 3, 40, 18, 7, 25, 11, 2, 33, 19};
    merge_sort(precos, 0, 15);
    for (int i = 0; i < 16; i++) printf("%d ", precos[i]);
    printf("\n");
    return 0;
}
