// A111 · Trocar linhas sem copiar

#include <stdio.h>
#include <stdlib.h>

int total_da_linha(const int *linha, int colunas) {
    int total = 0;
    for (int j = 0; j < colunas; j++) {
        total += linha[j];
    }
    return total;
}

int main(void) {
    int times = 4;
    int rodadas = 5;
    int pontos[4][5] = {{1, 0, 3, 1, 0},  // Time A
                        {3, 3, 1, 0, 3},  // Time B
                        {0, 1, 1, 1, 1},  // Time C
                        {3, 0, 3, 3, 1}}; // Time D

    int **tabela = malloc(times * sizeof *tabela);
    if (tabela == NULL) {
        return 1;
    }
    for (int i = 0; i < times; i++) {
        tabela[i] = malloc(rodadas * sizeof *tabela[i]);
        if (tabela[i] == NULL) {
            for (int k = 0; k < i; k++) {
                free(tabela[k]);
            }
            free(tabela);
            return 1;
        }
        for (int j = 0; j < rodadas; j++) {
            tabela[i][j] = pontos[i][j];
        }
    }
    char nome[4] = {'A', 'B', 'C', 'D'};

    // Ordena do mais pontuado ao menos (seleção). Trocar duas linhas é
    // trocar dois PONTEIROS: 8 bytes cada, não importa quantas rodadas.
    for (int i = 0; i < times - 1; i++) {
        int melhor = i;
        for (int k = i + 1; k < times; k++) {
            if (total_da_linha(tabela[k], rodadas) > total_da_linha(tabela[melhor], rodadas)) {
                melhor = k;
            }
        }
        int *linha = tabela[i]; // só o endereço da linha muda de gaveta
        tabela[i] = tabela[melhor];
        tabela[melhor] = linha;
        char letra = nome[i];
        nome[i] = nome[melhor];
        nome[melhor] = letra;
    }

    for (int i = 0; i < times; i++) {
        printf("%dº Time %c: %2d pts |", i + 1, nome[i], total_da_linha(tabela[i], rodadas));
        for (int j = 0; j < rodadas; j++) {
            printf(" %d", tabela[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < times; i++) {
        free(tabela[i]); // a ordem das linhas mudou, mas cada bloco é o mesmo
    }
    free(tabela);
    return 0;
}
// Saída:
// 1º Time B: 10 pts | 3 3 1 0 3
// 2º Time D: 10 pts | 3 0 3 3 1
// 3º Time A:  5 pts | 1 0 3 1 0
// 4º Time C:  4 pts | 0 1 1 1 1
//
// Numa matriz fixa int [4][5], trocar duas linhas exigiria copiar os 5
// números de cada uma. Com int **, as linhas nem saem do lugar no heap.
