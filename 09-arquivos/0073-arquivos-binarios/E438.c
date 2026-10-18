// 0073 · Arquivos binários
// Exercício E438 · ★★★
//
// O extrato do banco mostra os lançamentos mais recentes primeiro. Grave em
// /tmp/extrato.bin estes 6 lançamentos, nesta ordem (do mais antigo para o
// mais novo), como registros de struct { char descricao[24]; double valor; }:
//
//   Salário      +3500.00
//   Aluguel      -1200.00
//   Mercado       -387.60
//   Pix da Ana     +45.00
//   Farmácia       -62.30
//   Padaria        -18.90
//
// Depois, SEM carregar o arquivo inteiro na memória (um registro por vez),
// mostre os 3 últimos, do mais novo para o mais antigo, e o saldo de TODOS os
// lançamentos:
//
//   Últimos lançamentos:
//   Padaria           -18.90
//   Farmácia         -62.30
//   Pix da Ana        +45.00
//   Saldo: R$ 1876.20
//
// Dicas:
// 1. O registro k contado do fim (k = 1 é o último) começa em
//    -k * sizeof(registro) a partir de SEEK_END. Cuidado: sizeof é unsigned;
//    converta para long antes de pôr o sinal de menos.
// 2. Para o saldo, rewind(arq) e um while (fread(...) == 1) somando.
// 3. printf("%+.2f", x) mostra o sinal + nos positivos. Acentos ocupam mais de
//    um byte e bagunçam o alinhamento do %-15s; não se preocupe com isso.
// 4. Resposta esperada: Padaria, Farmácia, Pix da Ana, e Saldo: R$ 1876.20.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
