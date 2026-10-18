// 0163 · Skip list
// Exercício E975 · ★★☆
//
// A moeda da skip list não precisa ser honesta. Com probabilidade 1/4 de
// subir, os nós ficam mais baixos: menos ponteiros. Será que a busca fica
// muito mais lenta? Faça o experimento com 4000 chaves (1 a 4000):
// - complete sorteia(&estado, lados): começa com 1 andar e sobe mais um
//   enquanto (proximo(&estado) >> 16) % lados == 0, sem passar de SKIP_MAX;
// - complete experimento(lados): monta a skip list com
//   skip_insere_andares e os andares sorteados (estado começa em 7), busca
//   cada chave somando os nós olhados e mostra uma linha como abaixo.
//
//   Saída esperada:
//   1/2: 7997 ponteiros, 21.9 nós olhados por busca
//   1/4: 5410 ponteiros, 21.6 nós olhados por busca
//
// Dicas:
// 1. lados = 2 é a moeda de sempre (1/2); lados = 4 sobe com 1/4. Use o
//    proximo() pronto: os bits de baixo desse tipo de gerador são ruins,
//    por isso o >> 16.
// 2. Ponteiros em uso = soma dos andares de todos os nós. A média é o total
//    de passos (de skip_busca) dividido por 4000.0.
// 3. Resposta esperada: a saída acima. Com 1/4, a skip list usa um terço a
//    menos de ponteiros e a busca custa praticamente o mesmo: há menos
//    andares, mas anda-se mais em cada um.
//
// Escreva sua resposta abaixo (complete as duas funções):

#include <stdio.h>
#include "skip.h"

#define N 4000

unsigned proximo(unsigned *estado) {
    *estado = *estado * 1103515245u + 12345u;
    return *estado;
}

int sorteia(unsigned *estado, int lados) {
    (void)estado; // apague estas duas linhas
    (void)lados;
    return 1;
}

void experimento(int lados) {
    (void)lados; // apague esta linha
}

int main(void) {
    experimento(2);
    experimento(4);
    return 0;
}
