// 0095 · Busca binária
// Exercício E565 · ★☆☆
//
// Os armários livres do vestiário do clube estão numa lista ordenada, e o
// programa abaixo procura dois números nela. SEM RODAR, escreva a saída exata
// deste programa. Faça o teste de mesa com
// ini, fim e meio em cada volta. Só depois rode para conferir.
//
// Dicas:
// 1. n = 9, então a primeira volta tem ini = 0, fim = 8 e meio = 4.
// 2. Para o 5: depois de cada volta, anote o novo intervalo [ini, fim].
// 3. O laço para quando ini fica maior que fim.
// 4. Resposta esperada: para 47 aparecem meio=4 (30), meio=6 (47) e "achou na
//    posição 6"; para 5 aparecem meio=4 (30), meio=1 (9), meio=0 (4) e "não
//    achou".
//
// Escreva sua resposta abaixo (como comentário):

#include <stdio.h>

void procura(const int v[], int n, int x) {
    int ini = 0, fim = n - 1;
    printf("Procurando %d\n", x);
    while (ini <= fim) {
        int meio = ini + (fim - ini) / 2;
        printf("meio=%d (%d)\n", meio, v[meio]);
        if (v[meio] == x) {
            printf("achou na posição %d\n", meio);
            return;
        }
        if (v[meio] < x) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    printf("não achou\n");
}

int main(void) {
    int armarios[] = {4, 9, 13, 21, 30, 38, 47, 55, 62};
    procura(armarios, 9, 47);
    procura(armarios, 9, 5);
    return 0;
}
