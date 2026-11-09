// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1821 · ★★★ · O painel de partidas do aeroporto
//
// O painel de partidas do aeroporto de Manaus mostra os voos dos próximos
// dias por DIA, HORA e MINUTO e, no mesmo horário, pelo NÚMERO do voo. Os
// registros chegam fora de ordem (vetor do esqueleto).
//
// Monte a ordem com passadas estáveis de counting sort, da chave menos
// significativa para a mais: número do voo (de 0 a 9999), minuto, hora e
// dia. Use um único counting sort genérico, que recebe a chave por ponteiro
// de função e o tamanho do intervalo. Mostre a ordem dos números de voo
// depois de cada passada, o painel final e a conferência com o qsort usando
// um comparador de quatro critérios.
//
//   Saída esperada:
//   por número: 1190 1501 1502 1777 2011 2210 2788 3320 3999 4410
//   por minuto: 1777 3999 2788 3320 1502 2210 1190 1501 4410 2011
//   por hora:   1502 2210 1777 3999 2788 3320 2011 1190 1501 4410
//   por dia:    1502 1190 1501 2210 2788 3320 2011 1777 3999 4410
//   Data  Hora    Voo  Destino
//   09/11 06:15  1502  Brasilia
//   09/11 21:30  1190  Boa Vista
//   09/11 21:30  1501  Brasilia
//   10/11 06:15  2210  Porto Velho
//   10/11 14:05  2788  Sao Paulo
//   10/11 14:05  3320  Belem
//   10/11 14:50  2011  Santarem
//   11/11 08:00  1777  Rio
//   11/11 08:00  3999  Recife
//   11/11 23:40  4410  Fortaleza
//   qsort concorda: sim
//
// Dicas:
// 1. Os números de voo vão até 9999: o vetor C dessa passada tem 10000
//    posições (static). As outras têm 60, 24 e 31.
// 2. O comparador do qsort compara dia; se empatar, hora; depois minuto;
//    depois número. Os dois métodos têm de dar a mesma sequência.
// 3. As passadas custam Θ(4n + 10000 + 60 + 24 + 31): com poucos voos, o
//    10000 domina. Com milhões de voos, é linear e ganha do qsort.
// 4. Resposta esperada: o painel começa com o voo 1502 do dia 9 às 06:15 e
//    termina com o 4410 do dia 11 às 23:40; o qsort concorda.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct {
    int numero, dia, hora, minuto;
    const char *destino;
} Voo;

int main(void) {
    Voo v[N] = {{3320, 10, 14, 5, "Belem"},     {1502, 9, 6, 15, "Brasilia"},
                {2788, 10, 14, 5, "Sao Paulo"}, {4410, 11, 23, 40, "Fortaleza"},
                {1190, 9, 21, 30, "Boa Vista"}, {2210, 10, 6, 15, "Porto Velho"},
                {1501, 9, 21, 30, "Brasilia"},  {3999, 11, 8, 0, "Recife"},
                {2011, 10, 14, 50, "Santarem"}, {1777, 11, 8, 0, "Rio"}};

    for (int i = 0; i < N; i++) printf("%d ", v[i].numero);
    printf("\n");
    return 0;
}
