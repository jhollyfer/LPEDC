// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2819 · ★★☆ · Aniversários em duas passadas
//
// O RH quer os aniversários do ano em ordem de mês e, dentro do mês, de dia.
// Faça duas passadas de pigeonhole estável: primeiro pelo dia (31 casas),
// depois pelo mês (12 casas). Datas (dia/mês) e nomes: Ana 15/3, Beto 2/11,
// Cris 28/3, Duda 2/3, Enzo 15/1, Fábio 9/11, Gil 1/12, Hana 30/1. Mostre a
// lista depois de cada passada.
//
//   Saída esperada:
//   por dia: Gil 1/12 Beto 2/11 Duda 2/3 Fabio 9/11 Ana 15/3 Enzo 15/1 Cris 28/3 Hana 30/1
//   por mês: Enzo 15/1 Hana 30/1 Duda 2/3 Ana 15/3 Cris 28/3 Beto 2/11 Fabio 9/11 Gil 1/12
//
// Dicas:
// 1. Uma função genérica com chave = 0 (dia) ou 1 (mês) evita escrever o
//    código duas vezes.
// 2. Cada passada: para cada casa em ordem, copie da entrada, em ordem,
//    quem cai nela.
// 3. A última passada é a da chave principal (o mês).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
