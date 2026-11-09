// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2016 · ★★☆ · O menor atraso da gráfica
//
// A gráfica tem 5 encomendas e uma impressora só. Cada encomenda tem a
// duração (em horas) e o prazo (a hora, contando do início do dia, em que
// o cliente vem buscar):
//
//   encomenda   convites  cardápios  banner  folhetos  crachás
//   duração         3          2        4        1         2
//   prazo           6          4       10        3         7
//
// O atraso de uma encomenda é max(0, fim - prazo). O guloso PRAZO MAIS
// CEDO PRIMEIRO (ordenar por prazo) minimiza o MAIOR atraso. Escreva do
// zero: compare a ordem da tabela com a ordem por prazo, mostrando o
// início e o fim de cada encomenda e o maior atraso de cada ordem.
//
//   Saída esperada:
//   Ordem da tabela:
//     convites: 0 a 3 (prazo 6, atraso 0)
//     cardápios: 3 a 5 (prazo 4, atraso 1)
//     banner: 5 a 9 (prazo 10, atraso 0)
//     folhetos: 9 a 10 (prazo 3, atraso 7)
//     crachás: 10 a 12 (prazo 7, atraso 5)
//     Maior atraso: 7 h
//   Prazo mais cedo primeiro:
//     folhetos: 0 a 1 (prazo 3, atraso 0)
//     cardápios: 1 a 3 (prazo 4, atraso 0)
//     convites: 3 a 6 (prazo 6, atraso 0)
//     crachás: 6 a 8 (prazo 7, atraso 1)
//     banner: 8 a 12 (prazo 10, atraso 2)
//     Maior atraso: 2 h
//
// Dicas:
// 1. Use um struct { nome, dur, prazo } e qsort pelo prazo para a segunda
//    ordem. A hora corrente começa em 0 e soma a duração de cada uma.
// 2. Por que funciona? Trocar duas encomendas vizinhas fora da ordem de
//    prazo nunca aumenta o maior atraso (o argumento de troca do Cormen).
// 3. Resposta esperada: a ordem da tabela tem atraso máximo 7 (os folhetos
//    ficam prontos às 10, com prazo 3) e a ordem por prazo, só 2.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
