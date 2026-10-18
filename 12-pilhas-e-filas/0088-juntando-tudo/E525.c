// 0088 · Juntando tudo: a calculadora de expressões
// Exercício E525 · ★★☆
//
// Pergunta clássica de entrevista: faça uma FILA usando só duas PILHAS.
// Escreva um tipo FilaDuasPilhas com duas Pilha * (entrada e saida) e as
// funções fdp_insere e fdp_retira:
//
// - inserir: empilha na entrada;
// - retirar: se a saida estiver vazia, despeje a entrada inteira nela
// (isso inverte a ordem); depois desempilhe da saida.
//
// Teste: insira 1, 2 e 3, retire um, insira 4 e retire todos.
//
//   Saída esperada:
//   Saiu: 1
//   Depois: 2 3 4
//
// Dicas:
// 1. Só despeje quando a saida estiver VAZIA. Despejar com a saida ainda
//    cheia mistura a ordem.
// 2. Cada item é empilhado e desempilhado no máximo duas vezes, então,
//    na média, cada operação custa O(1) (custo amortizado), mesmo que um
//    despejo isolado custe O(n).
// 3. Resposta esperada: as duas linhas acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include "pilha.h"

int main(void) {

    return 0;
}
