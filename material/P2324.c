// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2324 · ★★★ · A carreta mais pesada
//
// Cada estrada entre seis cidades tem um limite de peso (toneladas, mão
// dupla). Uma carreta passa por um caminho se aguentar o trecho MAIS
// FRACO dele. Para cada par de cidades, qual a carreta mais pesada que
// consegue ir de uma à outra? As estradas:
//
//   Manaus-Itacoatiara 40, Manaus-Humaitá 18, Itacoatiara-Humaitá 25,
//   Humaitá-Porto Velho 30, Itacoatiara-Porto Velho 12, Humaitá-Lábrea 22,
//   Porto Velho-Lábrea 35, Manaus-Tefé 15, Tefé-Lábrea 28
//
// Escreva do zero uma variação do Floyd-Warshall (o caminho de GARGALO
// máximo): passar por k vale min(cap[i][k], cap[k][j]), e fica o maior.
// Use 0 para "sem estrada" e ignore a diagonal. Mostre a tabela com as
// siglas MAO ITA HUM PVH LAB TEF e as duas perguntas do fim.
//
//   Saída esperada:
//        MAO ITA HUM PVH LAB TEF
//   MAO    -  40  25  25  25  25
//   ITA   40   -  25  25  25  25
//   HUM   25  25   -  30  30  28
//   PVH   25  25  30   -  35  28
//   LAB   25  25  30  35   -  28
//   TEF   25  25  28  28  28   -
//   Manaus -> Porto Velho: até 25 t
//   Tefé -> Lábrea: até 28 t
//
// Dicas:
// 1. A troca é "max no lugar de min, min no lugar de +": o resto do Floyd
//    (o k por fora, a ordem dos laços) fica igual.
// 2. Sem estrada vale 0, e min(0, x) = 0: "não passa nada" se comporta
//    sozinho, sem precisar de INF.
// 3. Resposta esperada: Manaus -> Porto Velho até 25 t (por Itacoatiara e
//    Humaitá; a estrada Manaus-Humaitá aguenta só 18) e Tefé -> Lábrea até
//    28 t, a estrada direta.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
