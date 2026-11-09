// Lista · Módulo 25 · Estruturas especiais
// Exercício P2511 · ★★☆ · O estoque que não esquece o zero
//
// Ache o bug. A rede de farmácias guarda o estoque numa matriz esparsa
// filial × produto, uma lista por filial. Regra da matriz esparsa: zero
// NÃO se guarda. Mas quando um produto zera, a célula continua lá com 0, e
// zerar um produto que nem existia CRIA uma célula:
//
//   Saída que aparece:
//   filial 0: p4=10 p7=0
//   filial 1: p2=8 p5=0
//   filial 2: p4=0 p9=6
//   Células: 6
//
// Conserte a função define: com qtd 0, a célula que existe sai da lista (e
// é liberada) e a que não existe não é criada. O contador de células tem
// que acompanhar.
//
//   Saída esperada:
//   filial 0: p4=10
//   filial 1: p2=8
//   filial 2: p9=6
//   Células: 3
//
// Dicas:
// 1. Com Celula **p apontando para o ponteiro que leva à célula, tirar é
//    *p = velha->prox e depois free(velha).
// 2. São dois casos novos: "achou e qtd é 0" (remove) e "não achou e qtd é
//    0" (não faz nada).
// 3. Resposta esperada: 3 células: p4=10, p2=8 e p9=6.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

#define F 3

typedef struct Celula {
    int produto, qtd;
    struct Celula *prox;
} Celula;

Celula *linha[F];
int celulas = 0;

void define(int f, int produto, int qtd) {
    Celula **p = &linha[f];
    while (*p != NULL && (*p)->produto < produto) p = &(*p)->prox;
    if (*p != NULL && (*p)->produto == produto) {
        (*p)->qtd = qtd;
        return;
    }
    Celula *nova = malloc(sizeof(Celula));
    if (nova == NULL) exit(1);
    nova->produto = produto;
    nova->qtd = qtd;
    nova->prox = *p;
    *p = nova;
    celulas++;
}

int main(void) {
    define(0, 4, 10);
    define(0, 7, 3);
    define(1, 2, 8);
    define(2, 4, 1);
    define(2, 9, 6);
    define(0, 7, 0); // a filial 0 vendeu o último do produto 7
    define(2, 4, 0); // a filial 2 também zerou o produto 4
    define(1, 5, 0); // zera um que nem existia

    for (int f = 0; f < F; f++) {
        printf("filial %d:", f);
        for (Celula *c = linha[f]; c != NULL; c = c->prox) printf(" p%d=%d", c->produto, c->qtd);
        printf("\n");
    }
    printf("Células: %d\n", celulas);
    for (int f = 0; f < F; f++)
        while (linha[f] != NULL) {
            Celula *c = linha[f];
            linha[f] = c->prox;
            free(c);
        }
    return 0;
}
