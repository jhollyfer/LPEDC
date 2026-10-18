// 0094 · Busca sequencial
// Exercício E564 · ★★★

#include <stdio.h>
#include <string.h>

#define N 5

// busca e, se achar, move o contato para a frente (posição 0)
int busca_move(const char *agenda[], int n, const char *nome, int *comparacoes) {
    for (int i = 0; i < n; i++) {
        (*comparacoes)++;
        if (strcmp(agenda[i], nome) == 0) {
            const char *achado = agenda[i];
            for (int k = i; k > 0; k--) { // empurra os anteriores uma casa
                agenda[k] = agenda[k - 1];
            }
            agenda[0] = achado;
            return 0;
        }
    }
    return -1;
}

// busca comum, sem mexer na agenda
int busca(const char *agenda[], int n, const char *nome, int *comparacoes) {
    for (int i = 0; i < n; i++) {
        (*comparacoes)++;
        if (strcmp(agenda[i], nome) == 0) {
            return i;
        }
    }
    return -1;
}

void mostra(const char *agenda[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s%s", agenda[i], i < n - 1 ? " " : "\n");
    }
}

int main(void) {
    const char *fixa[N] = {"Chefe", "Banco", "Pizzaria", "Ana", "Mãe"};
    const char *agenda[N] = {"Chefe", "Banco", "Pizzaria", "Ana", "Mãe"};
    const char *acessos[] = {"Mãe", "Ana", "Mãe", "Mãe", "Pizzaria", "Mãe"};
    int sem = 0, com = 0;

    for (int k = 0; k < 6; k++) {
        busca(fixa, N, acessos[k], &sem);
        busca_move(agenda, N, acessos[k], &com);
        printf("%s -> ", acessos[k]);
        mostra(agenda, N);
    }
    printf("Sem mover: %d comparações\n", sem);
    printf("Movendo para a frente: %d comparações\n", com);
    return 0;
}
