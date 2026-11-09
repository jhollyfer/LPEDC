// Lista · Módulo 14 · Árvores
// Exercício P1416 · ★★☆ · A fila de prioridade da impressora
//
// A impressora do escritório atende por prioridade (1 é a mais urgente) e,
// no empate, por ordem de chegada. Escreva um heap de MÍNIMO de structs:
//
//   typedef struct { char dono[10]; int prioridade; int chegada; } Trabalho;
//
//   int antes(const Trabalho *a, const Trabalho *b)   a sai antes de b?
//   void insere(Trabalho h[], int *n, Trabalho t)    sobe
//   Trabalho extrai(Trabalho h[], int *n)            desce
//
// Chegam, nesta ordem (chegada de 1 a 6): Caixa 3, Gerente 1, RH 2, Vendas 3,
// Diretor 1, Estoque 2. Insira todos e depois extraia até esvaziar.
//
//   Saída esperada:
//   ordem de impressão:
//     Gerente  prioridade 1, chegou em 2
//     Diretor  prioridade 1, chegou em 5
//     RH       prioridade 2, chegou em 3
//     Estoque  prioridade 2, chegou em 6
//     Caixa    prioridade 3, chegou em 1
//     Vendas   prioridade 3, chegou em 4
//
// Dicas:
// 1. Toda comparação do heap passa por antes(): é ela que define o que é
//    "menor". Com chave composta, o heap não precisa mudar.
// 2. O heap NÃO é estável. Sem o campo chegada no desempate, Gerente e
//    Diretor poderiam sair em qualquer ordem.
// 3. Use printf("  %-8s prioridade %d, chegou em %d\n", ...).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

typedef struct {
    char dono[10];
    int prioridade;
    int chegada;
} Trabalho;

int main(void) {

    return 0;
}
