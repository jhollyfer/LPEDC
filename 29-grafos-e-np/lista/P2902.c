// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2902 · ★☆☆ · Fontes e sumidouros
//
// A reforma de uma casa tem oito tarefas (0 a 7): Projeto, Demolição,
// Elétrica, Hidráulica, Reboco, Piso, Pintura e Limpeza. A seta a -> b diz
// "a precisa acabar antes de b":
//
//   Projeto->Demolição, Demolição->Elétrica, Demolição->Hidráulica,
//   Elétrica->Reboco, Hidráulica->Reboco, Reboco->Piso, Reboco->Pintura,
//   Piso->Limpeza, Pintura->Limpeza
//
// Escreva o programa: mostre o grau de entrada e o de saída de cada tarefa,
// confira que as duas somas dão E e liste as FONTES (grau de entrada 0:
// podem começar já) e os SUMIDOUROS (grau de saída 0: ninguém depende delas).
//
//   Saída esperada:
//   Projeto: entrada 0, saída 1
//   Demolição: entrada 1, saída 2
//   Elétrica: entrada 1, saída 1
//   Hidráulica: entrada 1, saída 1
//   Reboco: entrada 2, saída 2
//   Piso: entrada 1, saída 1
//   Pintura: entrada 1, saída 1
//   Limpeza: entrada 2, saída 0
//   Somas: entrada 9, saída 9
//   Fontes: Projeto
//   Sumidouros: Limpeza
//
// Dicas:
// 1. Entrada de u é a coluna u da matriz; saída, a linha u.
// 2. No dirigido, cada seta conta 1 na saída de quem sai e 1 na entrada de quem
//    chega: as duas somas valem E = 9.
// 3. Resposta esperada: a saída acima. Num grafo sem ciclo existe sempre pelo
//    menos uma fonte e um sumidouro.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
