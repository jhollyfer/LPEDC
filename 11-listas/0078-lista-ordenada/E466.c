// 0078 · Lista ordenada
// Exercício E466 · ★★☆
//
// Duas linhas de ônibus saem do mesmo terminal. Os horários de cada uma
// (em minutos depois das 6h) estão em listas crescentes:
//
//   linha 101: 0 -> 25 -> 50 -> 75
//   linha 202: 10 -> 25 -> 40 -> 90
//
// Escreva No *intercala(No *a, No *b), que junta as duas numa lista só,
// também crescente, SEM criar nenhum nó novo: só religando os que existem.
//
//   Saída esperada:
//   0 -> 10 -> 25 -> 25 -> 40 -> 50 -> 75 -> 90 -> NULL
//
// Dicas:
// 1. Comece por um nó-cabeça local (No cabeca;) e um ponteiro "fim" que
//    aponta para ele. Assim o primeiro nó não é caso especial.
// 2. Enquanto as duas tiverem nós: o menor dos dois inícios vai para
//    fim->prox, e a lista de onde ele saiu anda.
// 3. Quando uma acabar, pendure a outra inteira no fim: fim->prox = a ou b.
// 4. Resposta esperada: a saída acima. Depois de intercalar, libere só a
//    lista resultado: os nós de a e b agora são dela.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "lista.h"

int main(void) {
    No *a = NULL;
    No *b = NULL;
    int la[] = {50, 0, 75, 25};
    int lb[] = {90, 10, 40, 25};
    for (int i = 0; i < 4; i++) {
        a = lista_insere_ordenado(a, la[i]);
        b = lista_insere_ordenado(b, lb[i]);
    }

    // chame intercala e imprima o resultado

    lista_libera(a); // troque estas duas linhas por
    lista_libera(b); // lista_libera(resultado)
    return 0;
}
