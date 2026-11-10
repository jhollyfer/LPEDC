// 0163 · Skip list
// Exercício E976 · ★★☆
//
// A concessionária desativou a parada do km 23. Escreva, sem usar
// skip_remove, void remove_parada(Skip *s, int chave): guarda o nó anterior
// de cada andar, tira o nó de TODOS os andares em que ele aparece e só então
// libera a memória. Escreva também void procura(const Skip *s, int km), que
// mostra se há parada. No main (a linha já está montada), remova o km 23,
// procure os km 47 e 23 e mostre a skip list com skip_mostra. Compile com
// -fsanitize=address: não pode haver acesso a memória liberada.
//
//   Saída esperada:
//   km 47: tem parada
//   km 23: não tem parada
//   andar 2:                          56
//   andar 1:      12          40      56
//   andar 0:   5  12  18  31  40  47  56
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include "skip.h"

int main(void) {
    int km[] = {5, 12, 18, 23, 31, 40, 47, 56};
    int andares[] = {1, 2, 1, 3, 1, 2, 1, 3};
    Skip *linha = skip_cria(0);
    for (int i = 0; i < 8; i++) {
        skip_insere_andares(linha, km[i], andares[i]);
    }

    skip_libera(linha);
    return 0;
}
