// Lista · Módulo 12 · Pilhas e filas
// Exercício P1220 · ★★☆ · Um painel para dois guichês
//
// Dois guichês do Detran emitem senhas com o horário de chegada (em minutos
// depois das 8h), e cada guichê tem a sua fila, já em ordem de chegada. O
// painel novo chama todo mundo numa fila ÚNICA, também por ordem de
// chegada. Escreva uma fila encadeada de int (entra, sai, frente, vazia) e
//
//   void junta(Fila *a, Fila *b, Fila *painel)
//
// que move todos os itens de a e b para o painel, sempre o de menor horário
// primeiro (no empate, o de a), usando SÓ essas quatro operações.
//
//   Saída esperada:
//   guichê A: 5 12 20
//   guichê B: 7 8 25 30
//   painel: 5 7 8 12 20 25 30
//   A e B vazias: sim
//
// Dicas:
// 1. frente(f) devolve o primeiro sem tirar. Enquanto as duas tiverem
//    gente, compare as frentes e mova a menor. Quando uma esvaziar, mova o
//    resto da outra.
// 2. É a intercalação de listas ordenadas, mas só com as operações da fila:
//    você não enxerga os nós. Custa O(n + m).
// 3. Para mostrar uma fila sem perdê-la, tire e reponha cada item.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

typedef struct {
    No *inicio, *fim;
    int n;
} Fila;

int main(void) {

    return 0;
}
