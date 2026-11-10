// A125 · As formas de pagamento

#include <stdio.h>

// prefixo PAG_ evita choque de nomes; QTD_PAG conta quantas formas existem
typedef enum { PAG_PIX, PAG_DEBITO, PAG_CREDITO, PAG_DINHEIRO, QTD_PAG } Pagamento;

typedef struct {
    double valor;
    Pagamento forma; // um enum dentro de uma struct
} Venda;

int main(void) {
    // vetores do tamanho do enum, indexados pelo próprio enum
    const char *nomes[QTD_PAG] = {"Pix", "débito", "crédito", "dinheiro"};
    const double taxa[QTD_PAG] = {0.0, 1.5, 3.2, 0.0}; // % que a maquininha cobra

    Venda vendas[] = {
        {50.00, PAG_PIX},
        {120.00, PAG_CREDITO},
        {35.00, PAG_DEBITO},
        {80.00, PAG_PIX},
        {20.00, 7}, // compila! o C não confere se 7 é uma forma válida
    };
    int n = sizeof vendas / sizeof vendas[0];

    int contagem[QTD_PAG] = {0};
    double taxas = 0;
    for (int i = 0; i < n; i++) {
        Pagamento f = vendas[i].forma;
        if (f < 0 || f >= QTD_PAG) { // quem confere é você
            printf("venda %d: forma inválida (%d)\n", i, f);
            continue;
        }
        contagem[f]++;
        taxas += vendas[i].valor * taxa[f] / 100;
    }

    for (Pagamento f = PAG_PIX; f < QTD_PAG; f++) {
        printf("%s: %d venda(s)\n", nomes[f], contagem[f]);
    }
    printf("Taxas pagas: R$ %.2f\n", taxas);
    return 0;
}
// Saída:
// venda 4: forma inválida (7)
// Pix: 2 venda(s)
// débito: 1 venda(s)
// crédito: 1 venda(s)
// dinheiro: 0 venda(s)
// Taxas pagas: R$ 4.37
