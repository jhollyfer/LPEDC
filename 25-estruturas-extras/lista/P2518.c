// Lista · Módulo 25 · Estruturas especiais
// Exercício P2518 · ★★☆ · A transposição que perde o contato
//
// Ache o bug. Esta agenda faz transposição religando os ponteiros:
// aa -> a -> x vira aa -> x -> a. Na segunda ligação para a Clínica ela
// some da lista, e o AddressSanitizer acusa vazamento de memória (memory
// leak) no fim, porque ninguém mais aponta para o nó dela:
//
//   Saída que aparece:
//   início: Avó Banco Clínica Dona Rosa
//   Clínica: Avó Clínica Banco Dona Rosa
//   Clínica: Avó Banco Dona Rosa
//   Dona Rosa: Avó Dona Rosa Banco
//
// Falta tratar um caso numa linha só. Conserte.
//
//   Saída esperada:
//   início: Avó Banco Clínica Dona Rosa
//   Clínica: Avó Clínica Banco Dona Rosa
//   Clínica: Clínica Avó Banco Dona Rosa
//   Dona Rosa: Clínica Avó Dona Rosa Banco
//
// Dicas:
// 1. Na segunda ligação, a Clínica é o segundo nó: a é a Avó e aa é NULL.
//    Quem deveria passar a apontar para a Clínica?
// 2. Quando o anterior do achado é o primeiro, o achado vira o primeiro:
//    é o ponteiro inicio que muda.
// 3. Resposta esperada: acrescente else inicio = x; a Clínica chega à
//    frente e a última linha fica Clínica Avó Dona Rosa Banco.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char nome[16];
    struct No *prox;
} No;

No *inicio = NULL;

void poe_no_fim(const char *nome) {
    No **p = &inicio;
    while (*p != NULL) p = &(*p)->prox;
    *p = malloc(sizeof(No));
    if (*p == NULL) exit(1);
    strcpy((*p)->nome, nome);
    (*p)->prox = NULL;
}

void liga(const char *nome) {
    No *aa = NULL, *a = NULL, *x = inicio;
    while (x != NULL && strcmp(x->nome, nome) != 0) {
        aa = a;
        a = x;
        x = x->prox;
    }
    if (x == NULL || a == NULL) return; // não achou, ou já é o primeiro
    a->prox = x->prox;
    x->prox = a;
    if (aa != NULL) aa->prox = x;
}

void mostra(const char *rotulo) {
    printf("%s:", rotulo);
    for (No *x = inicio; x != NULL; x = x->prox) printf(" %s", x->nome);
    printf("\n");
}

int main(void) {
    const char *contatos[] = {"Avó", "Banco", "Clínica", "Dona Rosa"};
    for (int k = 0; k < 4; k++) poe_no_fim(contatos[k]);
    mostra("início");
    liga("Clínica");
    mostra("Clínica");
    liga("Clínica");
    mostra("Clínica");
    liga("Dona Rosa");
    mostra("Dona Rosa");
    while (inicio != NULL) {
        No *x = inicio;
        inicio = x->prox;
        free(x);
    }
    return 0;
}
