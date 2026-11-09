// Lista · Módulo 12 · Pilhas e filas
// Exercício P1217 · ★★☆ · Embaralhar a fila como um baralho
//
// Para o sorteio da quadrilha junina, a fila de pares 1 a 8 deve ser
// "embaralhada" como um baralho: a primeira metade intercalada com a
// segunda, 1 5 2 6 3 7 4 8. Escreva
//
//   void intercala_metades(Fila *f)
//
// usando só insere, retira e tamanho de uma fila circular de int, mais UMA
// fila auxiliar. O tamanho é sempre par.
//
//   Saída esperada:
//   antes:  1 2 3 4 5 6 7 8
//   depois: 1 5 2 6 3 7 4 8
//   antes:  10 20 30 40
//   depois: 10 30 20 40
//
// Dicas:
// 1. Tire a primeira metade (n / 2 itens) da fila e ponha na auxiliar.
//    O que sobra na fila original é a segunda metade.
// 2. Depois, repita n / 2 vezes: tire um da auxiliar e ponha no fim da
//    original; tire um da frente da original (da segunda metade) e ponha no
//    fim dela de novo.
// 3. Para mostrar a fila sem destruí-la, tire e reponha cada item, n vezes.
// 4. Resposta esperada: a saída acima. Cada item é movido O(1) vezes: O(n).
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define CAP 16

typedef struct {
    int v[CAP];
    int inicio, n;
} Fila;

int main(void) {

    return 0;
}
