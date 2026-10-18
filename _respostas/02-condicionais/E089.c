// 0015 · if/else e o = no lugar do ==
// Exercício E089 · ★★★
//
// Com "vagas = 0", o if guardava 0 nas vagas e ia sempre para o else; com
// "mensalista = 1", todo mundo virava mensalista. Com a constante à
// esquerda, "0 = vagas" não compila: o erro aparece na hora.

#include <stdio.h>

int main(void) {
    int vagas, mensalista;
    printf("Vagas livres e mensalista (1 = sim, 0 = não): ");
    if (scanf("%d %d", &vagas, &mensalista) != 2) {
        printf("Entrada inválida\n");
        return 1;
    }

    if (0 == vagas) {
        printf("Lotado.\n");
    } else {
        if (1 == mensalista) {
            printf("Bem-vindo, mensalista. Cancela aberta.\n");
        } else {
            printf("Retire o ticket. Cancela aberta.\n");
        }
    }
    printf("Vagas livres: %d\n", vagas);
    return 0;
}
