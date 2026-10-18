// 0064 · Union
// Exercício E383 · ★★★
//
// Este programa compila sem aviso e roda sem erro do sanitizer, mas duas
// linhas saem erradas: um "real" aparece como 0.00 e um "texto" aparece como
// um número estranho. O C não confere a etiqueta de uma union: isso é
// trabalho seu. Rode, ache os dois erros, conserte e rode de novo.
//
//   Saída esperada (depois de consertado):
//   inteiro: 7
//   real: 42.50
//   texto: oi
//   texto: ok
//
// Dicas:
// 1. Para cada item do vetor, compare a etiqueta (tipo) com o campo da union
//    que foi preenchido.
// 2. O número estranho é 27503 = 0x6B6F: são os códigos ASCII de 'k' (0x6B) e
//    'o' (0x6F), lidos como um int num PC little-endian.
// 3. Resposta esperada: o 2º item tem tipo REAL mas preencheu .inteiro (use
//    .dados.real = 42.5); o 4º preencheu .texto mas a etiqueta diz INTEIRO
//    (use TEXTO).
//
// Escreva sua resposta abaixo (conserte o código):

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
        {REAL, .dados.inteiro = 42},
        {TEXTO, .dados.texto = "oi"},
        {INTEIRO, .dados.texto = "ok"},
    };

    for (int i = 0; i < 4; i++) {
        mostrar(&lista[i]);
    }
    return 0;
}
