// 0163 · Skip list
// Exercício E973 · ★☆☆
//
// Complete maior(s, &avancos), que devolve a maior chave da skip list
// (que não pode estar vazia) e conta quantas vezes o ponteiro avançou. Não
// ande só pelo andar 0: use os andares de cima, como o ônibus direto.
// O main testa com as paradas do texto e com 1000 códigos sorteados.
//
//   Saída esperada:
//   Paradas: maior 56, 2 avanços (pelo andar 0 seriam 8)
//   Códigos: maior 10000, 13 avanços (pelo andar 0 seriam 1000)
//
// Dicas:
// 1. É a busca sem a comparação: comece em x = &s->cabeca, no andar
//    s->andares - 1. Em cada andar, avance enquanto x->prox[k] != NULL.
//    Depois desça.
// 2. Some 1 em *avancos a cada x = x->prox[k]. No fim, x é o último nó.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete maior):

#include <stdio.h>
#include "skip.h"

int maior(const Skip *s, int *avancos) {
    (void)s; // apague estas duas linhas
    *avancos = 0;
    return 0;
}

int main(void) {
    int km[] = {5, 12, 18, 23, 31, 40, 47, 56};
    int andares[] = {1, 2, 1, 3, 1, 2, 1, 3};
    Skip *paradas = skip_cria(0);
    for (int i = 0; i < 8; i++) {
        skip_insere_andares(paradas, km[i], andares[i]);
    }
    Skip *codigos = skip_cria(2024);
    for (int i = 1; i <= 1000; i++) {
        skip_insere(codigos, i * 10);
    }

    int av;
    int m = maior(paradas, &av);
    printf("Paradas: maior %d, %d avanços (pelo andar 0 seriam %d)\n", m, av, paradas->n);
    m = maior(codigos, &av);
    printf("Códigos: maior %d, %d avanços (pelo andar 0 seriam %d)\n", m, av, codigos->n);

    skip_libera(paradas);
    skip_libera(codigos);
    return 0;
}
