// 0094 · Busca sequencial
// Exercício E560 · ★☆☆

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *convidados[] = {"Ana", "Bruno", "Carla", "Diego", "Elisa"};
    int n = 5;
    const char *procurados[] = {"Carla", "Fábio"};

    printf("Lista:");
    for (int i = 0; i < n; i++) {
        printf(" %s", convidados[i]);
    }
    printf("\n");

    for (int k = 0; k < 2; k++) {
        const char *nome = procurados[k];
        int pos = -1;
        for (int i = 0; i < n; i++) {
            if (strcmp(convidados[i], nome) == 0) {
                pos = i;
                break;
            }
        }
        if (pos >= 0) {
            printf("%s: pode entrar (posição %d)\n", nome, pos);
        } else {
            printf("%s: não está na lista\n", nome);
        }
    }
    return 0;
}
