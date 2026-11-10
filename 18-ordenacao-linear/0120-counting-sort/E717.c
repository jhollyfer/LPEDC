// 0120 · Counting sort
// Exercício E717 · ★★☆
//
// Na triagem do pronto-socorro, cada paciente recebe uma cor de risco:
// vermelho, laranja, amarelo, verde ou azul, do mais grave para o menos
// grave. A fila de atendimento é por cor e, dentro da mesma cor, por ordem
// de chegada. Escreva ordena_triagem, um counting sort ESTÁVEL que usa como
// chave a posição da cor no vetor ordem_cores, e mostre a fila.
//
//   Saída esperada:
//    1. Rita  (vermelho)
//    2. Otto  (vermelho)
//    3. Davi  (laranja)
//    4. Ivo   (laranja)
//    5. Joana (amarelo)
//    6. Caio  (amarelo)
//    7. Sara  (amarelo)
//    8. Pedro (verde)
//    9. Nina  (verde)
//   10. Lia   (azul)
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

#define CORES 5

typedef struct {
    char nome[12];
    char cor[10];
} Paciente;

const char *ordem_cores[CORES] = {"vermelho", "laranja", "amarelo", "verde", "azul"};

int main(void) {
    Paciente chegada[] = {
        {"Joana", "amarelo"}, {"Pedro", "verde"}, {"Rita", "vermelho"}, {"Caio", "amarelo"},
        {"Lia", "azul"}, {"Davi", "laranja"}, {"Nina", "verde"}, {"Otto", "vermelho"},
        {"Sara", "amarelo"}, {"Ivo", "laranja"},
    };
    (void) chegada; // apague esta linha

    return 0;
}
