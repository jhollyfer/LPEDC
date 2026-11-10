// Lista · Módulo 13 · Busca e ordenação
// Exercício P1325 · ★★★ · Duas passadas estáveis, uma chave composta
//
// O motoboy quer as entregas agrupadas por bairro (em ordem alfabética) e,
// dentro de cada bairro, por hora. Em vez de uma compara com dois critérios,
// dá para ordenar DUAS VEZES com um algoritmo estável: primeiro pela chave
// secundária (hora), depois pela principal (bairro). A segunda passada não
// desfaz a primeira entre os empatados, justamente porque é estável.
//
// Escreva por_hora e por_bairro, dois insertion sorts estáveis (o de bairro
// compara com strcmp). Ordene uma cópia na ordem certa (hora, depois bairro)
// e outra na ordem trocada (bairro, depois hora) e mostre as duas com
// printf("  %-8s %02d:00 pedido %d\n", ...).
//
//   typedef struct { char bairro[12]; int hora; int pedido; } Entrega;
//
//   Entregas: Centro 15h (101), Aleixo 11h (102), Centro 9h (103),
//   Flores 14h (104), Aleixo 8h (105), Centro 12h (106), Flores 10h (107)
//
//   Saída esperada:
//   hora, depois bairro (certo):
//     Aleixo   08:00 pedido 105
//     Aleixo   11:00 pedido 102
//     Centro   09:00 pedido 103
//     Centro   12:00 pedido 106
//     Centro   15:00 pedido 101
//     Flores   10:00 pedido 107
//     Flores   14:00 pedido 104
//   bairro, depois hora (errado):
//     Aleixo   08:00 pedido 105
//     Centro   09:00 pedido 103
//     Flores   10:00 pedido 107
//     Aleixo   11:00 pedido 102
//     Centro   12:00 pedido 106
//     Flores   14:00 pedido 104
//     Centro   15:00 pedido 101
//
// Dicas:
// 1. Os dois insertion sorts usam > no while (strcmp(...) > 0 no de bairro).
// 2. Na ordem trocada, a última passada (por hora) manda: o bairro só serve
//    de desempate entre horas iguais, e aqui nenhuma hora se repete.
// 3. Se você trocar o insertion por um selection na segunda passada, a ordem
//    das horas dentro do bairro pode se perder. É a mesma ideia do radix sort
//    (módulo 18).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

typedef struct {
    char bairro[12];
    int hora;
    int pedido;
} Entrega;

int main(void) {

    return 0;
}
