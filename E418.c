// 0070 · Juntando tudo
// Exercício E418 · ★★☆
//
// Relatório de vendas da feira. Escreva um programa que:
//
// 1. grava em /tmp/vendas.bin quatro vendas, como registros de
//    struct { char produto[16]; int qtd; double preco; }: pastel 30 x 8.00,
//    caldo de cana 25 x 6.50, tapioca 12 x 10.00 e queijo 4 x 35.00;
// 2. exporta para CSV (texto, separado por ';', com cabeçalho) no arquivo
//    cujo nome vem em argv[1] (sem argumento, usa /tmp/vendas.csv);
// 3. reabre o CSV, mostra o conteúdo com fgets e, por fim, o total geral.
//
//   Argumentos:
//   (nenhum)
//
//   Saída esperada:
//   produto;qtd;total
//   pastel;30;240.00
//   caldo de cana;25;162.50
//   tapioca;12;120.00
//   queijo;4;140.00
//   Total geral: R$ 662.50 (gravado em /tmp/vendas.csv)
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(int argc, char *argv[]) {
    (void) argc;
    (void) argv;

    return 0;
}
