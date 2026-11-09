// Lista · Módulo 13 · Busca e ordenação
// Exercício P1311 · ★★☆ · O primeiro boleto do dia
//
// O app do banco guarda os dias de vencimento dos boletos do mês, em ordem
// crescente e com repetidos:
//
//   2, 3, 5, 5, 5, 5, 9, 10, 12, 12, 12, 15, 18, 20, 20, 25
//
// Ele quer a PRIMEIRA posição de um dia (o primeiro boleto daquele dia).
// Escreva duas funções que devolvem essa posição (ou -1) e contam em *comp
// quantas vezes compararam o vetor:
//
//   int primeira_binaria(const int v[], int n, int x, int *comp)
//   int primeira_sequencial(const int v[], int n, int x, int *comp)
//
// A binária não pode parar quando acha: ela guarda a posição e continua
// procurando na metade da esquerda. Conte 1 comparação por volta do while
// (na binária) e 1 por posição olhada (na sequencial). Teste os dias 5, 12,
// 20 e 7.
//
//   Saída esperada:
//   dia 5: binária 2 (4 comp.), sequencial 2 (3 comp.)
//   dia 12: binária 8 (4 comp.), sequencial 8 (9 comp.)
//   dia 20: binária 13 (4 comp.), sequencial 13 (14 comp.)
//   dia 7: binária -1 (4 comp.), sequencial -1 (16 comp.)
//
// Dicas:
// 1. Comece com achou = -1. Quando v[meio] == x, faça achou = meio e
//    fim = meio - 1.
// 2. A binária sempre roda até o intervalo esvaziar: com 16 elementos, são 4
//    ou 5 voltas, mesmo quando acha cedo.
// 3. Para o dia 5, a sequencial ganha: o 5 está logo no começo. A binária só
//    vale a pena quando o vetor é grande ou o alvo está longe do início.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
