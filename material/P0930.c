// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0930 · ★★★ · O índice da biblioteca
//
// Os livros da biblioteca estão num arquivo de dados na ordem em que
// chegaram, então a busca por código seria sequencial. A solução dos bancos
// de dados é um ÍNDICE: um segundo arquivo, pequeno e ordenado, com pares
// (código, posição no arquivo de dados). Busca-se no índice (binária) e
// depois se vai direto ao registro com um fseek.
//
// 1. Grave em /tmp/p0930_dados.bin, nesta ordem: 3071 Vidas Secas 1938,
//    1150 Macunaima 1928, 4420 Iracema 1865, 2088 Dom Casmurro 1899,
//    1999 O Cortico 1890 e 3500 Grande Sertao 1956.
// 2. Monte um vetor de Entrada {codigo, posicao}, ordene com qsort e grave
//    em /tmp/p0930_indice.bin.
// 3. Escreva long procura(FILE *indice, int codigo, int *leituras): busca
//    binária NO ARQUIVO de índice que devolve a posição no arquivo de dados
//    (ou -1), contando os fread.
// 4. Procure 2088, 4420 e 1000, leia o livro no arquivo de dados e mostre.
//    Apague os dois arquivos no fim.
//
//   Saída esperada:
//   Índice: 1150 1999 2088 3071 3500 4420
//   2088: Dom Casmurro (1899), registro 3, 1 leitura no índice
//   4420: Iracema (1865), registro 2, 3 leituras no índice
//   1000: não cadastrado, 2 leituras no índice
//
// Dicas:
// 1. O índice tem n entradas: o tamanho do arquivo de índice dividido por
//    sizeof(Entrada).
// 2. Achou a entrada? fseek(dados, e.posicao * sizeof(Livro), SEEK_SET) e
//    um fread trazem o livro.
// 3. Por que não ordenar o próprio arquivo de dados? Porque registros
//    grandes custam caro para mover, e dá para ter vários índices (por
//    código, por ano...) sobre os mesmos dados.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    char titulo[24];
    int ano;
} Livro;

typedef struct {
    int codigo;
    int posicao; // número do registro no arquivo de dados
} Entrada;

int main(void) {

    return 0;
}
