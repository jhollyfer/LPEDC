// Lista · Módulo 14 · Árvores
// Exercício P1422 · ★★★ · A BST de volta a partir da pré-ordem
//
// Um sistema salva a BST do estoque gravando só a pré-ordem (é o jeito
// clássico: a pré-ordem de uma BST basta para remontá-la). Escreva
//
//   No *monta(const int pre[], int n, int *i, int min, int max)
//
// que remonta a árvore em O(n): se pre[*i] cabe no intervalo ABERTO
// (min, max), ele vira um nó, *i avança e os filhos são montados com
// (min, chave) à esquerda e (chave, max) à direita; senão, devolve NULL.
// Se, no fim, *i < n, a sequência não é pré-ordem de BST nenhuma.
//
// Escreva testa(nome, pre, n), que monta a partir de i = 0 com INT_MIN e
// INT_MAX, mostra a em ordem e a pós-ordem (ou o erro) e libera a árvore.
//
//   backup 1: 45 20 10 30 25 35 70 60 90
//   backup 2: 45 20 50 30 60
//   backup 3: 8 5 1 7 10 12
//
//   Saída esperada:
//   backup 1: ok
//     em:  10 20 25 30 35 45 60 70 90
//     pós: 10 25 35 30 20 60 90 70 45
//   backup 2: não é pré-ordem de BST (parou no 30, posição 3)
//   backup 3: ok
//     em:  1 5 7 8 10 12
//     pós: 1 7 5 12 10 8
//
// Dicas:
// 1. Inclua <limits.h> para INT_MIN e INT_MAX.
// 2. Cada elemento é olhado poucas vezes: quem não cabe num intervalo é
//    devolvido para o chamador, que tenta encaixá-lo mais acima.
// 3. No backup 2, o 50 já foi para a direita do 45; o 30 aparece depois e
//    não cabe em lugar nenhum (teria que estar à esquerda do 45).
// 4. Mesmo no erro, a árvore parcial precisa ser liberada.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct No {
    int chave;
    struct No *esq, *dir;
} No;

int main(void) {

    return 0;
}
