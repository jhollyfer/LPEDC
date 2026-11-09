// 0188 · Aproximação
// Exercício E1126 · ★★☆
//
// Compare o first fit (FF) e o first fit decrescente (FFD) em três listas
// de cargas (barco de 10 t), sem estragar a lista original. Escreva a
// função compara(nome, carga, n), que copia a lista com memcpy, ordena a
// cópia em ordem decrescente com qsort e mostra FF, FFD e o limite
// inferior.
//
//   Lista 1: 4, 4, 6, 9, 2, 6, 7, 7
//   Lista 2: 2, 2, 2, 2, 2, 2, 7, 7, 7, 7, 7, 7
//   Lista 3: 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 5
//
//   Saída esperada:
//   Lista 1: FF 6, FFD 5, limite 5
//   Lista 2: FF 7, FFD 6, limite 6
//   Lista 3: FF 6, FFD 6, limite 5
//
// Dicas:
// 1. Comparador decrescente sem risco de estouro:
//    return (x < y) - (x > y);
// 2. FF recebe a lista original; FFD, a cópia ordenada.
// 3. Resposta esperada: a saída acima. Na lista 3 nem o FFD acha o ótimo:
//    5 viagens dão certo com (3 3 4) três vezes, (4 5) e (4 4). O FFD faz
//    (5 4), (4 4), (4 4), (4 3 3), (3 3 3), (3): as viagens de 8 t perdem
//    2 t cada, e sobra um 3 sozinho.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
