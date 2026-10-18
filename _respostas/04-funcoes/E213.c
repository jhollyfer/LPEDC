// 0036 · A pilha de chamadas
// Exercício E213 · ★★☆

#include <stdio.h>

void recuo(int nivel) {
    for (int i = 0; i < nivel; i++) {
        printf("  ");
    }
}

void consultar_banco(int nivel) {
    recuo(nivel);
    printf("consultar_banco: aprovado\n");
}

void antifraude(int nivel) {
    recuo(nivel);
    printf("entra antifraude\n");
    consultar_banco(nivel + 1);
    recuo(nivel);
    printf("sai antifraude\n");
}

void pagar(int nivel) {
    recuo(nivel);
    printf("entra pagar\n");
    antifraude(nivel + 1);
    recuo(nivel);
    printf("sai pagar\n");
}

void finalizar_compra(int nivel) {
    recuo(nivel);
    printf("entra finalizar_compra\n");
    pagar(nivel + 1);
    recuo(nivel);
    printf("sai finalizar_compra\n");
}

int main(void) {
    finalizar_compra(0);
    return 0;
}
