// 0163 · Skip list
// Exercício E975 · ★★☆
//
// A moeda da skip list não precisa ser honesta. Com probabilidade 1/4 de
// subir, os nós ficam mais baixos: menos ponteiros. Será que a busca fica
// muito mais lenta? Faça o experimento com 4000 chaves (1 a 4000):
// - escreva int sorteia(unsigned *estado, int lados): começa com 1 andar e
//   sobe mais um enquanto (proximo(estado) >> 16) % lados == 0, sem passar
//   de SKIP_MAX;
// - escreva void experimento(int lados): monta a skip list com
//   skip_insere_andares e os andares sorteados (estado começa em 7), busca
//   cada chave somando os nós olhados e mostra uma linha como abaixo.
//
//   Saída esperada:
//   1/2: 7997 ponteiros, 21.9 nós olhados por busca
//   1/4: 5410 ponteiros, 21.6 nós olhados por busca
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "skip.h"

#define N 4000

unsigned proximo(unsigned *estado) {
    *estado = *estado * 1103515245u + 12345u;
    return *estado;
}

int main(void) {

    return 0;
}
