// 0045 · Ponteiros
// Exercício E267 · ★★☆
//
// Este programa da academia tem TRÊS erros com ponteiros, de propósito.
// Ele deveria mostrar:
//
//   Peso: 82
//   Meta: 78
//
// Rode com o rodar e conserte um erro de cada vez: primeiro o compilador
// recusa o código; depois avisa; por fim o AddressSanitizer reclama quando
// roda. Ache os três erros e conserte.
//
// Dicas:
// 1. Em int *peso_ptr, meta_ptr; quantos ponteiros foram declarados?
// 2. Um ponteiro precisa apontar para algum lugar antes de receber *p = ...
// 3. Resposta esperada: (1) meta_ptr não é ponteiro (o * não vale para os
//    dois nomes), por isso *meta_ptr nem compila: declare
//    int *peso_ptr, *meta_ptr;. (2) meta_ptr = meta tenta guardar o valor
//    78 como endereço (aviso "makes pointer from integer"): o certo é
//    meta_ptr = &meta;. (3) peso_ptr nunca recebeu um endereço: falta
//    peso_ptr = &peso; antes de *peso_ptr = 82;.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int peso = 0, meta = 78;
    int *peso_ptr, meta_ptr;

    *peso_ptr = 82;
    meta_ptr = meta;

    printf("Peso: %d\n", peso);
    printf("Meta: %d\n", *meta_ptr);
    return 0;
}
