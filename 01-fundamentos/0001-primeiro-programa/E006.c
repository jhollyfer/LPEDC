// 0001 · O primeiro programa
// Exercício E006 · ★★★
//
// O letreiro do ônibus abaixo tem um erro para cada tipo de reclamação: um
// que o pré-processador pega, um do compilador, um do ligador e um que
// ninguém pega (o programa roda e mostra o valor errado: a tarifa certa é
// R$ 4,90). Conserte o código, um erro por vez. A cada rodada, repare qual
// estação parou a linha de montagem, e só pare quando a saída for
// exatamente a esperada.
//
//   Saída esperada (depois de consertar):
//   Linha 077 - Terminal Centro
//   Via Av. Brasil
//   Tarifa: R$ 4,90
//
// Dicas:
// 1. O pré-processador só cuida das linhas com #. O compilador para no
//    primeiro erro de gramática. O ligador procura funções pelo nome,
//    inclusive a main.
// 2. Depois que tudo compilar, compare a saída com a esperada, letra por
//    letra: o compilador não sabe qual é a tarifa certa.
// 3. Resposta esperada: (1) stdoi.h vira stdio.h ("No such file or
//    directory", pré-processador); (2) falta o ; depois do primeiro printf
//    ("expected ';'", compilador); (3) Main com M maiúsculo não é a main
//    ("undefined reference to `main'", ligador); (4) R$ 9,40 vira R$ 4,90
//    (erro de execução, de lógica). E as três linhas acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdoi.h>

int Main(void) {
    printf("Linha 077 - Terminal Centro\n")
    printf("Via Av. Brasil\n");
    printf("Tarifa: R$ 9,40\n");
    return 0;
}
