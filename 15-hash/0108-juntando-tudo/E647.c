// 0108 · Juntando tudo: o contador de palavras
// Exercício E647 · ★★★
//
// Este contador lê as palavras de uma frase, uma por vez, no mesmo vetor
// "atual", e conta numa tabela com encadeamento. Ele compila sem aviso e o
// AddressSanitizer fica quieto, mas o resultado está errado. O erro está aí
// de propósito. Para a frase "sol e mar e sol e pera e lua" a saída
// deveria ter (em alguma ordem):
//
//   e: 4
//   lua: 1
//   mar: 1
//   pera: 1
//   sol: 2
//
// a) Rode e anote o que sai. Por que todas as palavras aparecem iguais?
// b) Por que "pera" sumiu e alguém ficou com uma contagem a mais?
// c) Conserte.
//
// Dicas:
// 1. Olhe o campo palavra do nó: ele guarda as letras ou um endereço?
// 2. Depois de "novo->palavra = atual", para onde aponta cada nó quando a
//    próxima palavra é lida em "atual"?
// 3. Resposta esperada: a) todos os nós apontam para o mesmo vetor
//    "atual", que no fim contém "lua"; cada nó mostra o que está lá agora.
//    b) "pera" cai no mesmo balde de "sol" (4). Na busca, o strcmp compara
//    "atual" com ele mesmo (o nó do sol aponta para "atual") e dá igual: o
//    sol ganha 1 e a pera nunca vira nó. c) o nó precisa da sua cópia:
//    "char palavra[16];" e snprintf(novo->palavra, sizeof novo->palavra,
//    "%s", atual). Consertado: mar: 1, e: 4, lua: 1, pera: 1 e sol: 2,
//    nessa ordem (a dos baldes).
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 5

typedef struct No {
    const char *palavra;
    int vezes;
    struct No *prox;
} No;

unsigned espalha(const char *s) {
    unsigned h = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        h = h * 31 + (unsigned char)s[i];
    }
    return h % M;
}

void conta(No *baldes[], const char *atual) {
    unsigned b = espalha(atual);
    for (No *p = baldes[b]; p != NULL; p = p->prox) {
        if (strcmp(p->palavra, atual) == 0) {
            p->vezes++;
            return;
        }
    }
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        return;
    }
    novo->palavra = atual;
    novo->vezes = 1;
    novo->prox = baldes[b];
    baldes[b] = novo;
}

int main(void) {
    const char *frase = "sol e mar e sol e pera e lua";
    No *baldes[M] = {NULL};
    char atual[16]; // reaproveitado a cada palavra
    const char *p = frase;

    while (*p != '\0') {
        int n = 0;
        while (*p != '\0' && *p != ' ') { // copia até o espaço
            if (n < 15) {
                atual[n++] = *p;
            }
            p++;
        }
        atual[n] = '\0';
        if (n > 0) {
            conta(baldes, atual);
        }
        while (*p == ' ') {
            p++;
        }
    }
    for (int b = 0; b < M; b++) {
        No *q = baldes[b];
        while (q != NULL) {
            printf("%s: %d\n", q->palavra, q->vezes);
            No *prox = q->prox;
            free(q);
            q = prox;
        }
    }
    return 0;
}
