// 0108 · Juntando tudo: o contador de palavras
// Exercício E644 · ★☆☆
//
// Um contador de palavras usa 4 baldes, encadeamento com inserção no início
// e a função hash "soma dos códigos % 4". O programa abaixo já tem o nó, a
// função hash e o main, que conta "ovo sal mel las sal" e mostra cada balde.
// Complete a função conta: ela procura a palavra na corrente do seu balde;
// se achar, soma 1; se não, cria um nó com uma CÓPIA da palavra e vezes = 1,
// no início da corrente.
//
//   Saída esperada:
//   [0] las:1 sal:2 ovo:1
//   [1]
//   [2] mel:1
//   [3]
//
// Dicas:
// 1. ovo = 340, sal = 320, mel = 318, las = 320: ovo, sal e las caem no 0.
// 2. Compare com strcmp; copie com snprintf(novo->palavra,
//    sizeof novo->palavra, "%s", w). O segundo "sal" não cria nó.
// 3. Resposta esperada: a saída acima. "las" e "sal" são anagramas e a soma
//    junta os dois no mesmo balde; o strcmp é que separa as contagens.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 4

typedef struct No {
    char palavra[8];
    int vezes;
    struct No *prox;
} No;

unsigned h(const char *s) {
    unsigned soma = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        soma += (unsigned char)s[i];
    }
    return soma % M;
}

void conta(No *baldes[], const char *w) {
    (void)baldes; // apague estas duas linhas
    (void)w;      // quando usar os parâmetros

    // complete aqui

}

int main(void) {
    No *baldes[M] = {NULL};
    const char *texto[] = {"ovo", "sal", "mel", "las", "sal"};
    for (int i = 0; i < 5; i++) {
        conta(baldes, texto[i]);
    }
    for (int b = 0; b < M; b++) {
        printf("[%d]", b);
        No *p = baldes[b];
        while (p != NULL) {
            printf(" %s:%d", p->palavra, p->vezes);
            No *prox = p->prox;
            free(p);
            p = prox;
        }
        printf("\n");
    }
    return 0;
}
