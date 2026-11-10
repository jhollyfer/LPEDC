// Lista · Módulo 08 · Tipos compostos
// Exercício P0813 · ★★☆ · Pix, cartão ou dinheiro
//
// O caixa da loja aceita três formas de pagamento, e cada uma tem dados
// diferentes. Represente com uma union etiquetada:
//
//   typedef enum { PIX, CARTAO, DINHEIRO } Forma;
//   typedef struct {
//       Forma forma;   // a etiqueta: diz qual campo da union vale
//       double valor;
//       union {
//           char chave[40];                              // PIX
//           struct { char final[5]; int parcelas; } cartao; // CARTAO
//           double recebido;                             // DINHEIRO
//       } dados;
//   } Pagamento;
//
// Escreva void recibo(const Pagamento *p), que usa um switch na etiqueta e
// mostra o que vale para aquela forma (no dinheiro, o troco; no cartão, o
// valor de cada parcela). Mostre os recibos dos três pagamentos abaixo e o
// sizeof da union e do Pagamento:
//
//   Saída esperada:
//   PIX de R$ 87.50 para loja@exemplo.com.br
//   Cartão final 4467: R$ 359.70 em 3x de R$ 119.90
//   Dinheiro: R$ 42.30, recebido R$ 50.00, troco R$ 7.70
//   sizeof da union: 40 bytes; sizeof do Pagamento: 56 bytes
//
// Dicas:
// 1. Inicialize com campos nomeados: {.forma = CARTAO, .valor = 359.70,
//    .dados.cartao = {"4467", 3}}.
// 2. Num Pagamento, só UM campo da union guarda dado de verdade. Ler outro
//    (dados.recebido de um PIX) mostra os bytes da chave lidos como double:
//    lixo. Por isso a etiqueta.
// 3. O tamanho da union é o do maior campo (a chave, 40 bytes).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

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

int main(void) {
    Pagamento pags[3] = {
        {.forma = PIX, .valor = 87.50, .dados.chave = "loja@exemplo.com.br"},
        {.forma = CARTAO, .valor = 359.70, .dados.cartao = {"4467", 3}},
        {.forma = DINHEIRO, .valor = 42.30, .dados.recebido = 50.00},
    };
    (void) pags; // apague esta linha quando escrever

    return 0;
}
