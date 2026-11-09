// Lista · Módulo 08 · Tipos compostos
// Exercício P0822 · ★★★ · O conjunto de bits dos assentos
//
// Um ônibus de viagem tem 100 lugares (0 a 99), e cada lugar vendido é um
// bit: 100 bits cabem em 13 bytes (unsigned char v[13]). Crie
//
//   typedef struct { unsigned char bits[13]; } Conjunto;
//
// e escreva inserir, remover, contem (bool), tamanho (quantos bits ligados),
// uniao e intersecao (as duas devolvem um Conjunto novo) e mostrar (lista os
// números). Dois aplicativos venderam lugares sem conversar entre si:
//
//   app A: 3 7 12 40 41 42 77 98
//   app B: 7 15 40 63 98 99
//
// Mostre os vendidos de cada app, a união (todos os vendidos), a interseção
// (lugares vendidos DUAS vezes: problema!) e quantos lugares ainda estão
// livres. Depois o app A cancela o lugar 7; mostre a nova interseção:
//
//   Saída esperada:
//   App A (8): 3 7 12 40 41 42 77 98
//   App B (6): 7 15 40 63 98 99
//   Vendidos (11): 3 7 12 15 40 41 42 63 77 98 99
//   Vendidos duas vezes (3): 7 40 98
//   Livres: 89 de 100 (em 13 bytes)
//   Depois do cancelamento, duas vezes (2): 40 98
//
// Dicas:
// 1. O número k mora no byte k / 8, bit k % 8: ligar é bits[k / 8] |= 1u <<
//    (k % 8); testar é (bits[k / 8] >> (k % 8)) & 1.
// 2. União e interseção são feitas BYTE a BYTE: r.bits[i] = a.bits[i] |
//    b.bits[i] (ou &). São 13 operações para 100 números.
// 3. Conjunto vazio: Conjunto c = {0};
// 4. Livres = 100 - tamanho(união).
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    unsigned char bits[13];
} Conjunto;

int main(void) {
    int app_a[8] = {3, 7, 12, 40, 41, 42, 77, 98};
    int app_b[6] = {7, 15, 40, 63, 98, 99};
    (void) app_a, (void) app_b; // apague esta linha quando escrever

    return 0;
}
