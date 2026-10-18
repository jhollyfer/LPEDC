// 0080 · Vetor dinâmico
// Exercício E479 · ★★★
//
// Este programa guarda as velocidades medidas por um radar num vetor que
// cresce. Ele compila sem aviso, mas tem TRÊS problemas de propósito: dois o
// AddressSanitizer acusa quando você roda, e o terceiro só morderia num dia
// em que faltasse memória. Rode, leia o relatório, ache os três e conserte.
//
//   Saída esperada depois do conserto:
//   primeiro: 40
//   40 50 60 70 80 90
//
// Dicas:
// 1. O primeiro relatório é "heap-buffer-overflow" dentro de vetor_insere:
//    o realloc recebe um número de BYTES.
// 2. Conserte e rode de novo. O segundo é "heap-use-after-free" no printf
//    do primeiro: depois que o vetor muda de lugar, o endereço guardado em
//    "primeiro" aponta para o bloco antigo, já devolvido.
// 3. O terceiro: "v->itens = realloc(v->itens, ...)". Se o realloc devolver
//    NULL, o endereço do bloco antigo se perde (vazamento) e a lista some.
// 4. Resposta esperada: realloc(v->itens, nova_cap * sizeof(int)) guardando
//    o resultado numa variável temporária antes de trocar v->itens; e guardar
//    a POSIÇÃO (índice 0) em vez do endereço, lendo v.itens[0] no fim.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *itens;
    int tam;
    int cap;
} Vetor;

static bool vetor_insere(Vetor *v, int valor) {
    if (v->tam == v->cap) {
        v->cap = v->cap * 2;
        v->itens = realloc(v->itens, v->cap);
        if (v->itens == NULL) return false;
    }
    v->itens[v->tam] = valor;
    v->tam++;
    return true;
}

int main(void) {
    Vetor v = {malloc(2 * sizeof(int)), 0, 2};
    if (v.itens == NULL) return 1;

    vetor_insere(&v, 40);
    int *primeiro = &v.itens[0];
    for (int vel = 50; vel <= 90; vel += 10) {
        vetor_insere(&v, vel);
    }

    printf("primeiro: %d\n", *primeiro);
    for (int i = 0; i < v.tam; i++) {
        printf("%d ", v.itens[i]);
    }
    printf("\n");

    free(v.itens);
    return 0;
}
