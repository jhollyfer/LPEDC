// 0163 · Skip list
// Exercício E973 · ★☆☆
//
// Escreva int maior(const Skip *s, int *avancos), que devolve a maior chave
// da skip list (que não pode estar vazia) e guarda em *avancos quantas vezes
// o ponteiro avançou. Não ande só pelo andar 0: use os andares de cima, como
// o ônibus direto. No main (as duas listas já estão montadas), teste com as
// paradas do texto e com 1000 códigos sorteados:
//
//   Saída esperada:
//   Paradas: maior 56, 2 avanços (pelo andar 0 seriam 8)
//   Códigos: maior 10000, 13 avanços (pelo andar 0 seriam 1000)
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "0163-skip.h"

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

    skip_libera(paradas);
    skip_libera(codigos);
    return 0;
}
