// A021 · Quantas caixas de piso comprar

#include <stdio.h>
#include <math.h>

#define PERDA 1.10          // 10% a mais para os recortes
#define M2_POR_CAIXA 2.5    // cada caixa cobre 2,5 m²

int main(void) {
    double largura = 0, comprimento = 0, preco_caixa = 0;

    // entrada: o retorno de cada scanf vai somando no total de leituras
    printf("Largura do cômodo (m): ");
    int leituras = scanf("%lf", &largura);
    printf("Comprimento (m): ");
    leituras += scanf("%lf", &comprimento);
    printf("Preço da caixa (R$): ");
    leituras += scanf("%lf", &preco_caixa);

    // processamento
    double area = largura * comprimento;
    double area_compra = area;
    area_compra *= PERDA;
    int caixas = (int) ceil(area_compra / M2_POR_CAIXA); // caixa não vem pela metade
    double total = caixas * preco_caixa;
    double sobra = caixas * M2_POR_CAIXA - area_compra;

    // saída: rótulos com acento direto no formato, porque a largura do %s
    // conta bytes, e cada letra acentuada ocupa 2
    printf("\nÁrea do cômodo:   %8.2f m²\n", area);
    printf("Com 10%% de perda: %8.2f m²\n", area_compra);
    printf("Caixas:           %8d\n", caixas);
    printf("Sobra na última:  %8.2f m²\n", sobra);
    printf("Total (R$):       %8.2f\n", total);
    printf("(leituras certas: %d de 3)\n", leituras);
    return 0;
}
// Exemplo de execução:
// Largura do cômodo (m): 3.2
// Comprimento (m): 4.5
// Preço da caixa (R$): 89.90
//
// Área do cômodo:      14.40 m²
// Com 10% de perda:    15.84 m²
// Caixas:                  7
// Sobra na última:      1.66 m²
// Total (R$):         629.30
// (leituras certas: 3 de 3)
//
// Teste: printf '3.2\n4.5\n89.90\n' | ~/LPEDC/rodar <este arquivo>
// Com uma letra no preço, printf '3.2\n4.5\nabc\n' | ~/LPEDC/rodar <este arquivo>
// mostra "(leituras certas: 2 de 3)" e o total sai 0.00: o preço ficou com
// o valor inicial. No módulo 02, com o if, o programa vai poder parar ali.
