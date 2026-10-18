// 0116 · Análise amortizada
// Exercício E696 · ★★★
//
// Conserte o programa. O carrinho de compras do app guarda os itens num
// vetor que dobra quando enche e, para não desperdiçar memória, encolhe
// pela metade quando fica com metade das posições ocupadas. Parece justo,
// mas olhe o que acontece quando o cliente põe e tira o mesmo item várias
// vezes com o carrinho cheio:
//
//   Saída que aparece:
//   16 inserções: 15 cópias (cap 16)
//   1000 operações alternadas: 16000 cópias (cap 16)
//   esvaziar: 15 cópias (cap 1)
//
// Cada operação da fase do meio copia 16 elementos. Mude SÓ a regra de
// encolher, para que o vetor encolha pela metade apenas quando ficar com
// UM QUARTO da capacidade ocupada:
//
//   Saída esperada:
//   16 inserções: 15 cópias (cap 16)
//   1000 operações alternadas: 16 cópias (cap 32)
//   esvaziar: 15 cópias (cap 1)
//
// Dicas:
// 1. Siga à mão: com n = 16 e cap = 16, insere dobra para 32 (16 cópias);
//    remove deixa n = 16 = 32 / 2 e encolhe para 16 (16 cópias). E de novo.
// 2. A operação cara precisa de "folga" dos dois lados. Depois de encolher
//    de cap para cap/2 com n = cap/4, o vetor fica meio cheio: faltam cap/4
//    inserções para dobrar e cap/8 remoções para encolher de novo.
// 3. Resposta esperada: a saída esperada acima. A condição vira
//    v->n == v->cap / 4.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int n, cap;
    long copias;
} Vetor;

// troca o vetor por um de capacidade nova, copiando os n elementos
void muda(Vetor *v, int nova) {
    int *outro = malloc(nova * sizeof *outro);
    if (outro == NULL) {
        exit(1);
    }
    for (int i = 0; i < v->n; i++) {
        outro[i] = v->dados[i];
        v->copias++;
    }
    free(v->dados);
    v->dados = outro;
    v->cap = nova;
}

void insere(Vetor *v, int x) {
    if (v->n == v->cap) {
        muda(v, 2 * v->cap);
    }
    v->dados[v->n++] = x;
}

int remove_ultimo(Vetor *v) {
    int x = v->dados[--v->n];
    if (v->cap > 1 && v->n == v->cap / 2) {
        muda(v, v->cap / 2);              // ficou com metade: encolhe
    }
    return x;
}

int main(void) {
    Vetor v = {malloc(sizeof(int)), 0, 1, 0};
    if (v.dados == NULL) {
        return 1;
    }
    for (int i = 0; i < 16; i++) {
        insere(&v, i);
    }
    printf("16 inserções: %ld cópias (cap %d)\n", v.copias, v.cap);

    v.copias = 0;
    for (int i = 0; i < 500; i++) {       // põe e tira o mesmo item
        insere(&v, 99);
        remove_ultimo(&v);
    }
    printf("1000 operações alternadas: %ld cópias (cap %d)\n", v.copias, v.cap);

    v.copias = 0;
    while (v.n > 0) {
        remove_ultimo(&v);
    }
    printf("esvaziar: %ld cópias (cap %d)\n", v.copias, v.cap);
    free(v.dados);
    return 0;
}
