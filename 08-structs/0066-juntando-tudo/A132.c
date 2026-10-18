// A132 · A comanda e o pagamento

#include <stdio.h>

typedef struct {
    char nome[24];
    double preco;
} Item;

typedef struct {
    const Item *item; // aponta para o cardápio: não copia o item
    int qtd;
} Linha;

typedef enum { PIX, CARTAO, DINHEIRO } FormaPagamento;

typedef struct {
    FormaPagamento forma;
    union {
        char chave[40];   // PIX
        int parcelas;     // CARTAO
        double entregue;  // DINHEIRO: quanto o cliente deu
    } dados;
} Pagamento;

double total_comanda(const Linha linhas[], int n) {
    double total = 0;
    for (int i = 0; i < n; i++) {
        total += linhas[i].item->preco * linhas[i].qtd; // ponteiro dentro de struct
    }
    return total;
}

void pagar(const Pagamento *p, double total) {
    switch (p->forma) {
    case PIX:
        printf("Pix de R$ %.2f para %s\n", total, p->dados.chave);
        break;
    case CARTAO:
        printf("Cartão: %dx de R$ %.2f\n", p->dados.parcelas, total / p->dados.parcelas);
        break;
    case DINHEIRO:
        printf("Dinheiro: recebeu R$ %.2f, troco R$ %.2f\n", p->dados.entregue,
               p->dados.entregue - total);
        break;
    }
}

int main(void) {
    const Item cardapio[] = {{"X-Burger", 28.90}, {"Suco de caju", 9.00}, {"Pudim", 12.00}};

    Linha mesa7[] = {{&cardapio[0], 2}, {&cardapio[1], 2}, {&cardapio[2], 1}};
    int n = sizeof mesa7 / sizeof mesa7[0];

    double total = total_comanda(mesa7, n);
    for (int i = 0; i < n; i++) {
        printf("%d x %s\n", mesa7[i].qtd, mesa7[i].item->nome);
    }
    printf("Total: R$ %.2f\n", total);

    Pagamento formas[] = {
        {PIX, .dados.chave = "lanchonete@exemplo.com"},
        {CARTAO, .dados.parcelas = 3},
        {DINHEIRO, .dados.entregue = 100.00},
    };
    for (int i = 0; i < 3; i++) {
        pagar(&formas[i], total);
    }
    return 0;
}
// Saída:
// 2 x X-Burger
// 2 x Suco de caju
// 1 x Pudim
// Total: R$ 87.80
// Pix de R$ 87.80 para lanchonete@exemplo.com
// Cartão: 3x de R$ 29.27
// Dinheiro: recebeu R$ 100.00, troco R$ 12.20
