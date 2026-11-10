// 0116 · Análise amortizada
// Exercício E693 · ★★☆
//
// Muitas bibliotecas crescem o vetor por 1,5 em vez de 2: gastam menos
// memória sobrando. Mas continua O(1) amortizado? Estenda o programa:
//
// - o insere passa a receber o fator como fração (num, den): a nova
// capacidade é cap * num / den (3 e 2 para 1,5; 2 e 1 para 2);
// - a struct ganha os campos copias (long) e mudancas (int);
// - uma função testa(nome, num, den, n) cria um vetor com capacidade 1,
// insere n números, mostra mudanças, cópias, cópias por inserção e a
// sobra (cap - n) no fim, e libera tudo.
//
// Rode com n = 1000000:
//
//   Saída esperada:
//   fator  mudanças    cópias  cópias/n     sobra
//   x 1,5        34    2099753     2.10     49869
//   x 2          20    1048575     1.05     48576
//
// Cuidado: com cap = 1, a conta 1 * 3 / 2 dá 1 em divisão inteira. O
// vetor "cresce" para o mesmo tamanho, e a próxima escrita cai fora dele
// (o AddressSanitizer do rodar acusa heap-buffer-overflow). Garanta que a
// nova capacidade seja sempre maior que a antiga.
//
// Escreva sua resposta abaixo (mude o programa):

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int n, cap;
} Vetor;

void insere(Vetor *v, int valor) {
    if (v->n == v->cap) {
        int nova = v->cap * 2;
        int *maior = malloc(nova * sizeof *maior);
        if (maior == NULL) {
            exit(1);
        }
        for (int i = 0; i < v->n; i++) {
            maior[i] = v->dados[i];
        }
        free(v->dados);
        v->dados = maior;
        v->cap = nova;
    }
    v->dados[v->n++] = valor;
}

int main(void) {
    Vetor v = {malloc(sizeof(int)), 0, 1};
    if (v.dados == NULL) {
        return 1;
    }
    for (int i = 0; i < 1000000; i++) {
        insere(&v, i);
    }
    printf("n = %d, cap = %d\n", v.n, v.cap);
    free(v.dados);
    return 0;
}
