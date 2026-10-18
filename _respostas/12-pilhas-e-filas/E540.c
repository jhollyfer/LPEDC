// 0090 · Fila
// Exercício E540 · ★★★

#include <stdio.h>
// Na pasta do assunto basta #include "fila.h" (o rodar compila o fila.c
// junto). Aqui a resolução inclui a implementação para compilar sozinha.
#include "../../12-pilhas-e-filas/0090-fila/fila.c"

#define JANELA 3

int main(void) {
    Fila *janela = fila_cria();
    if (janela == NULL) {
        return 1;
    }
    int leituras[] = {60, 64, 70, 66, 58, 62};
    int soma = 0;

    for (int i = 0; i < 6; i++) {
        fila_insere(janela, leituras[i]);
        soma += leituras[i];
        if (fila_tamanho(janela) > JANELA) { // o mais antigo sai da janela
            int velho;
            fila_retira(janela, &velho);
            soma -= velho;
        }
        if (fila_tamanho(janela) == JANELA) {
            printf("Leitura %d: média %.1f km/h\n", i + 1, soma / (double)JANELA);
        }
    }

    fila_libera(janela);
    return 0;
}
