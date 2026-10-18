// 0082 · Busca e remoção
// Exercício E490 · ★★☆
//
// Num leilão online, a cada rodada o MENOR lance sai da disputa. Os lances
// estão numa lista de structs com nome e valor. Escreva
//
//   bool remove_menor(Lance **inicio, Lance *saiu)
//
// que acha o nó de menor valor, copia os dados dele para *saiu, tira o nó
// da lista e devolve true (ou false se a lista estiver vazia). Rode duas
// rodadas.
//
//   Saída esperada:
//   Davi R$ 175 -> Carla R$ 210 -> Bruno R$ 90 -> Ana R$ 150 -> NULL
//   saiu Bruno (R$ 90)
//   Davi R$ 175 -> Carla R$ 210 -> Ana R$ 150 -> NULL
//   saiu Ana (R$ 150)
//   Davi R$ 175 -> Carla R$ 210 -> NULL
//
// Dicas:
// 1. Duas fases: primeiro ache o menor guardando o nó E o anterior dele
//    (menor e ant_menor); depois remova como no texto.
// 2. Para percorrer guardando o anterior, ande com ant e p, e quando
//    p->valor < menor->valor, faça menor = p e ant_menor = ant.
// 3. Copiar uma struct inteira é uma atribuição só: *saiu = *menor.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct lance {
    char nome[20];
    int valor;
    struct lance *prox;
} Lance;

Lance *lance_insere(Lance *inicio, const char *nome, int valor) {
    Lance *novo = malloc(sizeof(Lance));
    if (novo == NULL) exit(1);
    snprintf(novo->nome, sizeof novo->nome, "%s", nome);
    novo->valor = valor;
    novo->prox = inicio;
    return novo;
}

void lance_imprime(const Lance *inicio) {
    for (const Lance *p = inicio; p != NULL; p = p->prox) {
        printf("%s R$ %d -> ", p->nome, p->valor);
    }
    printf("NULL\n");
}

void lance_libera(Lance *inicio) {
    while (inicio != NULL) {
        Lance *seguinte = inicio->prox;
        free(inicio);
        inicio = seguinte;
    }
}

// escreva remove_menor aqui

int main(void) {
    Lance *leilao = NULL;
    leilao = lance_insere(leilao, "Ana", 150);
    leilao = lance_insere(leilao, "Bruno", 90);
    leilao = lance_insere(leilao, "Carla", 210);
    leilao = lance_insere(leilao, "Davi", 175);
    lance_imprime(leilao);

    // duas rodadas: chame remove_menor, mostre quem saiu e a lista

    lance_libera(leilao);
    return 0;
}
