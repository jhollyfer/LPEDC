// 0148 · Union-find
// Exercício E887 · ★★★
//
// Ache o bug. A escola forma grupos de estudo: quem estuda com quem fica no
// mesmo grupo. O programa abaixo tem um union-find escrito à mão, sem o TAD,
// com UM erro na união. Rode e compare: o contador diz 1 grupo, mas a
// conferência final (que conta as raízes de verdade) acha 2, e a Lia aparece
// fora do grupo da Ana, com quem ela estudou primeiro.
//
//   Saída esperada:
//   grupos (contador): 1
//   grupos (raízes):   1
//   Ana e Lia juntas? sim
//   Ana e Rui juntos? sim
//
// Conserte a função une e rode de novo.
//
// Dicas:
// 1. Desenhe as árvores (cada elemento com uma seta para o pai) depois de
//    cada união. Na última, a Lia já tem pai (a Ana): o que acontece com o
//    grupo antigo dela quando pai[a] é sobrescrito?
// 2. Quem representa o grupo é a raiz. Unir dois grupos é pendurar uma RAIZ
//    na outra, e não um elemento qualquer.
// 3. Resposta esperada: troque "pai[a] = b;" por "pai[acha(a)] = acha(b);"
//    (ou guarde as duas raízes em variáveis antes). Ligando o próprio a, ele
//    abandona o grupo em que estava e leva só os seus descendentes.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define N 6

int pai[N];
int grupos = N;

int acha(int x) {
    while (pai[x] != x) {
        x = pai[x];
    }
    return x;
}

void une(int a, int b) {
    if (acha(a) != acha(b)) {
        pai[a] = b;
        grupos--;
    }
}

int main(void) {
    const char *aluno[N] = {"Ana", "Bia", "Lia", "Rui", "Tom", "Vic"};
    for (int i = 0; i < N; i++) {
        pai[i] = i;
    }
    une(2, 0); // Lia estuda com Ana
    une(1, 0); // Bia estuda com Ana
    une(1, 2); // Bia e Lia (já estão juntas: nada muda)
    une(3, 4); // Rui estuda com Tom
    une(5, 4); // Vic estuda com Tom
    une(2, 5); // Lia estuda com Vic: os dois grupos viram um só

    int raizes = 0;
    for (int i = 0; i < N; i++) {
        raizes += pai[i] == i;
    }
    printf("grupos (contador): %d\n", grupos);
    printf("grupos (raízes):   %d\n", raizes);
    printf("%s e %s juntas? %s\n", aluno[0], aluno[2], acha(0) == acha(2) ? "sim" : "não");
    printf("%s e %s juntos? %s\n", aluno[0], aluno[3], acha(0) == acha(3) ? "sim" : "não");
    return 0;
}
