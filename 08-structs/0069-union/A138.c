// A138 · Um pagamento, três formas

#include <stdio.h>

typedef enum { PIX, CARTAO, BOLETO } TipoPagamento;

// union "etiquetada": o enum diz qual campo da union vale agora
typedef struct {
    TipoPagamento tipo;
    double valor;
    union {
        char chave[40];        // PIX
        struct {               // CARTAO
            char final[5];
            int parcelas;
        } cartao;
        char codigo[48];       // BOLETO
    } dados;
} Pagamento;

void mostrar(const Pagamento *p) {
    printf("R$ %7.2f via ", p->valor);
    switch (p->tipo) {
    case PIX:
        printf("Pix para %s\n", p->dados.chave);
        break;
    case CARTAO:
        printf("cartão final %s em %dx\n", p->dados.cartao.final, p->dados.cartao.parcelas);
        break;
    case BOLETO:
        printf("boleto %.10s...\n", p->dados.codigo);
        break;
    }
}

int main(void) {
    Pagamento lista[] = {
        {PIX, 89.90, .dados.chave = "loja@exemplo.com"},
        {CARTAO, 1250.00, .dados.cartao = {"4321", 10}},
        {BOLETO, 342.17, .dados.codigo = "23790123456789012345678901234567890123456789"},
    };

    for (int i = 0; i < 3; i++) {
        mostrar(&lista[i]);
    }
    printf("sizeof(Pagamento) = %zu (a union ocupa só o maior campo: 48)\n", sizeof(Pagamento));
    return 0;
}
// Saída:
// R$   89.90 via Pix para loja@exemplo.com
// R$ 1250.00 via cartão final 4321 em 10x
// R$  342.17 via boleto 2379012345...
// sizeof(Pagamento) = 64 (a union ocupa só o maior campo: 48)
