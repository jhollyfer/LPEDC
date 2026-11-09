// Lista · Módulo 12 · Pilhas e filas
// Exercício P1226 · ★★★ · A triagem do pronto-socorro
//
// No pronto-socorro, a fila não é por ordem de chegada: a classificação de
// risco manda (1 vermelho, 2 laranja, 3 amarelo, 4 verde, 5 azul). Entre
// pacientes da mesma cor, vale a ordem de chegada. Faça essa FILA DE
// PRIORIDADE com uma lista encadeada mantida em ordem:
//
//   void chega(Triagem *t, const char *nome, int cor)  // encaixa no lugar
//   bool atende(Triagem *t, char *nome, int *cor)      // tira o primeiro
//
// Faça: chegam Ana (4), Beto (3), Caio (1) e Duda (4); mostre a fila;
// atenda dois; chegam Edu (2), Fabi (5) e Gil (3); mostre a fila; atenda
// todos.
//
//   Saída esperada:
//   fila: Caio(vermelho) Beto(amarelo) Ana(verde) Duda(verde)
//   atende Caio (vermelho)
//   atende Beto (amarelo)
//   fila: Edu(laranja) Gil(amarelo) Ana(verde) Duda(verde) Fabi(azul)
//   atende Edu (laranja)
//   atende Gil (amarelo)
//   atende Ana (verde)
//   atende Duda (verde)
//   atende Fabi (azul)
//
// Dicas:
// 1. Para a ordem de chegada valer no empate, o novo entra DEPOIS de todos
//    os de cor menor OU IGUAL: ande enquanto p->prox->cor <= cor.
// 2. Atender é tirar do início: O(1). Chegar é O(n) (procura o lugar). Com
//    um heap (assunto 0102) as duas ficam O(log n).
// 3. Um vetor de nomes de cor, indexado por cor - 1, evita um switch.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct paciente {
    char nome[12];
    int cor; // 1 vermelho ... 5 azul
    struct paciente *prox;
} Paciente;

typedef struct {
    Paciente *inicio;
} Triagem;

int main(void) {

    return 0;
}
