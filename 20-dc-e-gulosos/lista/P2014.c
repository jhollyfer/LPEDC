// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2014 · ★★☆ · Quantas salas para o congresso?
//
// O congresso de computação em Manaus tem 9 palestras, cada uma num
// intervalo [ini, fim) em horas:
//
//   [9, 11) [9, 10) [10, 12) [11, 13) [10, 11) [12, 14) [13, 15) [9, 12)
//   [14, 16)
//
// Qual é o MENOR número de salas para que nenhuma palestra tenha choque?
// Diferente da seleção de atividades (que escolhe um subconjunto), aqui
// todas acontecem. O guloso: ordene pelo início e ponha cada palestra
// numa sala que já ficou livre (fim da última palestra dela <= ini); se
// nenhuma está livre, abra uma sala nova. Escreva do zero e mostre a sala
// de cada palestra e o total.
//
//   Saída esperada:
//   [9, 10) -> sala 1
//   [9, 11) -> sala 2
//   [9, 12) -> sala 3
//   [10, 11) -> sala 1
//   [10, 12) -> sala 4
//   [11, 13) -> sala 1
//   [12, 14) -> sala 2
//   [13, 15) -> sala 1
//   [14, 16) -> sala 2
//   Salas: 4
//
// Dicas:
// 1. Guarde livre_em[s], a hora em que a sala s fica livre. Para cada
//    palestra, na ordem do início, use a primeira sala com livre_em[s] <=
//    ini.
// 2. Ordene por início com qsort num vetor de structs { ini, fim }; empate
//    de início, o que termina antes vem primeiro.
// 3. Resposta esperada: 3 salas. Às 10h30 há três palestras ao mesmo tempo
//    ([9, 11), [10, 12) e [9, 12)... e mais [10, 11)?) — confira na saída:
//    o máximo de palestras simultâneas é o número de salas.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
