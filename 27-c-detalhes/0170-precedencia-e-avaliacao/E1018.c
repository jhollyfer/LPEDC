// 0170 · Precedência e ordem de avaliação
// Exercício E1018 · ★★☆
//
// Quatro amigos alugaram uma casa de praia por R$ 2400 para 3 dias. O
// programa abaixo compila sem nenhum aviso, mas as três contas estão
// erradas. Conserte cada uma:
//
//   - o custo por pessoa por dia é o total dividido por (pessoas x dias);
//   - cada um paga a sua parte do total mais R$ 50 de limpeza quando a
//     estadia passa de 2 dias;
//   - pagando à vista, o grupo ganha 10% de desconto sobre o total.
//
//   Saída esperada:
//   por pessoa por dia: R$ 200
//   cada um paga: R$ 650
//   desconto à vista: R$ 240
//
// Dicas:
// 1. Rode antes: sai 1800, 50 e 0. Para cada linha, escreva no papel a
//    árvore que o C montou.
// 2. O ?: fica abaixo do + e do >: ele engoliu a conta inteira.
// 3. 10 / 100 em inteiros é 0. Multiplique antes de dividir.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int total = 2400, pessoas = 4, dias = 3;

    int por_dia = total / pessoas * dias;
    printf("por pessoa por dia: R$ %d\n", por_dia);

    int cada_um = total / pessoas + dias > 2 ? 50 : 0;
    printf("cada um paga: R$ %d\n", cada_um);

    int desconto = 10 / 100 * total;
    printf("desconto à vista: R$ %d\n", desconto);
    return 0;
}
