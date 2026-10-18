// 0086 · Juntando tudo
// Exercício E514 · ★★☆
//
// O bolão da Copa da firma mantém um ranking: mais pontos na frente e, em
// caso de empate, ordem alfabética. Escreva, com uma lista encadeada de
// structs (nome e pontos) neste arquivo:
//
//   insere no lugar certo do ranking (inserção ordenada)
//   remove um participante pelo nome
//   imprime com a posição
//
// Participantes, na ordem em que entraram: Ana 12, Beto 15, Cris 12,
// Duda 9, Edu 15. Depois a Cris sai do bolão.
//
//   Saída esperada:
//   1. Beto 15
//   2. Edu 15
//   3. Ana 12
//   4. Cris 12
//   5. Duda 9
//   Cris saiu do bolão
//   1. Beto 15
//   2. Edu 15
//   3. Ana 12
//   4. Duda 9
//
// Dicas:
// 1. Escreva uma função bool vem_antes(const Participante *a, const
//    Participante *b): mais pontos, ou pontos iguais e strcmp(a->nome,
//    b->nome) < 0. O laço da inserção anda enquanto vem_antes(p, novo).
// 2. A remoção é a do assunto 0082, comparando nomes com strcmp.
// 3. Copie o nome com snprintf, nunca com strcpy sem limite.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void) {

    return 0;
}
