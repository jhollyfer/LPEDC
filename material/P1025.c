// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1025 · ★★★ · Os lugares do cinema num punhado de bits
//
// A sala do cinema tem 256 lugares (0 a 255). Guardar um bool por lugar
// gasta 256 bytes; guardando um BIT por lugar, bastam 32. Escreva o TAD
// Lugares, num arquivo só ("lugares.h", "lugares.c" e cliente), com um
// unsigned char bits[32] escondido na struct:
//
//   Lugares *lugares_cria(void);                 // todos livres
//   void lugares_ocupa(Lugares *l, int k);
//   void lugares_libera_lugar(Lugares *l, int k);
//   bool lugares_ocupado(const Lugares *l, int k);
//   int lugares_conta(const Lugares *l);          // quantos ocupados
//   Lugares *lugares_uniao(const Lugares *a, const Lugares *b);
//   Lugares *lugares_intersecao(const Lugares *a, const Lugares *b);
//   int lugares_bytes(void);                      // memória do vetor de bits
//   void lugares_libera(Lugares *l);
//
// Sessão da tarde: 0, 1, 2, 50, 99, 150 e 199. Sessão da noite: 2, 3, 50,
// 100 e 199. Mostre quantos foram ocupados em cada sessão, os ocupados nas
// duas, quantos foram ocupados em alguma e o tamanho do vetor de bits.
//
//   Saída esperada:
//   Tarde: 7 ocupados
//   Noite: 5 ocupados
//   Ocupados nas duas: 2 50 199
//   Ocupados em alguma: 9
//   Memória: 32 bytes para 256 lugares
//
// Dicas:
// 1. O lugar k fica no byte k / 8, no bit k % 8. Ocupar:
//    bits[k / 8] |= 1u << (k % 8). Liberar: &= ~(1u << (k % 8)).
//    Testar: (bits[k / 8] >> (k % 8)) & 1.
// 2. União e interseção são um laço de 32 voltas com | e &: 8 lugares por
//    operação. Mesma classe O(n) de um vetor bool, mas 8 vezes menos
//    trabalho e memória.
// 3. Para contar, some os bits de cada byte (com um laço de 8 ou com
//    b &= b - 1, que apaga o bit 1 mais baixo).
// 4. lugares_bytes devolve sizeof(struct lugares), e só pode ser escrita
//    DENTRO do lugares.c: o cliente não enxerga a struct, então não
//    consegue fazer esse sizeof.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
