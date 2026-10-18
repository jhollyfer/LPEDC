// 0078 · Lista ordenada
// Exercício E464 · ★☆☆
//
// Teste de mesa feito pelo próprio programa. A função insere_rastreando
// abaixo é a inserção ordenada do texto. Acrescente, logo depois do while,
// uma linha que mostre o valor inserido e onde ant e p pararam (use a
// função mostra_no, que já está pronta e escreve NULL quando o ponteiro é
// NULL). O main insere 25, 10, 40, 10 e 30 e mostra a lista a cada passo.
//
//   Saída esperada:
//   25: ant NULL, p NULL
//   25 -> NULL
//   10: ant NULL, p 25
//   10 -> 25 -> NULL
//   40: ant 25, p NULL
//   10 -> 25 -> 40 -> NULL
//   10: ant NULL, p 10
//   10 -> 10 -> 25 -> 40 -> NULL
//   30: ant 25, p 40
//   10 -> 10 -> 25 -> 30 -> 40 -> NULL
//
// Por fim, troque "p->valor < valor" por "p->valor <= valor" e rode de novo:
// a linha do segundo 10 tem que virar "10: ant 10, p 25" (o novo 10 entra
// DEPOIS do primeiro, não antes). Deixe a versão com < no arquivo final.
//
// Dicas:
// 1. printf("%d: ", valor); mostra_no("ant", ant); printf(", ");
//    mostra_no("p", p); printf("\n");
// 2. ant == NULL quer dizer "o novo vira o início"; p == NULL quer dizer
//    "o novo vai para o fim".
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete insere_rastreando):

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// escreve "ant 25" ou "ant NULL"
void mostra_no(const char *nome, const No *n) {
    if (n == NULL) {
        printf("%s NULL", nome);
    } else {
        printf("%s %d", nome, n->valor);
    }
}

static No *insere_rastreando(No *inicio, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) exit(1);
    novo->valor = valor;
    No *ant = NULL;
    No *p = inicio;
    while (p != NULL && p->valor < valor) {
        ant = p;
        p = p->prox;
    }
    // acrescente aqui: mostre onde ant e p pararam

    novo->prox = p;
    if (ant == NULL) return novo;
    ant->prox = novo;
    return inicio;
}

int main(void) {
    int valores[] = {25, 10, 40, 10, 30};
    No *l = NULL;
    for (int i = 0; i < 5; i++) {
        l = insere_rastreando(l, valores[i]);
        lista_imprime(l);
    }
    lista_libera(l);
    return 0;
}
