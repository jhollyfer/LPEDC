// Lista · Módulo 07 · Memória dinâmica
// Exercício P0721 · ★★★ · Um vetor que cresce para qualquer tipo
//
// Escreva um vetor dinâmico genérico, que serve para int, double ou qualquer
// outro tipo. Sem struct (só no módulo 08), o estado fica em três variáveis
// do main (void *v, size_t n, size_t cap), passadas por endereço:
//
//   bool empurrar(void **v, size_t *n, size_t *cap, size_t tam, const void *item);
//
// A função dobra a capacidade quando enche (começando em 1), copia os tam
// bytes de item para o fim com memcpy e devolve false se faltar memória.
// Use-a para guardar os gols por rodada de um time (int) e as médias de
// público (double):
//
//   int gols[7] = {2, 0, 1, 3, 1, 1, 4};
//   double publico[3] = {18450.5, 22010.0, 9875.25};
//
// Mostre cada vetor, n e cap, e libere os dois:
//
//   Saída esperada:
//   Gols (n = 7, cap = 8): 2 0 1 3 1 1 4
//   Público (n = 3, cap = 4): 18450.50 22010.00 9875.25
//
// Dicas:
// 1. O fim do vetor, em bytes: (unsigned char *) *v + *n * tam.
// 2. Para crescer: void *novo = realloc(*v, nova_cap * tam); e, se deu
//    certo, *v = novo; *cap = nova_cap. Começando com v = NULL e cap = 0,
//    o primeiro realloc funciona como malloc.
// 3. memcpy(destino, item, tam) copia os bytes, seja qual for o tipo.
// 4. Para ler de volta, converta: const int *g = v_gols; g[i].
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
    int gols[7] = {2, 0, 1, 3, 1, 1, 4};
    double publico[3] = {18450.5, 22010.0, 9875.25};
    (void) gols, (void) publico; // apague esta linha quando escrever

    return 0;
}
