// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1923 · ★★★ · Três programadores, carga igual
//
// Uma software house tem 9 tarefas para a semana, com 9, 8, 7, 6, 5, 4, 3,
// 2 e 1 horas, e 3 programadores. O gerente quer que cada um pegue
// exatamente 15 horas. Escreva do zero o backtracking da PARTIÇÃO EM k
// GRUPOS: para cada tarefa, em ordem, tente pô-la no programador 0, 1 ou 2,
// sem passar de 15 horas. Use duas podas: (a) a carga não passa de 15; (b)
// se dois programadores estão com a mesma carga, pôr a tarefa em um ou em
// outro dá na mesma, então tente só o primeiro deles. Mostre a primeira
// divisão achada e quantas chamadas a recursão fez.
//
//   Saída esperada:
//   Programador 1: 9 6 (15 h)
//   Programador 2: 8 7 (15 h)
//   Programador 3: 5 4 3 2 1 (15 h)
//   Chamadas: 10
//
// Dicas:
// 1. distribui(i) devolve 1 quando i == 9 (todas as tarefas colocadas: como
//    a soma é 45 e ninguém passa de 15, cada um ficou com 15).
// 2. A poda (b) é um laço que olha se algum programador anterior p2 < p
//    tem carga[p2] == carga[p]; se tem, pule p. Ela evita testar as 3! = 6
//    trocas de nome dos programadores.
// 3. Resposta esperada: 9 + 6, 8 + 7 e 5 + 4 + 3 + 2 + 1 (veja as chamadas
//    na saída de cima).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
