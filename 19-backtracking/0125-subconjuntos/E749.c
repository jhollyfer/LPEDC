// 0125 · Subconjuntos
// Exercício E749 · ★★★
//
// Ache o bug. A pizzaria cobra à parte quatro adicionais: bacon (R$ 6),
// cheddar (R$ 4), catupiry (R$ 5) e cebola (R$ 2). O programa abaixo devia
// listar todas as combinações de adicionais que custam no máximo R$ 10 e
// contá-las. Ele compila sem aviso e roda, mas a lista sai errada: aparecem
// as 16 combinações, quase todas de graça. Ache a linha com erro, conserte e
// rode de novo.
//
//   Saída esperada:
//   R$ 0: nenhum
//   R$ 6: bacon
//   R$ 4: cheddar
//   R$ 10: bacon cheddar
//   R$ 5: catupiry
//   R$ 9: cheddar catupiry
//   R$ 2: cebola
//   R$ 8: bacon cebola
//   R$ 6: cheddar cebola
//   R$ 7: catupiry cebola
//   10 combinações até R$ 10
//
// Dicas:
// 1. Acrescente um printf que mostre m & (1 << i) para m = 6. Quais valores
//    aparecem quando o bit está ligado?
// 2. O resultado de m & (1 << i) é 0 ou o próprio 1 << i (1, 2, 4 ou 8).
//    Ele só vale 1 para o bit 0.
// 3. Resposta esperada: o teste certo é if (m & (1 << i)), sem o == 1. Com
//    ele consertado, a saída é a de cima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define N 4

int main(void) {
    const char *nomes[N] = {"bacon", "cheddar", "catupiry", "cebola"};
    const int precos[N] = {6, 4, 5, 2};
    int conta = 0;

    for (int m = 0; m < (1 << N); m++) {
        int total = 0;
        for (int i = 0; i < N; i++) {
            if ((m & (1 << i)) == 1) {
                total += precos[i];
            }
        }
        if (total > 10) {
            continue;
        }
        conta++;
        printf("R$ %d:", total);
        if (m == 0) {
            printf(" nenhum");
        }
        for (int i = 0; i < N; i++) {
            if ((m & (1 << i)) == 1) {
                printf(" %s", nomes[i]);
            }
        }
        printf("\n");
    }
    printf("%d combinações até R$ 10\n", conta);
    return 0;
}
