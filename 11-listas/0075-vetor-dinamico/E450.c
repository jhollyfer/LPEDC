// 0075 · Vetor dinâmico
// Exercício E450 · ★★★
//
// Um vetor que só cresce nunca devolve memória: se um dia guardou um milhão
// de itens e agora guarda três, continua ocupando um milhão. Complete as
// duas funções que tiram o último item e encolhem o vetor pela metade (sem
// nunca descer de capacidade 2), cada uma com uma regra:
//
//   vet_tira         encolhe quando o tamanho fica <= 1/4 da capacidade
//   vet_tira_metade  encolhe quando o tamanho fica <= 1/2 da capacidade
//
// Toda vez que um realloc der certo (crescendo ou encolhendo), some 1 em
// v->reallocs. O main já está pronto: ele esvazia um vetor de 9 itens com
// vet_tira e depois compara as duas regras num vetor com tam 4 e cap 4 que
// alterna "empurra, tira" 10 vezes.
//
//   Saída esperada:
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
//   alternando com 1/2: 20 realloc
//   alternando com 1/4: 1 realloc
//
// Dicas:
// 1. Depois de diminuir o tamanho, em vet_tira:
//    if (v->cap > 2 && v->tam <= v->cap / 4). Em vet_tira_metade, troque
//    o 4 por 2.
// 2. Use realloc para a nova capacidade, numa variável temporária. Se ele
//    falhar, tudo bem: o vetor só continua grande.
// 3. Resposta esperada: a saída acima. Encolhendo na metade, cada "empurra"
//    cresce para 8 e cada "tira" volta a 4: um realloc (que copia tudo) a
//    cada operação. Com 1/4, depois de crescer sobra folga para os dois
//    lados.
//
// Escreva sua resposta abaixo (complete vet_tira e vet_tira_metade):

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *itens;
    int tam;
    int cap;
    int reallocs; // quantos realloc deram certo
} Vet;

static bool vet_empurra(Vet *v, int valor) {
    if (v->tam == v->cap) {
        int *novo = realloc(v->itens, v->cap * 2 * sizeof(int));
        if (novo == NULL) return false;
        v->itens = novo;
        v->cap *= 2;
        v->reallocs++;
    }
    v->itens[v->tam++] = valor;
    return true;
}

// tira o último item e guarda em *saiu; falta encolher em 1/4
static bool vet_tira(Vet *v, int *saiu) {
    if (v->tam == 0) return false;
    v->tam--;
    *saiu = v->itens[v->tam];
    return true;
}

// tira o último item e guarda em *saiu; falta encolher em 1/2
static bool vet_tira_metade(Vet *v, int *saiu) {
    if (v->tam == 0) return false;
    v->tam--;
    *saiu = v->itens[v->tam];
    return true;
}

// cria um vetor com 1, 2, 3, 4 (tam 4, cap 4) e zera o contador
static bool vet_quatro(Vet *v) {
    v->itens = malloc(2 * sizeof(int));
    if (v->itens == NULL) return false;
    v->tam = 0;
    v->cap = 2;
    for (int i = 1; i <= 4; i++) vet_empurra(v, i);
    v->reallocs = 0;
    return true;
}

int main(void) {
    Vet v = {malloc(2 * sizeof(int)), 0, 2, 0};
    if (v.itens == NULL) return 1;

    for (int i = 1; i <= 9; i++) vet_empurra(&v, i);
    printf("empurrou 9: tam %d, cap %d\n", v.tam, v.cap);

    int x;
    while (vet_tira(&v, &x)) {
        printf("tirou %d: tam %d, cap %d\n", x, v.tam, v.cap);
    }
    free(v.itens);

    Vet metade, quarto;
    if (!vet_quatro(&metade)) return 1;
    if (!vet_quatro(&quarto)) {
        free(metade.itens);
        return 1;
    }
    for (int i = 0; i < 10; i++) {
        vet_empurra(&metade, 5);
        vet_tira_metade(&metade, &x);
        vet_empurra(&quarto, 5);
        vet_tira(&quarto, &x);
    }
    printf("alternando com 1/2: %d realloc\n", metade.reallocs);
    printf("alternando com 1/4: %d realloc\n", quarto.reallocs);

    free(metade.itens);
    free(quarto.itens);
    return 0;
}
