// 0129 · Labirinto
// Exercício E773 · ★★★
//
// Ache o bug. Este é o balde de tinta de um editor de pixel art: balde(l, c,
// nova) troca pela cor nova toda a região da cor que está em (l, c). O
// primeiro clique funciona. O segundo, que pinta a mesma região com a MESMA
// cor que ela já tem, derruba o programa: o AddressSanitizer acusa
// stack-overflow. (Este erro é de propósito: rode, veja a falha, conserte e
// rode de novo.)
//
//   Saída esperada:
//   1º clique: 9 pixels
//   ..oo....
//   .oooo.##
//   ..oo..##
//   ..o.....
//   2º clique: 0 pixels
//   3º clique: 4 pixels
//   ..oo....
//   .oooo.++
//   ..oo..++
//   ..o.....
//
// Dicas:
// 1. Siga o 2º clique no papel: velha e nova são 'o'. A casa (1, 2) é
//    pintada de 'o'... e continua sendo da cor velha. O que acontece quando
//    o vizinho volta a ela?
// 2. No flood fill, pintar é o que marca a casa como visitada. Se a cor
//    nova é igual à velha, a marca não marca nada.
// 3. Resposta esperada: em balde, antes de começar, se velha == nova,
//    devolva 0 (não há nada a fazer). Consertado, a saída é a de cima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define L 4
#define C 8

char img[L][C + 1] = {
    "..##....",
    ".####.##",
    "..##..##",
    "..#.....",
};

int pinta(int l, int c, char velha, char nova) {
    if (l < 0 || l >= L || c < 0 || c >= C || img[l][c] != velha) {
        return 0;
    }
    img[l][c] = nova;
    return 1 + pinta(l, c + 1, velha, nova) + pinta(l + 1, c, velha, nova)
             + pinta(l, c - 1, velha, nova) + pinta(l - 1, c, velha, nova);
}

int balde(int l, int c, char nova) {
    char velha = img[l][c];
    return pinta(l, c, velha, nova);
}

void mostra(void) {
    for (int l = 0; l < L; l++) {
        printf("%s\n", img[l]);
    }
}

int main(void) {
    printf("1º clique: %d pixels\n", balde(1, 2, 'o'));
    mostra();
    printf("2º clique: %d pixels\n", balde(1, 2, 'o'));
    printf("3º clique: %d pixels\n", balde(1, 6, '+'));
    mostra();
    return 0;
}
