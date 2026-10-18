// 0069 · Union
// Exercício E413 · ★★★
//
// Resposta: o 2º item dizia REAL mas preenchia .inteiro (o double lido eram
// os bytes do int 42 com zeros: um número minúsculo, mostrado como 0.00); o
// 4º preenchia .texto mas a etiqueta dizia INTEIRO (os bytes 'o' 'k' lidos
// como int dão 27503). A etiqueta e o campo precisam combinar.

#include <stdio.h>

typedef enum { INTEIRO, REAL, TEXTO } Tipo;

typedef struct {
    Tipo tipo;
    union {
        int inteiro;
        double real;
        char texto[16];
    } dados;
} Valor;

void mostrar(const Valor *v) {
    switch (v->tipo) {
    case INTEIRO:
        printf("inteiro: %d\n", v->dados.inteiro);
        break;
    case REAL:
        printf("real: %.2f\n", v->dados.real);
        break;
    case TEXTO:
        printf("texto: %s\n", v->dados.texto);
        break;
    }
}

int main(void) {
    static Valor lista[] = {
        {INTEIRO, .dados.inteiro = 7},
        {REAL, .dados.real = 42.5},
        {TEXTO, .dados.texto = "oi"},
        {TEXTO, .dados.texto = "ok"},
    };

    for (int i = 0; i < 4; i++) {
        mostrar(&lista[i]);
    }
    return 0;
}
