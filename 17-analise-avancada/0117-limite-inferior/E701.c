// 0117 · Limite inferior da ordenação
// Exercício E701 · ★★★
//
// Ache os bugs. A função podio() recebe os tempos (em segundos) de três
// corredores e escreve em r[] os tempos do mais rápido para o mais lento.
// Ela foi escrita como uma árvore de decisão "na mão": cada if é um nó, e
// cada folha monta uma ordem. O limite é 3 comparações no pior caso, e uma
// árvore bem feita para 3 elementos tem 6 folhas e altura 3.
//
// O main testa as 6 ordens possíveis e mostra:
//
//   Saída que aparece:
//   10 20 30 -> 10 20 30 (2 comparações) ok
//   10 30 20 -> 20 10 30 (3 comparações) ERRADO
//   20 10 30 -> 10 20 30 (3 comparações) ok
//   20 30 10 -> 10 20 30 (3 comparações) ok
//   30 10 20 -> 10 20 30 (4 comparações) ok
//   30 20 10 -> 10 20 30 (4 comparações) ok
//   pior caso: 4 comparações
//
// Há dois problemas: uma folha monta a ordem errada, e um ramo faz uma
// pergunta cuja resposta ele já sabe. Conserte os dois sem mudar a ideia
// da função:
//
//   Saída esperada:
//   10 20 30 -> 10 20 30 (2 comparações) ok
//   10 30 20 -> 10 20 30 (3 comparações) ok
//   20 10 30 -> 10 20 30 (2 comparações) ok
//   20 30 10 -> 10 20 30 (3 comparações) ok
//   30 10 20 -> 10 20 30 (3 comparações) ok
//   30 20 10 -> 10 20 30 (3 comparações) ok
//   pior caso: 3 comparações
//
// Dicas:
// 1. Para a folha errada: siga a entrada 10 30 20 pela árvore. Quais
//    respostas levam até a folha? O que elas dizem sobre x, y e z?
// 2. Para a pergunta repetida: no ramo do else de menor(x, y), o que você
//    já sabe sobre x e y? Alguma pergunta ali tem resposta garantida?
// 3. Resposta esperada: a saída esperada acima. A folha do "x < y, y > z,
//    x < z" é x z y; e, com tempos diferentes, o menor(y, x) dentro do
//    else é sempre verdadeiro: pode sair.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int comparacoes = 0;

int menor(int a, int b) {
    comparacoes++;
    return a < b;
}

void monta(int r[], int a, int b, int c) {
    r[0] = a;
    r[1] = b;
    r[2] = c;
}

void podio(int x, int y, int z, int r[]) {
    if (menor(x, y)) {
        if (menor(y, z)) {
            monta(r, x, y, z);
        } else if (menor(x, z)) {
            monta(r, z, x, y);
        } else {
            monta(r, z, x, y);
        }
    } else {
        if (menor(y, x) && menor(x, z)) {
            monta(r, y, x, z);
        } else if (menor(y, z)) {
            monta(r, y, z, x);
        } else {
            monta(r, z, y, x);
        }
    }
}

int main(void) {
    int ordens[6][3] = {{10, 20, 30}, {10, 30, 20}, {20, 10, 30}, {20, 30, 10}, {30, 10, 20}, {30, 20, 10}};
    int pior = 0;
    for (int k = 0; k < 6; k++) {
        int r[3];
        comparacoes = 0;
        podio(ordens[k][0], ordens[k][1], ordens[k][2], r);
        int certo = r[0] == 10 && r[1] == 20 && r[2] == 30;
        printf("%d %d %d -> %d %d %d (%d comparações) %s\n", ordens[k][0], ordens[k][1], ordens[k][2],
               r[0], r[1], r[2], comparacoes, certo ? "ok" : "ERRADO");
        if (comparacoes > pior) {
            pior = comparacoes;
        }
    }
    printf("pior caso: %d comparações\n", pior);
    return 0;
}
