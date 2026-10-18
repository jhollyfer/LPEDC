// 0062 · Erros de memória
// Exercício E372 · ★★★
//
// O artilheiro do bairro jogou 4 das 5 rodadas; a 5ª ainda não aconteceu e
// deveria contar 0 gols. Este programa tem um erro de propósito que o
// AddressSanitizer NÃO acusa. Faça assim:
//
// 1) rode com o rodar e veja o total;
// 2) rode com ~/LPEDC/rodar --valgrind e leia a primeira mensagem;
// 3) conserte com UMA palavra trocada.
//
//   Saída esperada depois do conserto:
//   Total: 6 gols
//   Média por rodada: 1.2
//
// Por que o ASan não pegou e o valgrind pegou?
//
// Dicas:
// 1. Quem deu valor para gols[4]?
// 2. O valgrind avisa "Conditional jump or move depends on uninitialised
//    value(s)" e, com a opção que o rodar já liga, mostra onde o bloco foi
//    criado.
// 3. Resposta esperada: gols[4] nunca recebeu valor e o malloc entrega lixo
//    (com o ASan, o lixo é sempre 0xbebebebe, um número negativo enorme).
//    O ASan vigia limites e blocos liberados, não valores; o valgrind
//    acompanha se cada byte já foi escrito. Conserto: trocar malloc(5 *
//    sizeof *gols) por calloc(5, sizeof *gols).
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int rodadas = 5;
    int *gols = malloc(rodadas * sizeof *gols);
    if (gols == NULL) {
        return 1;
    }
    gols[0] = 2;
    gols[1] = 0;
    gols[2] = 3;
    gols[3] = 1;

    int total = 0;
    for (int i = 0; i < rodadas; i++) {
        total += gols[i];
    }
    if (total >= 0) {
        printf("Total: %d gols\n", total);
        printf("Média por rodada: %.1f\n", (double)total / rodadas);
    } else {
        printf("Total negativo? Algo está muito errado: %d\n", total);
    }
    free(gols);
    return 0;
}
