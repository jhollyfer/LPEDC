// 0123 · Quickselect
// Exercício E738 · ★★★
//
// O pivô sorteado deixa o pior caso improvável, mas não impossível. Em
// 1973, Blum, Floyd, Pratt, Rivest e Tarjan acharam um pivô que GARANTE
// O(n) no pior caso: a MEDIANA DAS MEDIANAS. Em cada volta do quickselect:
//
// 1. divida v[p..r] em grupos de 5 (o último pode ter menos), ordene cada
// grupo com o insertion sort (já está no arquivo) e leve a mediana de
// cada grupo para o começo do pedaço: v[p], v[p + 1], ...;
// 2. ache a mediana dessas medianas chamando a própria seleção
// (recursivamente) só no pedaço das medianas;
// 3. use essa mediana como pivô: troque com v[r] e chame o separa de
// sempre. O resto é o quickselect do texto.
//
// Escreva int seleciona(int v[], int p, int r, int k, bool mm), que faz o
// quickselect com pivô no fim (mm = false) ou com a mediana das medianas
// (mm = true), e compare as comparações num vetor em ordem e num
// embaralhado.
//
//   Saída esperada:
//   vetor em ordem:
//     pivô no fim:           mediana 5001,  37507500 comparações
//     mediana das medianas:  mediana 5001,     61140 comparações
//   vetor embaralhado:
//     pivô no fim:           mediana 5001,     28403 comparações
//     mediana das medianas:  mediana 5001,     39964 comparações
//
// Repare na última linha: a garantia tem preço. Em dados comuns, o pivô
// simples ganha.
//
// Dicas:
// 1. Grupo g vai de g até fim = min(g + 4, r); a mediana dele, depois de
//    ordenado, está em g + (fim - g) / 2. Troque-a com v[m] e faça m++,
//    começando com m = p.
// 2. As medianas ficam em v[p..m-1]; a do meio está na posição
//    meio = p + (m - p - 1) / 2. Chame seleciona(v, p, m - 1, meio, true):
//    ela deixa a mediana das medianas exatamente em v[meio].
// 3. Depois, troca(&v[meio], &v[r]) e segue igual ao quickselect, com k
//    sempre absoluto (posição no vetor inteiro).
// 4. Por que garante O(n)? A mediana das medianas é maior que uns 30% dos
//    elementos e menor que outros 30%: cada volta descarta pelo menos 30%.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (escreva seleciona):

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10001

static long comparacoes;

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int separa(int v[], int p, int r) {
    int pivo = v[r], j = p;
    for (int k = p; k < r; k++) {
        comparacoes++;
        if (v[k] <= pivo) {
            troca(&v[j], &v[k]);
            j++;
        }
    }
    troca(&v[j], &v[r]);
    return j;
}

// insertion sort em v[ini..fim], contando comparações
void insertion(int v[], int ini, int fim) {
    for (int i = ini + 1; i <= fim; i++) {
        int x = v[i];
        int j = i;
        while (j > ini) {
            comparacoes++;
            if (v[j - 1] <= x) {
                break;
            }
            v[j] = v[j - 1];
            j--;
        }
        v[j] = x;
    }
}

// devolve o valor da posição k (absoluta) de v[p..r]; com
// mediana_das_medianas = false, é o quickselect do texto (pivô no fim)
int seleciona(int v[], int p, int r, int k, bool mediana_das_medianas) {
    (void) mediana_das_medianas; // apague esta linha e escreva a função
    (void) p;
    (void) r;
    return v[k];
}

void testa(const char *nome, bool mm, int tipo) {
    int *v = malloc(N * sizeof(int));
    if (v == NULL) {
        return;
    }
    for (int i = 0; i < N; i++) {
        v[i] = tipo == 0 ? i + 1 : (i * 7919) % N + 1; // em ordem ou embaralhado
    }
    comparacoes = 0;
    int m = seleciona(v, 0, N - 1, N / 2, mm);
    printf("%s mediana %d, %9ld comparações\n", nome, m, comparacoes);
    free(v);
}

int main(void) {
    printf("vetor em ordem:\n");
    testa("  pivô no fim:          ", false, 0);
    testa("  mediana das medianas: ", true, 0);
    printf("vetor embaralhado:\n");
    testa("  pivô no fim:          ", false, 1);
    testa("  mediana das medianas: ", true, 1);
    return 0;
}
