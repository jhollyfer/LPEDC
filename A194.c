// A194 · O organograma com dois ponteiros

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// "primeiro filho / próximo irmão": qualquer quantidade de filhos
// cabe em só dois ponteiros por nó
typedef struct No {
    char cargo[16];
    struct No *filho; // o primeiro filho
    struct No *irmao; // o próximo irmão (mesmo pai)
} No;

No *novo(const char *cargo) {
    No *n = malloc(sizeof(No));
    if (n == NULL) {
        exit(1);
    }
    strcpy(n->cargo, cargo);
    n->filho = NULL;
    n->irmao = NULL;
    return n;
}

// coloca o novo filho no fim da fila de irmãos
No *contrata(No *chefe, const char *cargo) {
    No *n = novo(cargo);
    if (chefe->filho == NULL) {
        chefe->filho = n;
    } else {
        No *p = chefe->filho;
        while (p->irmao != NULL) {
            p = p->irmao;
        }
        p->irmao = n;
    }
    return n;
}

// grau = quantos filhos o nó tem: anda pela fila de irmãos
int grau(const No *n) {
    int g = 0;
    for (const No *p = n->filho; p != NULL; p = p->irmao) {
        g++;
    }
    return g;
}

void mostra(const No *n, int nivel) {
    printf("%*s%s: grau %d\n", 2 * nivel, "", n->cargo, grau(n));
    for (const No *p = n->filho; p != NULL; p = p->irmao) {
        mostra(p, nivel + 1);
    }
}

void libera(No *n) {
    while (n != NULL) {
        No *prox = n->irmao; // guarda antes do free
        libera(n->filho);
        free(n);
        n = prox;
    }
}

int main(void) {
    No *dona = novo("dona");
    No *gerente = contrata(dona, "gerente");
    No *padeiro = contrata(dona, "padeiro");
    contrata(gerente, "caixa 1");
    contrata(gerente, "caixa 2");
    contrata(gerente, "entregador");
    contrata(padeiro, "ajudante");

    mostra(dona, 0);
    printf("Tamanho de um nó: %zu bytes\n", sizeof(No));

    libera(dona);
    return 0;
}
// Saída:
// dona: grau 2
//   gerente: grau 3
//     caixa 1: grau 0
//     caixa 2: grau 0
//     entregador: grau 0
//   padeiro: grau 1
//     ajudante: grau 0
// Tamanho de um nó: 32 bytes
