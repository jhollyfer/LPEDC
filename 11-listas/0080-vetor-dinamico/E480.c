// 0080 · Vetor dinâmico
// Exercício E480 · ★★★
//
// Um vetor que só cresce nunca devolve memória: se um dia guardou um milhão
// de itens e agora guarda três, continua ocupando um milhão. Complete
// vet_tira para que, depois de tirar o último item, o vetor ENCOLHA PELA
// METADE quando o tamanho ficar menor ou igual a 1/4 da capacidade (sem
// nunca descer de capacidade 2).
//
//   Saída esperada (o main já está pronto):
//   empurrou 9: tam 9, cap 16
//   tirou 9: tam 8, cap 16
//   tirou 8: tam 7, cap 16
//   tirou 7: tam 6, cap 16
//   tirou 6: tam 5, cap 16
//   tirou 5: tam 4, cap 8
//   tirou 4: tam 3, cap 8
//   tirou 3: tam 2, cap 4
//   tirou 2: tam 1, cap 2
//   tirou 1: tam 0, cap 2
//
// Por fim responda: por que encolher em 1/4 e não assim que chegar na
// metade? Pense num vetor com tam 4 e cap 4 que alterna "empurra, tira,
// empurra, tira..." para sempre.
//
// Dicas:
// 1. Depois de diminuir o tamanho: if (v->cap > 2 && v->tam <= v->cap / 4).
// 2. Use realloc para a nova capacidade, numa variável temporária. Se ele
//    falhar, tudo bem: o vetor só continua grande.
// 3. Resposta esperada: a saída acima. Encolhendo na metade, a alternância
//    faria um realloc a CADA operação (empurra cresce para 8, tira volta a
//    tam 4 e encolhe para 4, empurra cresce para 8...), e cada um copia tudo.
//    Com 1/4, depois de encolher sobra folga para os dois lados.
//
// Escreva sua resposta abaixo (complete vet_tira):

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *itens;
    int tam;
    int cap;
} Vet;

static bool vet_empurra(Vet *v, int valor) {
    if (v->tam == v->cap) {
        int *novo = realloc(v->itens, v->cap * 2 * sizeof(int));
        if (novo == NULL) return false;
        v->itens = novo;
        v->cap *= 2;
    }
    v->itens[v->tam++] = valor;
    return true;
}

// tira o último item e guarda em *saiu; falta encolher
static bool vet_tira(Vet *v, int *saiu) {
    if (v->tam == 0) return false;
    v->tam--;
    *saiu = v->itens[v->tam];
    return true;
}

int main(void) {
    Vet v = {malloc(2 * sizeof(int)), 0, 2};
    if (v.itens == NULL) return 1;

    for (int i = 1; i <= 9; i++) vet_empurra(&v, i);
    printf("empurrou 9: tam %d, cap %d\n", v.tam, v.cap);

    int x;
    while (vet_tira(&v, &x)) {
        printf("tirou %d: tam %d, cap %d\n", x, v.tam, v.cap);
    }

    free(v.itens);
    return 0;
}
