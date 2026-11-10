// Lista · Módulo 13 · Busca e ordenação
// Exercício P1330 · ★★★ · A agenda do posto de saúde
//
// O posto guarda as consultas como structs, fora de ordem:
//
//   typedef struct { int data; int hora; char paciente[12]; } Consulta;
//   // data no formato aaaammdd, hora no formato hhmm
//
//   {20261112, 1030, "Marta"}, {20261110, 900, "Joao"}, {20261112, 800, "Ivo"},
//   {20261111, 1400, "Sara"}, {20261110, 1500, "Lia"}, {20261112, 1330, "Davi"},
//   {20261110, 730, "Rosa"}, {20261114, 1000, "Tito"}
//
// a) Ordene com qsort pela chave composta (data, depois hora).
// b) Escreva int primeira_do_dia(const Consulta v[], int n, int data): busca
//    binária que devolve a primeira posição com v[i].data >= data (de 0 a n).
// c) Escreva void lista_dia(v, n, data), que mostra o dia (dd/mm) e, a partir
//    da primeira posição, todas as consultas daquele dia; ou "nenhuma
//    consulta".
//
// Liste os dias 10, 12, 13 e 14 de novembro de 2026.
//
//   Saída esperada:
//   10/11: 07:30 Rosa; 09:00 Joao; 15:00 Lia;
//   12/11: 08:00 Ivo; 10:30 Marta; 13:30 Davi;
//   13/11: nenhuma consulta
//   14/11: 10:00 Tito;
//
// Dicas:
// 1. Na compara, só olhe a hora se as datas forem iguais.
// 2. O dia é data % 100 e o mês é data / 100 % 100; a hora é hora / 100 e os
//    minutos, hora % 100. Use %02d.
// 3. Para o dia 13, a busca devolve a posição do Tito (o primeiro >= 13), que
//    não é do dia 13: confira v[i].data antes de listar. Para um dia depois
//    do último, ela devolve n.
// 4. A busca custa O(log n) e a listagem O(k), com k consultas no dia: é
//    assim que agendas grandes respondem rápido.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    int hora;
    char paciente[12];
} Consulta;

int main(void) {

    return 0;
}
