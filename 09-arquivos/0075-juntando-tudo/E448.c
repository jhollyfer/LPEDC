// 0075 · Juntando tudo
// Exercício E448 · ★★☆
//
// Relatório de vendas da feira. O programa:
//
// 1. grava em /tmp/vendas.bin quatro vendas, como registros de
// struct { char produto[16]; int qtd; double preco; }:
// pastel 30 x 8.00, caldo de cana 25 x 6.50, tapioca 12 x 10.00 e
// queijo 4 x 35.00 (use os nomes sem acento);
// 2. exporta para CSV (texto, separado por ';', com cabeçalho) no arquivo
// cujo nome vem em argv[1]. Sem argumento, usa /tmp/vendas.csv;
// 3. reabre o CSV, mostra o conteúdo com fgets e, por fim, o total geral.
//
//   $ rodar E448.c
//   produto;qtd;total
//   pastel;30;240.00
//   caldo de cana;25;162.50
//   tapioca;12;120.00
//   queijo;4;140.00
//   Total geral: R$ 662.50 (gravado em /tmp/vendas.csv)
//
// Dicas:
// 1. const char *destino = argc >= 2 ? argv[1] : "/tmp/vendas.csv";
// 2. Leia o binário com while (fread(&v, sizeof v, 1, ent) == 1) e vá
//    escrevendo no CSV com fprintf(sai, "%s;%d;%.2f\n", ...).
// 3. "caldo de cana" tem espaços: por isso o separador é ';' e não espaço.
// 4. Resposta esperada: as 5 linhas do CSV e Total geral: R$ 662.50.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(int argc, char *argv[]) {
    (void) argc; // apague estas duas linhas quando usar argc e argv
    (void) argv;

    return 0;
}
