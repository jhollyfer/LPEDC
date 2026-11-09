// Lista · Módulo 14 · Árvores
// Exercício P1424 · ★★★ · O heap que escolhia o filho errado
//
// O RH paga os bônus do maior para o menor usando um heap de máximo: monta o
// heap e extrai a raiz até esvaziar. Os bônus (em reais) são 300, 1500, 800,
// 1200, 900, 400, 1100, 700. A função desce tem UM erro de propósito, numa
// linha só. O programa não quebra, mas a ordem de pagamento sai errada.
// Ache, conserte e rode até sair:
//
//   Saída esperada:
//   ordem de pagamento: 1500 1200 1100 900 800 700 400 300
//
// Dicas:
// 1. Antes do conserto, alguns valores saem fora de ordem. Faça o teste de
//    mesa de um desce em que os DOIS filhos são maiores que o pai.
// 2. O desce tem que trocar o pai com o MAIOR dos filhos. Quem o if
//    compara com o filho direito?
// 3. Resposta esperada: a linha certa é
//    if (f + 1 < n && v[f + 1] > v[f]) f++;
//    e a saída fica igual à de cima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void desce(int v[], int n, int i) {
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && v[f + 1] > v[i]) {
            f++;
        }
        if (v[i] >= v[f]) {
            break;
        }
        troca(&v[i], &v[f]);
        i = f;
    }
}

int main(void) {
    int bonus[] = {300, 1500, 800, 1200, 900, 400, 1100, 700};
    int n = 8;

    for (int i = n / 2 - 1; i >= 0; i--) {
        desce(bonus, n, i);
    }
    printf("ordem de pagamento:");
    while (n > 0) {
        printf(" %d", bonus[0]);
        bonus[0] = bonus[--n];
        desce(bonus, n, 0);
    }
    printf("\n");
    return 0;
}
