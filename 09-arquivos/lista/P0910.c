// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0910 · ★☆☆ · Os preços da feira pela linha de comando
//
// Os preços chegam pela linha de comando. Grave cada um em
// /tmp/p0910_precos.txt, um por linha e com duas casas. Feche, reabra para
// leitura, some tudo com fscanf e mostre quantos preços foram gravados e o
// total. Sem argumentos, mostre "uso: P0910 preco1 preco2 ..." e termine
// com return 1. Apague o arquivo no fim.
//
//   $ ./rodar P0910.c 12.50 3.99 7.00
//
//   Saída esperada:
//   3 preços gravados
//   Total: R$ 23.49
//
// Dicas:
// 1. argv[i] é texto: atof(argv[i]) transforma "12.50" em 12.5.
// 2. Grave com fprintf(arq, "%.2f\n", preco) e leia com fscanf(arq, "%lf",
//    &preco) num while que confere se devolveu 1.
// 3. Resposta esperada: 3 preços gravados e Total: R$ 23.49.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    (void) argc; // apague estas duas linhas quando usar argc e argv
    (void) argv;

    return 0;
}
