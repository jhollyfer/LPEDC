// Lista · Módulo 11 · Listas
// Exercício P1114 · ★★☆ · Os contatos que vêm para a frente
//
// A agenda do celular é uma lista dupla (com início e fim) com Ana, Bia,
// Caio, Duda e Edu. Quem você procura muito deveria ficar no começo. A
// heurística "mover para a frente": a cada busca bem-sucedida, o nó achado
// sai de onde está e vai para o início. Escreva
//
//   int busca_move(Agenda *ag, const char *nome)
//
// que faz a busca sequencial, move o nó para a frente (se achou) e devolve
// quantas comparações fez. Faça as buscas Duda, Duda, Edu, Duda e Ana,
// mostrando a agenda depois de cada uma, e compare o total com o que a
// mesma sequência custaria sem mover ninguém.
//
//   Saída esperada:
//   Duda: 4 comparações | Duda Ana Bia Caio Edu
//   Duda: 1 comparações | Duda Ana Bia Caio Edu
//   Edu: 5 comparações | Edu Duda Ana Bia Caio
//   Duda: 2 comparações | Duda Edu Ana Bia Caio
//   Ana: 3 comparações | Ana Duda Edu Bia Caio
//   Total movendo: 15
//   Total sem mover: 18
//
// Dicas:
// 1. Para tirar o nó p do lugar: se p->ant existe, p->ant->prox = p->prox;
//    se p->prox existe, p->prox->ant = p->ant; se p era o fim, o fim vira
//    p->ant. Depois ponha p no início (p->ant = NULL, p->prox = início...).
// 2. Se p já é o início, não mexa em nada.
// 3. Sem mover, cada busca custa a posição original + 1: 4 + 4 + 5 + 4 + 1.
//    Para calcular isso, use um vetor com os nomes na ordem original.
// 4. Resposta esperada: a saída acima. É a ideia por trás de caches como o
//    LRU: o que foi usado há pouco tende a ser usado de novo.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contato {
    char nome[16];
    struct contato *ant, *prox;
} Contato;

typedef struct {
    Contato *inicio, *fim;
} Agenda;

int main(void) {

    return 0;
}
