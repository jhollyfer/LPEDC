// A149 · Quantas vezes o vetor mudou de casa

#include <stdio.h>
#include "lista.h"

int main(void) {
    // capacidade 0 não existe: lista_cria corrige para 1
    Lista *passos = lista_cria(0);
    if (passos == NULL) return 1;
    printf("criou: tam %d, cap %d\n", lista_tamanho(passos), lista_capacidade(passos));

    // 20 dias de passos no app da academia (em milhares)
    int crescimentos = 0;
    for (int dia = 1; dia <= 20; dia++) {
        int cap_antes = lista_capacidade(passos);
        if (!lista_insere_fim(passos, 5 + dia % 4)) break;
        if (lista_capacidade(passos) != cap_antes) { // houve realloc
            crescimentos++;
            printf("dia %2d: cap %2d -> %2d\n", dia, cap_antes, lista_capacidade(passos));
        }
    }

    int tam = lista_tamanho(passos);
    int cap = lista_capacidade(passos);
    printf("%d itens, cap %d, %d vagas livres\n", tam, cap, cap - tam);
    printf("realloc: %d vezes\n", crescimentos);

    // posição fora da lista: lista_pega recusa e não mexe na variável
    int valor = -1;
    if (!lista_pega(passos, 20, &valor)) {
        printf("posição 20 não existe; valor continua %d\n", valor);
    }

    lista_libera(passos);
    return 0;
}
// Saída:
// criou: tam 0, cap 1
// dia  2: cap  1 ->  2
// dia  3: cap  2 ->  4
// dia  5: cap  4 ->  8
// dia  9: cap  8 -> 16
// dia 17: cap 16 -> 32
// 20 itens, cap 32, 12 vagas livres
// realloc: 5 vezes
// posição 20 não existe; valor continua -1
