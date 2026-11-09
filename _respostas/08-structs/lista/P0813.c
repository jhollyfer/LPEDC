// Lista · Módulo 08 · Tipos compostos
// Exercício P0813 · ★★☆ · Pix, cartão ou dinheiro

#include <stdio.h>

typedef enum { PIX, CARTAO, DINHEIRO } Forma;

typedef struct {
    Forma forma;
    double valor;
    union {
        char chave[40];
        struct {
            char final[5];
            int parcelas;
        } cartao;
        double recebido;
    } dados;
} Pagamento;

void recibo(const Pagamento *p) {
    switch (p->forma) {
    case PIX:
        printf("PIX de R$ %.2f para %s\n", p->valor, p->dados.chave);
        break;
    case CARTAO:
        printf("Cartão final %s: R$ %.2f em %dx de R$ %.2f\n", p->dados.cartao.final,
               p->valor, p->dados.cartao.parcelas, p->valor / p->dados.cartao.parcelas);
        break;
    case DINHEIRO:
        printf("Dinheiro: R$ %.2f, recebido R$ %.2f, troco R$ %.2f\n", p->valor,
               p->dados.recebido, p->dados.recebido - p->valor);
        break;
    }
}

int main(void) {
    Pagamento pags[3] = {
        {.forma = PIX, .valor = 87.50, .dados.chave = "loja@exemplo.com.br"},
        {.forma = CARTAO, .valor = 359.70, .dados.cartao = {"4467", 3}},
        {.forma = DINHEIRO, .valor = 42.30, .dados.recebido = 50.00},
    };

    for (int i = 0; i < 3; i++) {
        recibo(&pags[i]);
    }
    printf("sizeof da union: %zu bytes; sizeof do Pagamento: %zu bytes\n",
           sizeof pags[0].dados, sizeof pags[0]);
    return 0;
}
