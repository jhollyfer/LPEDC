// Lista · Módulo 12 · Pilhas e filas
// Exercício P1207 · ★☆☆ · A pilha de bandejas que transborda
//
// No balcão cabem 4 bandejas. A pilha abaixo guarda as bandejas num vetor
// alocado com malloc. Ela compila sem aviso, mas tem DOIS erros de
// propósito, e o sanitizer acusa "heap-buffer-overflow". Um erro deixa
// empilhar a 5ª bandeja (que não cabe); o outro faz desempilhar ler a
// posição errada. Conserte os dois para a saída ficar:
//
//   Saída esperada:
//   empilha 1: ok
//   empilha 2: ok
//   empilha 3: ok
//   empilha 4: ok
//   empilha 5: pilha cheia
//   desempilha: 4 3 2 1
//
// Dicas:
// 1. Com n itens, as posições ocupadas são 0 a n - 1. Quando a pilha está
//    cheia, quanto vale n? E qual é a última posição válida do vetor?
// 2. Onde está o topo: em v[n] ou em v[n - 1]? Decremente ANTES de ler.
// 3. Resposta esperada: o teste de cheia é n >= CAP (ou n == CAP), não
//    n > CAP; e desempilha faz *x = v[--n], não v[n--].
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define CAP 4

typedef struct {
    int *v;
    int n;
} Pilha;

bool empilha(Pilha *p, int x) {
    if (p->n > CAP) {
        return false;
    }
    p->v[p->n++] = x;
    return true;
}

bool desempilha(Pilha *p, int *x) {
    if (p->n == 0) {
        return false;
    }
    *x = p->v[p->n--];
    return true;
}

int main(void) {
    Pilha p = {malloc(CAP * sizeof(int)), 0};
    if (p.v == NULL) {
        return 1;
    }
    for (int b = 1; b <= 5; b++) {
        printf("empilha %d: %s\n", b, empilha(&p, b) ? "ok" : "pilha cheia");
    }
    printf("desempilha:");
    int x;
    while (desempilha(&p, &x)) {
        printf(" %d", x);
    }
    printf("\n");
    free(p.v);
    return 0;
}
