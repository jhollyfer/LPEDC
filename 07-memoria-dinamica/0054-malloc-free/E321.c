// 0054 · malloc e free
// Exercício E321 · ★★☆
//
// Escreva a função
//
//   int *filtrar_pares(const int *v, int n, int *qtd);
//
// que devolve um vetor NOVO, no heap, só com os números pares de v, do
// tamanho exato. A quantidade de pares volta por *qtd. Teste com os números
// sorteados 7, 4, 10, 3, 8, 1, 6.
//
//   Saída esperada:
//   4 pares: 4 10 8 6
//
// Dicas:
// 1. Duas passadas: a primeira só conta os pares; com a contagem, faça o
//    malloc; a segunda copia.
// 2. *qtd = contagem; é o "devolver mais de um valor" do assunto 0046.
// 3. Resposta esperada: "4 pares: 4 10 8 6". Quem chama faz o free. Se não
//    houver pares, malloc(0) pode devolver NULL ou um endereço válido; trate
//    esse caso antes (devolva NULL com *qtd = 0).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
