// Lista · Módulo 11 · Listas
// Exercício P1116 · ★★☆ · A agenda do consultório em vetor ordenado
//
// Os horários marcados do dia ficam numa lista sequencial ORDENADA (em
// minutos desde a meia-noite, num vetor de 10). Escreva:
//
//   int ord_busca(const Agenda *a, int x, int *pos)
//     busca binária: devolve 1 se achou (e *pos é onde está) ou 0 (e *pos é
//     onde x deveria entrar para manter a ordem);
//   bool ord_insere(Agenda *a, int x)   // recusa repetido e agenda cheia
//   bool ord_remove(Agenda *a, int x)
//
// As duas últimas usam ord_busca para achar a posição e depois deslocam os
// itens do vetor. Insira 540, 600, 480, 720 e 600 (repetido), remova o 540
// e procure o 720. Mostre os horários como hh:mm.
//
//   Saída esperada:
//   Agenda: 08:00 09:00 10:00 12:00
//   10:00: horário ocupado
//   Sem 09:00: 08:00 10:00 12:00
//   12:00 está na posição 2
//
// Dicas:
// 1. Na busca binária, quando o laço termina sem achar, ini é exatamente a
//    posição de inserção: todos antes dela são menores que x.
// 2. Inserir na posição p: desloque v[p..n-1] uma casa para a direita (do
//    fim para o começo). Remover: desloque v[p+1..n-1] uma casa para a
//    esquerda (do começo para o fim).
// 3. Buscar é O(log n), mas inserir e remover continuam O(n) por causa do
//    deslocamento. Essa é a troca da lista sequencial ordenada.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define CAP 10

typedef struct {
    int v[CAP];
    int n;
} Agenda;

int main(void) {

    return 0;
}
