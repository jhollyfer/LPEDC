// Lista · Módulo 13 · Busca e ordenação
// Exercício P1314 · ★★☆ · Quick sort com a partição de Hoare
//
// Ordene as notas 7, 2, 9, 4, 7, 1, 8, 3 com quick sort usando a partição de
// HOARE do Cormen (problema 7-1): o pivô é x = v[p]; i começa em p - 1 e j em
// r + 1; repita: "j-- até v[j] <= x", "i++ até v[i] >= x"; se i < j, troca
// v[i] com v[j]; senão, devolve j. Depois, a recursão é quick(p, j) e
// quick(j + 1, r): o pivô NÃO fica necessariamente na posição j.
//
// O vetor e n são globais (já estão no esqueleto). A cada partição, mostre
// o intervalo, o pivô, o j devolvido e o vetor inteiro; no fim, o vetor
// ordenado.
//
//   Saída esperada:
//   [0..7] pivô 7, j = 4: 3 2 1 4 7 9 8 7
//   [0..4] pivô 3, j = 1: 1 2 3 4 7 9 8 7
//   [0..1] pivô 1, j = 0: 1 2 3 4 7 9 8 7
//   [2..4] pivô 3, j = 2: 1 2 3 4 7 9 8 7
//   [3..4] pivô 4, j = 3: 1 2 3 4 7 9 8 7
//   [5..7] pivô 9, j = 6: 1 2 3 4 7 7 8 9
//   [5..6] pivô 7, j = 5: 1 2 3 4 7 7 8 9
//   final: 1 2 3 4 7 7 8 9
//
// Dicas:
// 1. Use do { j--; } while (v[j] > x); e do { i++; } while (v[i] < x);
// 2. Guarde o pivô (v[p]) antes de chamar a partição, para poder mostrá-lo.
// 3. Na primeira partição, os 7 iguais ao pivô vão um para cada lado: Hoare
//    para nos iguais, e é isso que deixa as metades equilibradas.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int v[] = {7, 2, 9, 4, 7, 1, 8, 3};
int n = 8;

void mostra(void) {
    for (int k = 0; k < n; k++) {
        printf(" %d", v[k]);
    }
    printf("\n");
}

int main(void) {

    return 0;
}
