// 0103 · Heapsort
// Exercício E618 · ★★★
//
// A organização da corrida quer a lista dos inscritos em ordem alfabética.
// Escreva do zero um heapsort para um vetor de strings (const char *),
// comparando com strcmp, e ordene:
//
//   Nomes: Paula Bruno Zeca Ana Marcos Carla Igor Beatriz
//
//   Saída esperada:
//   Ana
//   Beatriz
//   Bruno
//   Carla
//   Igor
//   Marcos
//   Paula
//   Zeca
//
// Dicas:
// 1. É o heapsort do texto com duas trocas: o vetor é de const char *, e
//    "v[a] > v[b]" vira "strcmp(v[a], v[b]) > 0".
// 2. A troca só troca os PONTEIROS: as letras não saem do lugar. Por isso a
//    função recebe const char *v[] e a troca usa um const char * auxiliar.
// 3. Resposta esperada: a lista acima, um nome por linha.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *nomes[] = {"Paula", "Bruno", "Zeca", "Ana", "Marcos", "Carla", "Igor", "Beatriz"};
    (void)nomes; // apague esta linha

    return 0;
}
