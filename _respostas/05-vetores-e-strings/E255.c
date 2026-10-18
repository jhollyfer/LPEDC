// 0043 · Juntando tudo
// Exercício E255 · ★★☆

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 20

bool completa(const bool revelada[], int n) {
    for (int i = 0; i < n; i++) {
        if (!revelada[i]) {
            return false;
        }
    }
    return true;
}

void mostrar(const char secreta[], const bool revelada[], int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            putchar(' ');
        }
        putchar(revelada[i] ? secreta[i] : '_');
    }
}

int main(void) {
    char secreta[] = "BANANA";
    char chutes[] = {'A', 'E', 'N', 'B', 'O'};
    int n = (int) strlen(secreta);
    int total_chutes = sizeof(chutes);
    bool revelada[MAX] = {false};
    int erros = 0;

    for (int k = 0; k < total_chutes && !completa(revelada, n); k++) {
        bool acertou = false;
        for (int i = 0; i < n; i++) {
            if (secreta[i] == chutes[k]) {
                revelada[i] = true;
                acertou = true;
            }
        }
        printf("Chute %c: ", chutes[k]);
        mostrar(secreta, revelada, n);
        if (!acertou) {
            erros++;
            printf(" (erro %d)", erros);
        }
        printf("\n");
    }

    if (completa(revelada, n)) {
        printf("Venceu com %d erro(s)!\n", erros);
    } else {
        printf("Os chutes acabaram.\n");
    }
    return 0;
}
