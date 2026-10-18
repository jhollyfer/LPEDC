// 0063 · Juntando tudo
// Exercício E378 · ★★★

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void liberar_pedacos(char **v, int n) {
    if (v == NULL) {
        return;
    }
    for (int i = 0; i < n; i++) {
        free(v[i]);
    }
    free(v);
}

char **dividir(const char *texto, char separador, int *qtd) {
    int n = 1;
    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == separador) {
            n++;
        }
    }
    *qtd = 0;
    char **v = malloc(n * sizeof *v);
    if (v == NULL) {
        return NULL;
    }
    int inicio = 0;
    for (int k = 0; k < n; k++) {
        int fim = inicio;
        while (texto[fim] != '\0' && texto[fim] != separador) {
            fim++;
        }
        int tamanho = fim - inicio;
        v[k] = malloc(tamanho + 1);
        if (v[k] == NULL) {
            liberar_pedacos(v, k);
            return NULL;
        }
        for (int j = 0; j < tamanho; j++) {
            v[k][j] = texto[inicio + j];
        }
        v[k][tamanho] = '\0';
        inicio = fim + 1; // pula o separador
    }
    *qtd = n;
    return v;
}

void mostrar(const char *texto) {
    int n;
    char **pedacos = dividir(texto, ';', &n);
    if (pedacos == NULL) {
        printf("Sem memória\n");
        return;
    }
    printf("%d itens:", n);
    for (int i = 0; i < n; i++) {
        printf(" [%s]", pedacos[i]);
    }
    printf("\n");
    liberar_pedacos(pedacos, n);
}

int main(void) {
    mostrar("arroz;feijao;cafe;oleo de soja");
    mostrar(";;");
    return 0;
}
// Saída:
// 4 itens: [arroz] [feijao] [cafe] [oleo de soja]
// 3 itens: [] [] []
